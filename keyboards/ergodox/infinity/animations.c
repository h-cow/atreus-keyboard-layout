/* Copyright 2017 Fred Sundvik
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

#include "animations.h"
#include "visualizer.h"
#ifdef LCD_ENABLE
#include "lcd_keyframes.h"
#endif
#ifdef LCD_BACKLIGHT_ENABLE
#include "lcd_backlight_keyframes.h"
#endif

#if defined(VISUALIZER_ENABLE) && defined(LCD_ENABLE) && defined(LCD_BACKLIGHT_ENABLE)

// Don't worry, if the startup animation is long, you can use the keyboard like normal
// during that time
keyframe_animation_t default_startup_animation = {
    .num_frames = 4,
    .loop = false,
    .frame_lengths = {0, 0, 0, gfxMillisecondsToTicks(5000), 0},
    .frame_functions = {
            lcd_keyframe_enable,
            backlight_keyframe_enable,
            lcd_keyframe_draw_logo,
            backlight_keyframe_animate_color,
    },
};

keyframe_animation_t default_suspend_animation = {
    .num_frames = 4,
    .loop = false,
    .frame_lengths = {0, gfxMillisecondsToTicks(1000), 0, 0},
    .frame_functions = {
            lcd_keyframe_display_layer_text,
            backlight_keyframe_animate_color,
            lcd_keyframe_disable,
            backlight_keyframe_disable,
    },
};

#endif
