/* Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/init.h>
#include <linux/ioport.h>
#include <mach/board.h>
#include <mach/gpio.h>
#include <mach/gpiomux.h>
#include <mach/board_lge.h>
#include <mach/socinfo.h>

#define KS8851_IRQ_GPIO 115

#if defined(CONFIG_KS8851) || defined(CONFIG_KS8851_MODULE)
static struct gpiomux_setting gpio_eth_config = {
	.pull = GPIOMUX_PULL_UP,
	.drv = GPIOMUX_DRV_2MA,
	.func = GPIOMUX_FUNC_GPIO,
};

static struct msm_gpiomux_config msm_eth_configs[] = {
	{
		.gpio = KS8851_IRQ_GPIO,
		.settings = {
			[GPIOMUX_SUSPENDED] = &gpio_eth_config,
		}
	},
};
#endif

static struct gpiomux_setting melfas_int_act_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_UP,
	.dir = GPIOMUX_IN,
};

static struct gpiomux_setting melfas_int_sus_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
	.dir = GPIOMUX_OUT_HIGH,
};

static struct gpiomux_setting touch_enable_act_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_HIGH,
};

static struct gpiomux_setting touch_enable_sus_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};

static struct gpiomux_setting touch_misc_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_IN,
};

static struct gpiomux_setting atmel_chg_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_IN,
};

static struct gpiomux_setting atmel_reset_act_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_HIGH,
};

static struct gpiomux_setting atmel_reset_sus_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_IN,
};

static struct gpiomux_setting atmel_reserved_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_IN,
};

static struct gpiomux_setting gpio_keys_active = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_UP,
};

static struct gpiomux_setting gpio_keys_suspend = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
};

static struct gpiomux_setting gpio_spi_config = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
};

static struct gpiomux_setting gpio_spi_cs_config = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_6MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct gpiomux_setting gpio_spi_cs_eth_config = {
	.func = GPIOMUX_FUNC_4,
	.drv = GPIOMUX_DRV_6MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct gpiomux_setting wcnss_5wire_suspend_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv  = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_UP,
};

static struct gpiomux_setting wcnss_5wire_active_cfg = {
	.func = GPIOMUX_FUNC_1,
	.drv  = GPIOMUX_DRV_6MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct gpiomux_setting gpio_i2c_config = {
	.func = GPIOMUX_FUNC_3,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
};

static struct msm_gpiomux_config msm_keypad_configs[] __initdata = {
	{
		.gpio = 106,
		.settings = {
			[GPIOMUX_ACTIVE]    = &gpio_keys_active,
			[GPIOMUX_SUSPENDED] = &gpio_keys_suspend,
		},
	},
	{
		.gpio = 107,
		.settings = {
			[GPIOMUX_ACTIVE]    = &gpio_keys_active,
			[GPIOMUX_SUSPENDED] = &gpio_keys_suspend,
		},
	},
	{
		.gpio = 108,
		.settings = {
			[GPIOMUX_ACTIVE]    = &gpio_keys_active,
			[GPIOMUX_SUSPENDED] = &gpio_keys_suspend,
		},
	},
	{
		.gpio = 109,
		.settings = {
			[GPIOMUX_ACTIVE]    = &gpio_keys_active,
			[GPIOMUX_SUSPENDED] = &gpio_keys_suspend,
		},
	},
};

static struct gpiomux_setting lcd_rst_act_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_UP,
	.dir = GPIOMUX_OUT_HIGH,
};

static struct gpiomux_setting lcd_rst_sus_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct msm_gpiomux_config msm_lcd_configs[] __initdata = {
	{
		.gpio = 25,
		.settings = {
			[GPIOMUX_ACTIVE]    = &lcd_rst_act_cfg,
			[GPIOMUX_SUSPENDED] = &lcd_rst_sus_cfg,
		},
	}
};

static struct msm_gpiomux_config msm_blsp_configs[] __initdata = {
	{
		.gpio      = 0,		/* BLSP1 QUP1 SPI_DATA_MOSI */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gpio_spi_config,
		},
	},
	{
		.gpio      = 1,		/* BLSP1 QUP1 SPI_DATA_MISO */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gpio_spi_config,
		},
	},
	{
		.gpio      = 2,		/* BLSP1 QUP1 SPI_CS1 */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gpio_spi_cs_config,
		},
	},
	{
		.gpio      = 3,		/* BLSP1 QUP1 SPI_CLK */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gpio_spi_config,
		},
	},
