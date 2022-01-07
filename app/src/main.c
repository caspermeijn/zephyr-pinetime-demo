/*
 * Copyright (c) 2022 Casper Meijn <casper@meijn.net
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

#include "app_version.h"

#include <logging/log.h>
LOG_MODULE_REGISTER(main, CONFIG_APP_LOG_LEVEL);

const struct gpio_dt_spec gpio_backlight = GPIO_DT_SPEC_GET(DT_ALIAS(led2), gpios);

static int backlight_init() {
    if (!device_is_ready(gpio_backlight.port)) {
        printk("Error: Backlight gpio is not ready\n");
        return -1;
    }

    int ret = gpio_pin_configure_dt(&gpio_backlight, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printk("Error: Failed to initialize backlight gpio: %i\n", ret);
        return ret;
    }
}

static int backlight_toggle() {
    int ret = gpio_pin_toggle_dt(&gpio_backlight);
    if (ret < 0) {
        printk("Error: Failed to toggle backlight gpio: %i\n", ret);
        return ret;
    }
}

void main(void)
{
	printk("Zephyr Pinetime demo Application %s\n", APP_VERSION_STR);

    backlight_init();

    while (1) {
        backlight_toggle();

        printk("Hello world\n");

        k_msleep(1000);
    }
}

