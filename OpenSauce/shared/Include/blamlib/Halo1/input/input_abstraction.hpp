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
			_button_none = NONE,

			_button_jump,
			_button_switch_grenade,
			_button_action,
			_button_switch_weapon,
			_button_melee,
			_button_flashlight,
			_button_throw_grenade,
			_button_fire,
			_button_accept,
			_button_back,
			_button_crouch,
			_button_zoom,
			_button_show_scores,
			_button_reload,
			_button_pickup,
			_button_say,
			_button_say_to_team,
			_button_say_to_vehicle,
			_button_screenshot,

			k_number_of_action_control_buttons, // NUMBER_OF_ACTION_CONTROL_BUTTONS

			_control_button_move_forward = k_number_of_action_control_buttons,
			_control_button_move_backward,
			_control_button_move_left,
			_control_button_move_right,
			_control_button_look_up,
			_control_button_look_down,
			_control_button_look_left,
			_control_button_look_right,

			_new_control_button_show_rules,
			_new_control_button_show_homies,

			k_number_of_total_control_buttons, // NUMBER_OF_TOTAL_CONTROL_BUTTONS
			k_first_new_control_button =		// FIRST_NEW_CONTROL_BUTTON
				_new_control_button_show_rules, 
		};
	};
};