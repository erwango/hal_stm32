/*
 * Copyright (c) 2020 Linaro Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef PINCTRL_ST_STM32_H_
#define PINCTRL_ST_STM32_H_

#if 0

/* Create a pincfg device tree node:
 *
 * The node name and nodelabel will be of the form:
 *
 * NODE = <periph>_<signal>_p<port>_<pin>
 *
 * LABEL: NODE {
 *     pinmux = <STM32_PINMUX_Z(STM32_DT_PORT_<port>,pin, function)>;
 *     prop-foo;
 *     prop-bar;
 * }
 *
 * Also, each macro will fill directly a knwon working pin configuration
 * depending on the signal that is required.
 *
 * So for example:
 *
 * DT_STM32_UART_TX(b, 6, usart1, AF7);
 *
 * Will become:
 *
 * usart1_tx_pb6: usart1_tx_pb6 {
 *     pinmux = <((((0x10 + 6)) << 8) | (0x7))>;
 *     drive-push-pull;
 *     bias-pull-up;
 * };
 *
 */

#define DT_STM32_UART_TX(port, pin, periph, function) \
periph##_tx_p##port####pin##: \
periph##_tx_p##port####pin## { \
	pinmux = < STM32_PINMUX_Z(STM32_DT_PORT_##port, pin, function) > ; \
	drive-push-pull; \
	bias-pull-up; \
}

#define DT_STM32_UART_RX(port, pin, periph, function) \
periph##_rx_p##port####pin##: \
periph##_rx_p##port####pin## { \
	pinmux = < STM32_PINMUX_Z(STM32_DT_PORT_##port, pin, function) > ; \
	bias-disable; \
}

#define DT_STM32_UART_CTS(port, pin, periph, function) \
periph##_rx_p##port####pin##: \
periph##_rx_p##port####pin## { \
	pinmux = < STM32_PINMUX_Z(STM32_DT_PORT_##port, pin, function) > ; \
	bias-pull-up; \
	drive-open-drain; \
}

#define DT_STM32_UART_RTS(port, pin, periph, function) \
periph##_rx_p##port####pin##: \
periph##_rx_p##port####pin## { \
	pinmux = < STM32_PINMUX_Z(STM32_DT_PORT_##port, pin, function) > ; \
	bias-pull-up; \
	drive-open-drain; \
}

#endif

#endif /* PINCTRL_ST_STM32_H_ */