#ifdef CONFIG_MACH_LGE  /* LGE_CHANGE_S,  Added for COMMON_I2C */
	{
		.gpio      = 10,	/* BLSP1 QUP3 I2C_SDA */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gpio_i2c_config,
		},
	},
	{
		.gpio      = 11,	/* BLSP1 QUP3 I2C_SCL */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gpio_i2c_config,
		},
	},
#endif
	{
		.gpio      = 14,	/* BLSP1 QUP4 I2C_SDA */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gpio_i2c_config,
		},
	},
	{
		.gpio      = 15,	/* BLSP1 QUP4 I2C_SCL */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gpio_i2c_config,
		},
	},
	{
		.gpio      = 18,		/* BLSP1 QUP5 I2C_SDA */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gpio_i2c_config,
		},
	},
	{
		.gpio      = 19,		/* BLSP1 QUP5 I2C_SCL */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gpio_i2c_config,
		},
	},
	{
		.gpio      = 22,		/* BLSP1 QUP1 SPI_CS_ETH */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gpio_spi_cs_eth_config,
		},
	},
};

static struct msm_gpiomux_config msm_melfas_configs[] __initdata = {
	{
		.gpio = 16,
		.settings = {
			[GPIOMUX_ACTIVE] = &melfas_int_act_cfg,
			[GPIOMUX_SUSPENDED] = &melfas_int_sus_cfg,
		},
	},
};

static struct msm_gpiomux_config msm_melfas_configs_rev_c[] __initdata = {
	{
		.gpio = 17,
		.settings = {
			[GPIOMUX_ACTIVE] = &touch_misc_cfg,
			[GPIOMUX_SUSPENDED] = &touch_misc_cfg,
		},
	},
	{
		.gpio = 60,
		.settings = {
			[GPIOMUX_ACTIVE] = &touch_enable_act_cfg,
			[GPIOMUX_SUSPENDED] = &touch_enable_sus_cfg,
		},
	},
	{
		.gpio = 66,
		.settings = {
			[GPIOMUX_ACTIVE] = &touch_misc_cfg,
			[GPIOMUX_SUSPENDED] = &touch_misc_cfg,
		},
	},
};

static struct msm_gpiomux_config msm_atmel_configs_rev_d[] __initdata = {
	{
		.gpio = 17,
		.settings = {
			[GPIOMUX_ACTIVE] = &atmel_chg_cfg,
			[GPIOMUX_SUSPENDED] = &atmel_chg_cfg,
		},
	},
	{
		.gpio = 60,
		.settings = {
			[GPIOMUX_ACTIVE] = &atmel_reset_act_cfg,
			[GPIOMUX_SUSPENDED] = &atmel_reset_sus_cfg,
		},
	},
	{
		.gpio = 120,
		.settings = {
			[GPIOMUX_ACTIVE] = &atmel_reserved_cfg,
			[GPIOMUX_SUSPENDED] = &atmel_reserved_cfg,
		},
	},
};

static struct gpiomux_setting hall_ic_sus_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_IN,
};

static struct msm_gpiomux_config msm_hall_ic_configs[] __initdata = {
	{
		.gpio = 4,
		.settings = {
			[GPIOMUX_SUSPENDED] = &hall_ic_sus_cfg,
		},
    },
};

static struct gpiomux_setting sd_card_det_active_config = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_IN,
};

#ifdef CONFIG_MACH_LGE
static struct gpiomux_setting sd_card_det_sleep_config = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_IN,
};
#else // not CONFIG_MACH_LGE
static struct gpiomux_setting sd_card_det_sleep_config = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_UP,
	.dir = GPIOMUX_IN,
};
#endif // CONFIG_MACH_LGE

