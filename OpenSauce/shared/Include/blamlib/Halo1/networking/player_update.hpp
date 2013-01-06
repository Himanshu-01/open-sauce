/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

namespace Yelo
{
	namespace Enums
	{
		enum {
			k_maximum_action_updates_in_super_update = 16,

			k_number_of_remote_player_action_update_baseline_ids = 2,
		};
	};

	namespace Networking
	{
		struct s_player_set_action_result_network_data
		{
			datum_index player_index;
			int32 action_result_type;
			datum_index action_object_index;
			int16 action_result;
			int16 action_seat_index;
			datum_index weapon_to_drop_as_result_of_swap;
		}; BOOST_STATIC_ASSERT( sizeof(s_player_set_action_result_network_data) == 0x14 );


		struct s_player_action_update_data
		{
			long_flags control_flags;
			PAD64;
			struct {
				real r0, r1;
			}throttle;
			real primary_trigger;
			int16 desired_weapon_index;
			int16 desired_grenade_index;
		}; BOOST_STATIC_ASSERT( sizeof(s_player_action_update_data) == 0x1C );

		struct s_remote_player_action_update_header
		{
			datum_index player_index;
			sbyte update_id;
			sbyte baseline_id; // k_number_of_remote_player_action_update_baseline_ids
		}; BOOST_STATIC_ASSERT( sizeof(s_remote_player_action_update_header) == 0x6 );

		struct s_remote_player_action_update_network_data
		{
			int32 ticks_to_apply_update_to;
			s_player_action_update_data action;
			PAD32;
			real_vector3d facing_vector;
		}; BOOST_STATIC_ASSERT( sizeof(s_remote_player_action_update_network_data) == 0x30 );

		struct s_remote_player_position_update_network_data
		{
			real_point3d position;
		}; BOOST_STATIC_ASSERT( sizeof(s_remote_player_position_update_network_data) == 0xC );

		struct s_remote_player_vehicle_update_network_data
		{
			datum_index vehicle_index;
			real_point3d position;
			real_vector3d translational_velocity, angular_velocity;
			real_vector3d forward, up;
		}; BOOST_STATIC_ASSERT( sizeof(s_remote_player_vehicle_update_network_data) == 0x40 );
	};
};