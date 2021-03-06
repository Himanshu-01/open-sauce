/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/

ENGINE_PTR(const void*, gather_exception_data,	0x6BDEAC, 0x626524);
FUNC_PTR(GATHER_EXCEPTION,					0x582780, 0x52AEB0);

FUNC_PTR(SET_TEXTURE_SAMPLER_STAGE,				0x51C370, FUNC_PTR_NULL);
FUNC_PTR(TEXTURE_CACHE_BITMAP_GET_HARDWARE_FORMAT,			0x445080, FUNC_PTR_NULL);
FUNC_PTR(SOUND_CACHE_SOUND_REQUEST,				0x444940, FUNC_PTR_NULL);
FUNC_PTR(RESOLUTION_LIST_ADD_RESOLUTION,		0x4BE350, FUNC_PTR_NULL);

FUNC_PTR(ANIMATION_PICK_RANDOM_PERMUTATION,	0x4D97C0, 0x4C1CF0);

FUNC_PTR(GENERATE_MD5,						0x5BFB70, 0x52F7E0);

FUNC_PTR(GET_CMD_LINE_PARAMETER,			0x5460E0, 0x4FF900);

FUNC_PTR(CACHE_FILE_READ_REQUEST,			0x443580+0x10, 0x4440A0+0x10);

//////////////////////////////////////////////////////////////////////////
// AI
FUNC_PTR(ACTOR_DELETE,						0x427E60, 0x427E70);
FUNC_PTR(AI_SCRIPTING_ATTACH_FREE,			0x435420, 0x435430);

//////////////////////////////////////////////////////////////////////////
// Cache
FUNC_PTR(MAP_LIST_ADD_MAP,						0x498060, 0x48DA50);
ENGINE_PTR(cstring, MAP_LIST_MAP_EXTENSION_REF,	0x49813D, 0x48DB2D);
ENGINE_PTR(const char, MAP_LIST_MAP_EXTENSION,	0x609494, 0x563C30); // ".map"

FUNC_PTR(MAP_ENTRY_INDEX_FROM_NAME,				0x497F90, 0x48D980);

//////////////////////////////////////////////////////////////////////////
// Console
FUNC_PTR(CONSOLE_PROCESS_COMMAND,	0x4C9F40, 0x4B3990); // also in Console.cpp
FUNC_PTR(CONSOLE_TERMINAL_PRINTF,	0x4C9D40, 0x48ED70);
FUNC_PTR(CONSOLE_PRINTF,			0x4C9DE0, 0x4B3790);
FUNC_PTR(CONSOLE_WARNING,			0x4C9EA0, 0x4B38F0);