static struct msm_gpiomux_config sd_card_det __initdata = {
	.gpio = 37,
	.settings = {
		[GPIOMUX_ACTIVE]    = &sd_card_det_active_config,
		[GPIOMUX_SUSPENDED] = &sd_card_det_sleep_config,
	},
};

static struct msm_gpiomux_config wcnss_5wire_interface[] = {
	{
		.gpio = 40,
		.settings = {
			[GPIOMUX_ACTIVE]    = &wcnss_5wire_active_cfg,
			[GPIOMUX_SUSPENDED] = &wcnss_5wire_suspend_cfg,
		},
	},
	{
		.gpio = 41,
		.settings = {
			[GPIOMUX_ACTIVE]    = &wcnss_5wire_active_cfg,
			[GPIOMUX_SUSPENDED] = &wcnss_5wire_suspend_cfg,
		},
	},
	{
		.gpio = 42,
		.settings = {
			[GPIOMUX_ACTIVE]    = &wcnss_5wire_active_cfg,
			[GPIOMUX_SUSPENDED] = &wcnss_5wire_suspend_cfg,
		},
	},
	{
		.gpio = 43,
		.settings = {
			[GPIOMUX_ACTIVE]    = &wcnss_5wire_active_cfg,
			[GPIOMUX_SUSPENDED] = &wcnss_5wire_suspend_cfg,
		},
	},
	{
		.gpio = 44,
		.settings = {
			[GPIOMUX_ACTIVE]    = &wcnss_5wire_active_cfg,
			[GPIOMUX_SUSPENDED] = &wcnss_5wire_suspend_cfg,
		},
	},
};

static struct gpiomux_setting gpio_suspend_config[] = {
	{
		.func = GPIOMUX_FUNC_GPIO,  /* IN-NP */
		.drv = GPIOMUX_DRV_2MA,
		.pull = GPIOMUX_PULL_NONE,
	},
	{
		.func = GPIOMUX_FUNC_GPIO,  /* O-LOW */
		.drv = GPIOMUX_DRV_2MA,
		.pull = GPIOMUX_PULL_NONE,
		.dir = GPIOMUX_OUT_LOW,
	},
};

static struct gpiomux_setting cam_settings[] = {
	{
		.func = GPIOMUX_FUNC_1, /*active 1*/ /* 0 */
		.drv = GPIOMUX_DRV_2MA,
		.pull = GPIOMUX_PULL_NONE,
	},

	{
		.func = GPIOMUX_FUNC_1, /*suspend*/ /* 1 */
		.drv = GPIOMUX_DRV_2MA,
		.pull = GPIOMUX_PULL_DOWN,
	},

	{
		.func = GPIOMUX_FUNC_1, /*i2c suspend*/ /* 2 */
		.drv = GPIOMUX_DRV_2MA,
		.pull = GPIOMUX_PULL_KEEPER,
	},

	{
		.func = GPIOMUX_FUNC_GPIO, /*active 0*/ /* 3 */
		.drv = GPIOMUX_DRV_2MA,
		.pull = GPIOMUX_PULL_NONE,
	},

	{
		.func = GPIOMUX_FUNC_GPIO, /*suspend 0*/ /* 4 */
		.drv = GPIOMUX_DRV_2MA,
		.pull = GPIOMUX_PULL_DOWN,
	},
};


