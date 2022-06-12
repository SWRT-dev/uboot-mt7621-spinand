// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2022 MediaTek Inc. All rights reserved.
 *
 * Author: Weijie Gao <weijie.gao@mediatek.com>
 */

#include <common.h>
#include <image.h>
#include <linux/types.h>
#include <debug_uart.h>
#include <asm/io.h>
#include <nand.h>
#include <linux/mtd/mtd.h>
#include <mach/../../mt7621/mt7621.h>
#include <asm-generic/gpio.h>
#include <configs/mt7621.h>
#include <errno.h>

void gpio_output(unsigned int pin, int value)
{
	int ret = 0;
	unsigned int gpio;
	char gpio_number[128];
	sprintf(gpio_number, "%d", pin);
#if defined(CONFIG_DM_GPIO)
	ret = gpio_lookup_name(gpio_number, NULL, NULL, &gpio);
#else
	/* turn the gpio name into a gpio number */
	gpio = name_to_gpio(gpio_number);
#endif
	/* grab the pin before we tweak it */
	gpio_request(gpio, "cmd_gpio");
	if (ret && ret != -EBUSY) {
		printf("gpio: requesting pin %u failed\n", gpio);
		return;
	}

	gpio_direction_output(gpio, value);
	if (ret != -EBUSY)
		gpio_free(gpio);
}

int gpio_input(unsigned int pin)
{
	int ret = 0;
	unsigned int gpio;
	int value;
	char gpio_number[128];
	sprintf(gpio_number, "%d", pin);
#if defined(CONFIG_DM_GPIO)
	ret = gpio_lookup_name(gpio_number, NULL, NULL, &gpio);
#else
	/* turn the gpio name into a gpio number */
	gpio = name_to_gpio(gpio_number);
#endif
	/* grab the pin before we tweak it */
	gpio_request(gpio, "cmd_gpio");
	if (ret && ret != -EBUSY) {
		printf("gpio: requesting pin %u failed\n", gpio);
		return -1;
	}

	gpio_direction_input(gpio);
	value = gpio_get_value(gpio);
	if (ret != -EBUSY)
		gpio_free(gpio);

	return value;
}

void gpio_init(void)
{
	printf("%s ......\n", __func__);
#if !defined(CONFIG_RMAC2100) && !defined(CONFIG_PGBM1)
	gpio_input(WPS_BTN);
#endif
	gpio_input(RST_BTN);
	gpio_output(PWR_LED,0);
#if !defined(CONFIG_R6800) && !defined(CONFIG_H3CTX1801)
	gpio_output(WIFI_2G_LED,0);
	gpio_output(WIFI_5G_LED,0);
#endif
}

void LEDON(void)
{
	gpio_output(PWR_LED,1);
}

void LEDOFF(void)
{
	gpio_output(PWR_LED,0);
}


void PWR_LEDON(void)
{
#if defined(CONFIG_RTAX53U) || defined(CONFIG_RTAX54) || defined(CONFIG_RTAC85P) || defined(CONFIG_RMAC2100) || defined(CONFIG_R6800) || defined(CONFIG_PGBM1) || defined(CONFIG_H3CTX1801)
	gpio_output(PWR_LED,0);
#elif defined(CONFIG_4GAX56)
	gpio_output(PWR_LED,1);
#endif
}

unsigned long DETECT(void)
{
	int key = 0;
	if(!gpio_input(RST_BTN))
	{
		key = 1;
		printf("reset buootn pressed!\n");
	}
	return key;
}

unsigned long DETECT_WPS(void)
{
	int key = 0;
#if !defined(CONFIG_RMAC2100) && !defined(CONFIG_PGBM1)
	if(!gpio_input(WPS_BTN))
	{
		key = 1;
		printf("wps buootn pressed!\n");
	}
#endif
	return key;
}
