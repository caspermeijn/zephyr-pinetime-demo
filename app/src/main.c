/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <drivers/sensor.h>

#include "app_version.h"

#include <logging/log.h>
LOG_MODULE_REGISTER(main, CONFIG_APP_LOG_LEVEL);

void main(void)
{
	printk("Zephyr Pinetime demo Application %s\n", APP_VERSION_STR);

	while (1) {
		printk("Hello world\n");

		k_sleep(K_MSEC(1000));
	}
}