static struct msm_gpiomux_config msm_sensor_configs[] __initdata = {
	{
		.gpio = 26, /* CAM_MCLK0 */
		.settings = {
			[GPIOMUX_ACTIVE]    = &cam_settings[0],
			[GPIOMUX_SUSPENDED] = &cam_settings[1],
		},
	},
	{
		.gpio = 27, /* CAM_MCLK1 */
		.settings = {
			[GPIOMUX_ACTIVE]    = &cam_settings[0],
			[GPIOMUX_SUSPENDED] = &cam_settings[1],
		},

	},
	{
		.gpio = 29, /* CCI_I2C_SDA0 */
		.settings = {
			[GPIOMUX_ACTIVE]    = &cam_settings[0],
			[GPIOMUX_SUSPENDED] = &gpio_suspend_config[0],
		},
	},
	{
		.gpio = 30, /* CCI_I2C_SCL0 */
		.settings = {
			[GPIOMUX_ACTIVE]    = &cam_settings[0],
			[GPIOMUX_SUSPENDED] = &gpio_suspend_config[0],
		},
	},
	{
		.gpio = 36, /* CAM1_STANDBY_N */
		.settings = {
			[GPIOMUX_ACTIVE]    = &cam_settings[3],
			[GPIOMUX_SUSPENDED] = &cam_settings[4],
		},
	},
	{
		.gpio = 114, /* CAM1_RST_N */
		.settings = {
			[GPIOMUX_ACTIVE]    = &cam_settings[3],
			[GPIOMUX_SUSPENDED] = &cam_settings[4],
		},
	},
	{
		.gpio = 35, /* CAM2_STANDBY_N */
		.settings = {
			[GPIOMUX_ACTIVE]    = &cam_settings[3],
			[GPIOMUX_SUSPENDED] = &cam_settings[4],
		},
	},
	{
		.gpio = 28, /* CAM2_RST_N */
		.settings = {
			[GPIOMUX_ACTIVE]    = &cam_settings[3],
			[GPIOMUX_SUSPENDED] = &cam_settings[4],
		},
	},

};

#ifndef CONFIG_MACH_LGE
static struct gpiomux_setting auxpcm_act_cfg = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
};

static struct gpiomux_setting auxpcm_sus_cfg = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct msm_gpiomux_config msm_auxpcm_configs[] __initdata = {
	{
		.gpio = 63,
		.settings = {
			[GPIOMUX_SUSPENDED] = &auxpcm_sus_cfg,
			[GPIOMUX_ACTIVE] = &auxpcm_act_cfg,
		},
	},
	{
		.gpio = 64,
		.settings = {
			[GPIOMUX_SUSPENDED] = &auxpcm_sus_cfg,
			[GPIOMUX_ACTIVE] = &auxpcm_act_cfg,
		},
	},
	{
		.gpio = 65,
		.settings = {
			[GPIOMUX_SUSPENDED] = &auxpcm_sus_cfg,
			[GPIOMUX_ACTIVE] = &auxpcm_act_cfg,
		},
	},
	{
		.gpio = 66,
		.settings = {
			[GPIOMUX_SUSPENDED] = &auxpcm_sus_cfg,
			[GPIOMUX_ACTIVE] = &auxpcm_act_cfg,
		},
	},
};

static struct gpiomux_setting usb_otg_sw_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.dir = GPIOMUX_OUT_LOW,
};

static struct msm_gpiomux_config usb_otg_sw_configs[] __initdata = {
	{
		.gpio = 67,
		.settings = {
			[GPIOMUX_SUSPENDED] = &usb_otg_sw_cfg,
		},
	},
};
#endif


#ifdef CONFIG_MACH_LGE /* X5 SPR */
/* Reserved Pin Setting */

// GPIO related function <<0.Resreved Pin>>
#define MSM8x26_GPIO_END 121
static int gpio_reserved_pin_rev_B[] = {
	0, 1, 2, 3, 5, 12, 13, 14, 15, 17, 31, 49, 50, 51, 52, 53, 54, 55, 56, 60, 63, 64, 65, 73, 74, 75, 76, 78, 79, 82, 83, 84, 88, 90, 94, 95, 96, 97, 103, 104, 115, 116, 117, 118,
	MSM8x26_GPIO_END // This is included to notify the end of reserved GPIO configuration.
	};
	
static int gpio_reserved_pin_rev_D[] = {
	0, 1, 2, 3, 5, 12, 13, 14, 15, 31, 34, 49, 50, 51, 52, 53, 54, 55, 56, 63, 64, 65, 67, 73, 74, 75, 76, 78, 79, 80, 82, 83, 84, 88, 90, 94, 95, 96, 97, 98, 103, 104, 109, 115, 116, 117, 118,
	MSM8x26_GPIO_END // This is included to notify the end of reserved GPIO configuration.
	};
	
static struct gpiomux_setting reserved_pin_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
	.dir  = GPIOMUX_IN,
};