//////////////////////////////////////////////////////////////////////////
// Cheats
FUNC_PTR(CHEAT_ALL_WEAPONS,						0x45B0B0, 0x457B10);
FUNC_PTR(CHEAT_SPAWN_WARTHOG,					0x45B140, 0x457BA0);
FUNC_PTR(CHEAT_TELEPORT_TO_CAMERA,				0x45B1B0, 0x457C10);
FUNC_PTR(CHEAT_ACTIVE_CAMOFLAGE,				0x45B240, 0x457CA0);
FUNC_PTR(CHEAT_ACTIVE_CAMOFLAGE_LOCAL_PLAYER,	0x45B2A0, 0x457D00);
FUNC_PTR(CHEAT_PLAYER_INDEX,					0x45B320, 0x457D80);
FUNC_PTR(DIRECTOR_SAVE_CAMERA,					0x4463B0, FUNC_PTR_NULL);
FUNC_PTR(DIRECTOR_LOAD_CAMERA,					0x446470, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Effects
FUNC_PTR(EFFECT_NEW_ON_OBJECT_MARKER,		0x48B640, 0x482F20);

//////////////////////////////////////////////////////////////////////////
// Game
FUNC_PTR(SCENARIO_SWITCH_STRUCTURE_BSP,		0x542610, 0x4FD320);
FUNC_PTR(BINK_PLAYBACK_START,				0x43ED20, FUNC_PTR_NULL);
FUNC_PTR(GAME_ENGINE_RASTERIZE_MESSAGE,		0x462C90, FUNC_PTR_NULL);
FUNC_PTR(GAME_TEAM_IS_ENEMY,				0x45C8D0, 0x459280);
FUNC_PTR(GAME_ENGINE_PLAY_MULTIPLAYER_SOUND,0x46EC70, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// HS
FUNC_PTR(OBJECT_LIST_ADD,					0x48E000, 0x4858E0);

//////////////////////////////////////////////////////////////////////////
// Input
FUNC_PTR(INPUT_KEY_IS_DOWN, 0x493AD0, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Interface
FUNC_PTR(KEYSTONE_CHAT_LOG_ADD_STRING,	0x4AEAD0, FUNC_PTR_NULL); // I forget if the dedicated has a chat log equivalent...
FUNC_PTR(HUD_PRINT_MESSAGE,				0x4B1790, 0x4A0240);
FUNC_PTR(HUD_GET_ITEM_MESSAGE,			0x4AD630, 0x49F340);
FUNC_PTR(MAINMENU_LOAD,					0x4CBF00, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Math
FUNC_PTR(PERIODIC_FUNCTION_EVALUATE,	0x4CFEF0, 0x4B8F60);
FUNC_PTR(TRANSITION_FUNCTION_EVALUATE,	0x4D0000, 0x4B9070);

//////////////////////////////////////////////////////////////////////////
// Memory
FUNC_PTR(DATA_NEW,			0x4D3880+0x30, 0x4BC7F0+0x30);
FUNC_PTR(DATUM_NEW_AT_INDEX,0x4D3910, 0x4BC880);
FUNC_PTR(DATUM_NEW,			0x4D39C0, 0x4BC930);
FUNC_PTR(DATUM_DELETE,		0x4D3A50, 0x4BC9C0);
FUNC_PTR(DATA_MAKE_VALID,	0x4D3A90+0x30, 0x4BCA00+0x30);
FUNC_PTR(DATA_ITERATOR_NEXT,0x4D3B10, 0x4BCA80);
FUNC_PTR(DATUM_NEXT_INDEX,	0x4D3B70, 0x4BCAE0);
FUNC_PTR(DATUM_GET,			0x4D3BC0, 0x4BCB30);
FUNC_PTR(DATUM_INITIALIZE,	0x4D3C00, 0x4BCB70);

//////////////////////////////////////////////////////////////////////////
// Networking
FUNC_PTR(MDP_ENCODE_OBJECT_DELETION_MESSAGE,			0x4F9730, 0x4E0720);
FUNC_PTR(ENCODE_HUD_CHAT_NETWORK_DATA,					0x4ADF70, 0x49F740);
FUNC_PTR(INDEX_RESOLUTION_TABLE_TRANSLATE,				0x4F4270, 0x4DD4D0);
FUNC_PTR(CONNECT_TO_MP_SERVER,							0x4CB980, PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Objects
FUNC_PTR(OBJECT_HEADER_BLOCK_ALLOCATE,	0x4FBAE0, 0x4E2A30);
FUNC_PTR(OBJECT_ITERATOR_NEXT,			0x4FAB80+0x30, 0x4E1AD0+0x30);

FUNC_PTR(OBJECT_PLACEMENT_DATA_NEW,		0x4F9030, 0x4E0020);
FUNC_PTR(OBJECT_NEW,					0x4F90F0, 0x4E00E0);
FUNC_PTR(OBJECT_NEW_WITH_ROLE,			0x4F9140, 0x4E0130);
FUNC_PTR(OBJECT_DELETE,					0x4F9860, 0x4E0850);
FUNC_PTR(OBJECT_ATTACH_TO_MARKER,		0x4F9E10, 0x4E0D60);
FUNC_PTR(OBJECT_DETACH,					0x4FA2A0, 0x4E11F0);
FUNC_PTR(OBJECTS_FIND_IN_SPHERE,		0x4FAC70, 0x4E1BC0);
FUNC_PTR(OBJECT_START_INTERPOLATION,	0x4FA800, 0x4E1750);
FUNC_PTR(OBJECT_RESET,					0x4F8DF0, 0x4DFDE0);
FUNC_PTR(OBJECT_RECONNECT_TO_MAP,		0x4F98C0, 0x4E08B0);
FUNC_PTR(OBJECT_DISCONNECT_FROM_MAP,	0x4F9A70, 0x4E0A60);
FUNC_PTR(OBJECT_GET_ORIGIN,				0x4FA590, 0x4E14E0);
FUNC_PTR(OBJECT_GET_ORIENTATION,		0x4FA600, 0x4E1550);
FUNC_PTR(OBJECT_GET_LOCATION,			0x4FA7A0, 0x4E16F0);
FUNC_PTR(OBJECT_SET_POSITION,			0x4F8E50, 0x4DFE40);
FUNC_PTR(OBJECT_SET_POSITION_NETWORK,	0x4F8F50, 0x4DFF40);
FUNC_PTR(OBJECT_RESTORE_BODY,			0x4F1660, 0x4DA8C0);
FUNC_PTR(OBJECT_DEPLETE_BODY,			0x4F16B0, 0x4DA910);
FUNC_PTR(OBJECT_DEPLETE_SHIELD,			0x4F17A0, 0x4DAA00);
FUNC_PTR(OBJECT_DOUBLE_CHARGE_SHIELD,	0x4F1830, 0x4DAA90);
FUNC_PTR(OBJECT_DEFINITION_PREDICT,		0x4FB760, 0x4E26B0);
FUNC_PTR(OBJECT_SET_SCALE,				0x4FD330, 0x4E4280);
FUNC_PTR(UNIT_ORIENT_TO_FLAG,			0x48ACA0, 0x482580);
FUNC_PTR(UNIT_GET_CAMERA_POSITION,		0x56CA80, FUNC_PTR_NULL);
FUNC_PTR(UNIT_SET_ANIMATION,			0x572910, 0x521010);
FUNC_PTR(UNIT_GET_CUSTOM_ANIMATION_TIME,0x573EF0, 0x522600);

//////////////////////////////////////////////////////////////////////////
// Physics
FUNC_PTR(COLLISION_TEST_VECTOR,			0x5094F0+0x30, 0x4EF5D0+0x30);

//////////////////////////////////////////////////////////////////////////
// Players
FUNC_PTR(PLAYER_INDEX_FROM_UNIT_INDEX,		0x477BF0, 0x46F670);
FUNC_PTR(PLAYER_TELEPORT,					0x478A90, 0x470510);
FUNC_PTR(PLAYER_OVER_SHIELD_SCREEN_EFFECT,	0x47C4B0, FUNC_PTR_NULL);
FUNC_PTR(PLAYER_CAMO_SCREEN_EFFECT,			0x47C570, FUNC_PTR_NULL);
FUNC_PTR(PLAYER_HEALTH_PACK_SCREEN_EFFECT,	0x47C630, FUNC_PTR_NULL);
FUNC_PTR(FIND_CLOSEST_PLAYER_INDEX,			0x45EEE0, FUNC_PTR_NULL);

//////////////////////////////////////////////////////////////////////////
// Scenario
FUNC_PTR(SCENARIO_TRIGGER_VOLUME_TEST_POINT,0x542780, 0x4FD490);

//////////////////////////////////////////////////////////////////////////
// TagGroups
FUNC_PTR(PHYSICAL_MEMORY_MAP_PREDICT_RESOURCES,	0x445520, FUNC_PTR_NULL);
FUNC_PTR(TAG_LOADED,							0x4429A0, 0x443530);
FUNC_PTR(UNICODE_STRING_LIST_GET_STRING,		0x55B390, 0x509DE0);