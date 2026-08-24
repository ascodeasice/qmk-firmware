/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Trackball angle adjustment. */
#define ROTATIONAL_TRANSFORM_ANGLE -25
#define COMBO_COUNT 31
// enables the combo_should_trigger() hook used to gate combos per layer
#define COMBO_SHOULD_TRIGGER
#define TAPPING_TERM 200

/* SECTION mouse key*/
#define MOUSEKEY_INTERVAL 16

#define MOUSEKEY_DELAY 0

#define MOUSEKEY_TIME_TO_MAX 25

#define MOUSEKEY_MAX_SPEED 5

#define MOUSEKEY_WHEEL_DELAY 0

// use right hand right top key for bootmagic
// reference to info.json for row and column
// https://github.com/qmk/qmk_firmware/blob/master/docs/reference_info_json.md
#define BOOTMAGIC_ROW_RIGHT 4
#define BOOTMAGIC_COLUMN_RIGHT 0

// SECTION: emoji
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