static struct msm_gpiomux_config gpio_func_reserved_pin_config __initdata = {
	.gpio = 0,
	.settings = {
		[GPIOMUX_SUSPENDED] = &reserved_pin_cfg,
		[GPIOMUX_ACTIVE] = &reserved_pin_cfg,
	},
};
#endif
// GPIO related function <<5.NFC>>
//+GPIO[010] COMMON_I2C_SDA
//+GPIO[011] COMMON_I2C_SCL
//Need to set GPIO[020] NFC_VEN
//Need to set GPIO[021] NFC_IRQ
//Need to set GPIO[022] NFC_MODE
/*                                                        */
#ifdef CONFIG_LGE_NFC_PN544_C3
static struct gpiomux_setting nfc_pn544_sda_cfg = {
	.func = GPIOMUX_FUNC_3,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
};

static struct gpiomux_setting nfc_pn544_scl_cfg = {
	.func = GPIOMUX_FUNC_3,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
};

static struct gpiomux_setting nfc_pn544_ven_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};

static struct gpiomux_setting nfc_pn544_irq_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_DOWN,
	.dir = GPIOMUX_IN,
};

static struct gpiomux_setting nfc_pn544_mode_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_HIGH,
};

static struct msm_gpiomux_config msm_nfc_configs[] __initdata = {
	{
		/* I2C SDA */
		.gpio      = 10,
		.settings = {
			[GPIOMUX_ACTIVE]    = &nfc_pn544_sda_cfg,
			[GPIOMUX_SUSPENDED] = &nfc_pn544_sda_cfg,
		},
	},
	{
		/* I2C SCL */
		.gpio      = 11,
		.settings = {
			[GPIOMUX_ACTIVE]    = &nfc_pn544_scl_cfg,
			[GPIOMUX_SUSPENDED] = &nfc_pn544_scl_cfg,
		},
	},
	{
		/* VEN */
		.gpio      = 20,
		.settings = {
			[GPIOMUX_ACTIVE]    = &nfc_pn544_ven_cfg,
			[GPIOMUX_SUSPENDED] = &nfc_pn544_ven_cfg,
		},
	},
	{
		/* IRQ */
		.gpio      = 21,
		.settings = {
			[GPIOMUX_ACTIVE]    = &nfc_pn544_irq_cfg,
			[GPIOMUX_SUSPENDED] = &nfc_pn544_irq_cfg,
		},
	},
	{
		/* MODE *//* WAKE */
		.gpio      = 22,
		.settings = {
			[GPIOMUX_ACTIVE]    = &nfc_pn544_mode_cfg,
			[GPIOMUX_SUSPENDED] = &nfc_pn544_mode_cfg,
		},
	},
};
#endif
/*                                                        */

