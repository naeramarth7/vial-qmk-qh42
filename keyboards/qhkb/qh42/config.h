/*
Copyright 2021 beanaccle

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// qmk flash -kb qh/qh42 -km vial-qh42 -bl uf2-split-left
// qmk flash -kb qh/qh42 -km vial-qh42 -bl uf2-split-right

#define EE_HANDS

#define USART1_REMAP               // Remap USART TX and RX pins on STM32F103 MCUs

#define COMBO_ONLY_FROM_LAYER 0
#define LAYER_STATE_16BIT

// WS2812 PWM-specific settings (ChibiOS)
#define WS2812_PWM_COMPLEMENTARY_OUTPUT
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 1
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA1_STREAM5
#define WS2812_DMA_CHANNEL 1

#ifdef RGB_MATRIX_ENABLE
#   define DRIVER_LED_TOTAL RGB_MATRIX_LED_COUNT
#   define RGBLED_NUM 54
#   define RGBLED_SPLIT { 27, 27 }
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#   define RGB_MATRIX_KEYPRESSES
#   define RGB_MATRIX_KEYRELEASES
#endif
