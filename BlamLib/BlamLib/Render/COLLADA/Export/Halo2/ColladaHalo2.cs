﻿/*
    BlamLib: .NET SDK for the Blam Engine

    Copyright (C) 2005-2010  Kornner Studios (http://kornner.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
using System;
using System.Collections.Generic;
using System.IO;
using BlamLib.Blam;
using BlamLib.Managers;

namespace BlamLib.Render.COLLADA.Halo2
{
	public class ColladaHalo2LightmapInfo : ColladaHaloModelInfoBase
	{
		public ColladaHalo2LightmapInfo(int internal_index, string name,
			int vertex_count, int face_count)
			: base(internal_index, name, vertex_count, face_count)
		{
		}
	};
	/// <summary>
	/// Provides readonly information about an object in a model tag for external use
	/// </summary>
	public class ColladaHalo2RenderModelInfo : ColladaHaloModelInfoBase
	{
		public int Permutation { get; private set; }
		public int LevelOfDetail { get; private set; }

		public ColladaHalo2RenderModelInfo(int internal_index, string name,
			int vertex_count, int face_count, int permutation, int level_of_detail)
			: base(internal_index, name, vertex_count, face_count)
		{
			Permutation = permutation;
			LevelOfDetail = level_of_detail;
		}
	};

	class ColladaHalo2 : ColladaInterface
	{
		#region Internal Classes
		/// <summary>
		/// Interface class to pass mesh include information to the Halo2 structure lightmap exporter
		/// </summary>
		protected class LightmapInfoInternal : ColladaInfoInternal, IHalo2LightmapInterface, IHaloShaderDatumList
		{
			List<DatumIndex> shaderDatums = new List<DatumIndex>();

			public void AddShader(DatumIndex shader_datum)
			{
				if (!shaderDatums.Contains(shader_datum))
					shaderDatums.Add(shader_datum);
			}

			#region IHalo2ShaderDatumList Members
			public int GetShaderCount()
			{
				return shaderDatums.Count;
			}

			public DatumIndex GetShaderDatum(int index)
			{
				return shaderDatums[index];
			}
			#endregion
		}
		/// <summary>
		/// Interface class to pass mesh include information to the Halo2 render model exporter
		/// </summary>
		protected class RenderModelInfoInternal : ColladaInfoInternal, IHalo2RenderModelInterface, IHaloShaderDatumList
		{
			struct GeometryInfo
			{
				public string Name;
				public int Index;
			};

			public bool IsMultiplePermutations = false;
			public int Permutation = 0;

			List<GeometryInfo> geometries = new List<GeometryInfo>();
			List<DatumIndex> shaderDatums = new List<DatumIndex>();

			public void AddShaderDatum(DatumIndex shader_datum)
			{
				if (!shaderDatums.Contains(shader_datum))
					shaderDatums.Add(shader_datum);
			}
			/// <summary>
			/// Determines if a geometry with a matching index already exists in the list
			/// </summary>
			/// <param name="index">The geometry index to search for</param>
			/// <returns>True if a matching element is found</returns>
			bool GeometryExists(int index)
			{
				foreach (var geometry in geometries)
					if (geometry.Index == index)
						return true;
				return false;
			}
			/// <summary>
			/// Adds a geometry name and index pair to the list, if an element with a matching index does not already exist
			/// </summary>
			/// <param name="name">The geometry name</param>
			/// <param name="index">The geometry index</param>
			public void AddGeometry(string name, int index)
			{
				if (GeometryExists(index))
					return;

				GeometryInfo geometry = new GeometryInfo();
				geometry.Name = name;
				geometry.Index = index;

				geometries.Add(geometry);
			}

			#region IHalo2RenderModelInterface Members
			public int GetShaderCount()
			{
				return shaderDatums.Count;
			}
			public DatumIndex GetShaderDatum(int index)
			{
				return shaderDatums[index];
			}
			public int GetGeometryCount()
			{
				return geometries.Count;
			}
			public string GetGeometryName(int index)
			{
				return geometries[index].Name;
			}
			public int GetGeometryIndex(int index)
			{
				return geometries[index].Index;
			}
			public bool GetIsMultiplePerms()
			{
				return IsMultiplePermutations;
			}
			public int GetPermutation()
			{
				return Permutation;
			}
			#endregion
		}
		#endregion

		#region Static Helper Classes
		protected static class Lightmap
		{
			public static void AddShaderDatums(LightmapInfoInternal lightmap_info, TagManager manager)
			{
				var definition = manager.TagDefinition as Blam.Halo2.Tags.scenario_structure_lightmap_group;

				foreach (var lightmap in definition.LightmapGroups)
				{
					foreach (var cluster in lightmap)
					{

					}
				}
			}

			public static int GetVertexCount(TagManager manager)
			{
				var definition = manager.TagDefinition as Blam.Halo2.Tags.scenario_structure_lightmap_group;

				int count = 0;
				foreach (var group in definition.LightmapGroups)
				{
					foreach (var cluster in group.Clusters)
						count += cluster.GeometryInfo.Value.TotalVertexCount.Value;
				}
				return count;
			}
			public static int GetTriangleCount(TagManager manager)
			{
				var definition = manager.TagDefinition as Blam.Halo2.Tags.scenario_structure_lightmap_group;

				int count = 0;
				foreach (var group in definition.LightmapGroups)
				{
					foreach (var cluster in group.Clusters)
						count += cluster.GeometryInfo.Value.TotalTriangleCount.Value;
				}
				return count;
			}
		}
		protected static class RenderModel
		{
			public static void AddGeometryInfos(RenderModelInfoInternal model_info, TagManager manager, int permutation, int lod)
			{
				var definition = manager.TagDefinition as Blam.Halo2.Tags.render_model_group;

				for (int i = 0; i < definition.Regions.Count; i++ )
				{
					int permutation_index = permutation;

					if (permutation >= definition.Regions[i].Permutations.Count)
						permutation_index = 0;

					string name = string.Format("{0}-{1}-lod{2}",
						definition.Regions[i].Name.ToString(), definition.Regions[i].Permutations[permutation_index].Name.ToString(), lod);

					int index = 0;
					switch (lod)
					{
						case 0: index = definition.Regions[i].Permutations[permutation_index].L6; break;
						case 1: index = definition.Regions[i].Permutations[permutation_index].L5; break;
						case 2: index = definition.Regions[i].Permutations[permutation_index].L4; break;
						case 3: index = definition.Regions[i].Permutations[permutation_index].L3; break;
						case 4: index = definition.Regions[i].Permutations[permutation_index].L2; break;
						case 5: index = definition.Regions[i].Permutations[permutation_index].L1; break;
					};

					model_info.AddGeometry(name, index);
				}
			}
			public static void AddShaderDatums(RenderModelInfoInternal model_info, TagManager manager)
			{
				var definition = manager.TagDefinition as Blam.Halo2.Tags.render_model_group;

				for(int i = 0; i <  model_info.GetGeometryCount(); i++)
				{
					foreach (var part in definition.Sections[model_info.GetGeometryIndex(i)].SectionData[0].Section.Value.Parts)
						model_info.AddShaderDatum(definition.Materials[part.Material].Shader.Datum);
				}
			}

			public static int GetPermutationCount(TagManager manager)
			{
				var definition = manager.TagDefinition as Blam.Halo2.Tags.render_model_group;

				int permutation_count = 0;
				foreach (var region in definition.Regions)
					permutation_count = (region.Permutations.Count > permutation_count ? region.Permutations.Count : permutation_count);
				return permutation_count;
			}			
			public static int GetVertexCount(RenderModelInfoInternal model_info, TagManager manager)
			{
				var definition = manager.TagDefinition as Blam.Halo2.Tags.render_model_group;

				int count = 0;
				for (int i = 0; i < model_info.GetGeometryCount(); i++)
					count += definition.Sections[model_info.GetGeometryIndex(i)].SectionInfo.Value.TotalVertexCount;
				return count;
			}
			public static int GetTriangleCount(RenderModelInfoInternal model_info, TagManager manager)
			{
				var definition = manager.TagDefinition as Blam.Halo2.Tags.render_model_group;

				int count = 0;
				for (int i = 0; i < model_info.GetGeometryCount(); i++)
					count += definition.Sections[model_info.GetGeometryIndex(i)].SectionInfo.Value.TotalTriangleCount;
				return count;
			}
		}
		#endregion

		#region Class Members
		TagIndexBase tagIndex;
		TagManager tagManager;
		#endregion

		#region Constructor
		/// <summary>
		/// Halo2 export interface class constructor
		/// </summary>
		/// <param name="tag_index">Tag index containing the tag being exported</param>
		/// <param name="tag_datum">DatumIndex of the tag being exported</param>
		public ColladaHalo2(TagIndexBase tag_index, DatumIndex tag_datum)
		{
			tagIndex = tag_index;
			tagManager = tagIndex[tag_datum];

			GenerateInfoList();
		}
		#endregion

		#region Info List Generation
		/// <summary>
		/// Generic branch point for adding info classes
		/// </summary>
		protected override void GenerateInfoList()
		{
			if (tagManager.GroupTag.Equals(Blam.Halo2.TagGroups.ltmp))
				GenerateInfoListLightmap();
			else if (tagManager.GroupTag.Equals(Blam.Halo2.TagGroups.mode))
				GenerateInfoListRenderModel();
		}
		/// <summary>
		/// Creates info classes for a structure lightmap
		/// </summary>
		void GenerateInfoListLightmap()
		{
			string name = Path.GetFileNameWithoutExtension(tagManager.Name);

			int vertex_count, triangle_count;

			vertex_count = Lightmap.GetVertexCount(tagManager);
			triangle_count = Lightmap.GetTriangleCount(tagManager);

			if ((vertex_count > 0) && (triangle_count > 0))
			{
				LightmapInfoInternal lightmap_info_internal = new LightmapInfoInternal();
				internalInfoList.Add(lightmap_info_internal);

				Add(new ColladaHalo2LightmapInfo(internalInfoList.Count - 1,
					name,
					vertex_count,
					triangle_count));
			}
		}
		/// <summary>
		/// Creates info classes for a render model
		/// </summary>
		void GenerateInfoListRenderModel()
		{
			string name = Path.GetFileNameWithoutExtension(tagManager.Name);

			int permutation_count = RenderModel.GetPermutationCount(tagManager);

			for (int i = 0; i < permutation_count; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					RenderModelInfoInternal model_info_internal = new RenderModelInfoInternal();
					model_info_internal.Permutation = i;
					model_info_internal.IsMultiplePermutations = false;

					RenderModel.AddGeometryInfos(model_info_internal, tagManager, i, j);
					RenderModel.AddShaderDatums(model_info_internal, tagManager);

					internalInfoList.Add(model_info_internal);

					ColladaHalo2RenderModelInfo model_info = new ColladaHalo2RenderModelInfo(
						internalInfoList.Count - 1,
						Path.GetFileNameWithoutExtension(tagManager.Name),
						RenderModel.GetVertexCount(model_info_internal, tagManager),
						RenderModel.GetTriangleCount(model_info_internal, tagManager),
						i,
						j);

					Add(model_info);
				}
			}
		}
		#endregion

		public override void Export(string file_name)
		{
			if (registeredInfos.Count == 0)
			{
				AddReport("COLLADAINTERFACE : invalid info count on export");
				return;
			}

			if (tagManager.GroupTag.Equals(Blam.Halo2.TagGroups.ltmp))
			{
				LightmapInfoInternal info = new LightmapInfoInternal();

				var exporter = new Halo2.ColladaLightmapExporter(info, tagIndex, tagManager);

				exporter.ErrorOccured += new EventHandler<ColladaExporter.ColladaErrorEventArgs>(ExporterErrorOccured);

				exporter.Overwrite = Overwrite;
				exporter.RelativeDataPath = RelativeFilePath;
				exporter.BitmapFormat = BitmapFormat;

				exporter.BuildColladaInstance();
				exporter.SaveDAE(RelativeFilePath + file_name + ".dae");

				exporter.ErrorOccured -= new EventHandler<ColladaExporter.ColladaErrorEventArgs>(ExporterErrorOccured);
			}
			else if (tagManager.GroupTag.Equals(Blam.Halo2.TagGroups.mode))
			{
				RenderModelInfoInternal model_info = new RenderModelInfoInternal();

				List<int> added_permutations = new List<int>();

				foreach (int index in registeredInfos)
				{
					RenderModelInfoInternal info = internalInfoList[index] as RenderModelInfoInternal;

					if (!added_permutations.Contains(info.Permutation))
						added_permutations.Add(info.Permutation);

					for (int i = 0; i < info.GetShaderCount(); i++)
					    model_info.AddShaderDatum(info.GetShaderDatum(i));
					for (int i = 0; i < info.GetGeometryCount(); i++)
						model_info.AddGeometry(info.GetGeometryName(i), info.GetGeometryIndex(i));
				}

				if(added_permutations.Count == 1)
					model_info.Permutation = added_permutations[0];
				else
					model_info.IsMultiplePermutations = true;

				var exporter = new Halo2.ColladaRenderModelExporter(model_info, tagIndex, tagManager);
				
				exporter.ErrorOccured += new EventHandler<ColladaExporter.ColladaErrorEventArgs>(ExporterErrorOccured);

				exporter.Overwrite = Overwrite;
				exporter.RelativeDataPath = RelativeFilePath;
				exporter.BitmapFormat = BitmapFormat;

				exporter.BuildColladaInstance();
				exporter.SaveDAE(RelativeFilePath + file_name + ".dae");

				exporter.ErrorOccured -= new EventHandler<ColladaExporter.ColladaErrorEventArgs>(ExporterErrorOccured);
			}
		}

		void ExporterErrorOccured(object sender, ColladaExporter.ColladaErrorEventArgs e)
		{
			AddReport(e.ErrorMessage);
		}
	};
}