void __init msm8226_init_gpiomux(void)
{
	int rc;
#ifdef CONFIG_MACH_LGE
	int gpio_index = 0;
	hw_rev_type hw_rev;
	hw_rev = lge_get_board_revno();
#endif
	rc = msm_gpiomux_init_dt();
	if (rc) {
		pr_err("%s failed %d\n", __func__, rc);
		return;
	}
#ifdef CONFIG_MACH_LGE

	//--------------------------------------------
	// MSM8X26 GPIO Confiuration via X5
	//--------------------------------------------
	// GPIO related function <<0.Resreved Pin>>
	// GPIO related function <<1.SENSOR>>
	// GPIO related function <<2.I2C>>
	// GPIO related function <<3.UART>>
	// GPIO related function <<4.TOUCH>>
	// GPIO related function <<5.NFC>>
	// GPIO related function <<6.LCD>>
	// GPIO related function <<7.CAMERA>>
	// GPIO related function <<8.FLASH LED>>
	// GPIO related function <<9.IRRC>>
	// GPIO related function <<10.AUDIO>>
	// GPIO related function <<11.SD CARD>>
	// GPIO related function <<12.BATTERY>>
	// GPIO related function <<13.BT>>
	// GPIO related function <<14.WIFI>>
	// GPIO related function <<15.FM>>
	// GPIO related function <<16.WLC>>
	// GPIO related function <<17.SIM>>
	// GPIO related function <<18.SLIMBUS>>
	// GPIO related function <<19.RF>>
	// GPIO related function <<20.KEY PAD>>
	// GPIO related function <<21.LOGIC>>

	// GPIO related function <<0.Resreved Pin>>
	switch ( hw_rev ){
		case HW_REV_0 :
		case HW_REV_A :
		case HW_REV_B :
            for ( gpio_index = 0 ; gpio_reserved_pin_rev_B[gpio_index] < MSM8x26_GPIO_END ; gpio_index++ ){
				gpio_func_reserved_pin_config.gpio = gpio_reserved_pin_rev_B[gpio_index];
				msm_gpiomux_install(&gpio_func_reserved_pin_config, 1);
			}
			break;
		case HW_REV_C :
		case HW_REV_D :
		    for ( gpio_index = 0 ; gpio_reserved_pin_rev_D[gpio_index] < MSM8x26_GPIO_END ; gpio_index++ ){
				gpio_func_reserved_pin_config.gpio = gpio_reserved_pin_rev_D[gpio_index];
				msm_gpiomux_install(&gpio_func_reserved_pin_config, 1);
			}
			break;
		case HW_REV_E :
		case HW_REV_1_0 :
		case HW_REV_1_1 :
		default :
		    for ( gpio_index = 0 ; gpio_reserved_pin_rev_D[gpio_index] < MSM8x26_GPIO_END ; gpio_index++ ){
				gpio_func_reserved_pin_config.gpio = gpio_reserved_pin_rev_D[gpio_index];
				msm_gpiomux_install(&gpio_func_reserved_pin_config, 1);
			}
			break;
	}
#endif

#if defined(CONFIG_KS8851) || defined(CONFIG_KS8851_MODULE)
	msm_gpiomux_install(msm_eth_configs, ARRAY_SIZE(msm_eth_configs));
#endif
	msm_gpiomux_install(msm_keypad_configs,
			ARRAY_SIZE(msm_keypad_configs));

	msm_gpiomux_install(msm_blsp_configs, ARRAY_SIZE(msm_blsp_configs));
	msm_gpiomux_install(wcnss_5wire_interface,
				ARRAY_SIZE(wcnss_5wire_interface));

	msm_gpiomux_install(&sd_card_det, 1);

	if (hw_rev <= HW_REV_B) {
		msm_gpiomux_install(msm_melfas_configs, ARRAY_SIZE(msm_melfas_configs));
		printk(KERN_ERR "[Touch] HW_REV_0, A, B configs \n");
	} else if (hw_rev == HW_REV_C) {
		msm_gpiomux_install(msm_melfas_configs_rev_c, ARRAY_SIZE(msm_melfas_configs_rev_c));
		printk(KERN_ERR "[Touch] HW_REV_C configs \n");
	} else {
		msm_gpiomux_install(msm_atmel_configs_rev_d, ARRAY_SIZE(msm_atmel_configs_rev_d));
		printk(KERN_ERR "[Touch] HW_REV_D or above use Atmel \n");
	}

	msm_gpiomux_install_nowrite(msm_lcd_configs,
			ARRAY_SIZE(msm_lcd_configs));
	msm_gpiomux_install(msm_sensor_configs, ARRAY_SIZE(msm_sensor_configs));
	msm_gpiomux_install(msm_hall_ic_configs, ARRAY_SIZE(msm_hall_ic_configs));
#ifndef CONFIG_MACH_LGE
	msm_gpiomux_install(msm_auxpcm_configs,
			ARRAY_SIZE(msm_auxpcm_configs));

	if (of_board_is_cdp() || of_board_is_mtp() || of_board_is_xpm())
		msm_gpiomux_install(usb_otg_sw_configs,
					ARRAY_SIZE(usb_otg_sw_configs));
#endif


/*                                                         */
#ifdef CONFIG_LGE_NFC_PN544_C3
	msm_gpiomux_install(msm_nfc_configs, ARRAY_SIZE(msm_nfc_configs));
#endif
/*                                                         */


}


