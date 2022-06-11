/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2022 MediaTek Inc. All rights reserved.
 *
 * Author: Weijie Gao <weijie.gao@mediatek.com>
 */

#ifndef __CONFIG_MT7621_H
#define __CONFIG_MT7621_H

#define CONFIG_SYS_HZ			1000
#define CONFIG_SYS_MIPS_TIMER_FREQ	440000000

#define CONFIG_SYS_BOOTPARAMS_LEN	0x20000

#define CONFIG_SYS_SDRAM_BASE		0x80000000

#define CONFIG_VERY_BIG_RAM
#define CONFIG_MAX_MEM_MAPPED		0x1c000000

#define CONFIG_SYS_INIT_SP_OFFSET	0x800000

#define CONFIG_SYS_BOOTM_LEN		0x2000000

#define CONFIG_SYS_MAXARGS		16
#define CONFIG_SYS_CBSIZE		1024

#define CONFIG_SYS_NONCACHED_MEMORY	0x100000

/* MMC */
#define MMC_SUPPORTS_TUNING

/* NAND */
#define CONFIG_SYS_MAX_NAND_DEVICE	1

/* Serial SPL */
#if defined(CONFIG_SPL_BUILD) && defined(CONFIG_SPL_SERIAL)
#define CONFIG_SYS_NS16550_MEM32
#define CONFIG_SYS_NS16550_CLK		50000000
#define CONFIG_SYS_NS16550_REG_SIZE	-4
#define CONFIG_SYS_NS16550_COM1		0xbe000c00
#endif

/* Serial common */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200, \
					  230400, 460800, 921600 }

/* SPL */
#define CONFIG_SYS_UBOOT_START		CONFIG_SYS_TEXT_BASE

#ifdef CONFIG_TPL_BUILD
#define CONFIG_SPL_START_S_PATH		"arch/mips/mach-mtmips/mt7621/tpl"
/* .bss will not be used by TPL */
#define CONFIG_SPL_BSS_START_ADDR	0x80000000
#define CONFIG_SPL_BSS_MAX_SIZE		0
#else
#define CONFIG_SPL_START_S_PATH		"arch/mips/mach-mtmips/mt7621/spl"
#define CONFIG_SPL_BSS_START_ADDR	0x80140000
#define CONFIG_SPL_BSS_MAX_SIZE		0x80000
#define CONFIG_SPL_MAX_SIZE		0x30000
#endif

/* Dummy value */
#define CONFIG_SYS_UBOOT_BASE		0
#define CONFIG_SYS_NAND_U_BOOT_OFFS	0

#endif /* __CONFIG_MT7621_H */
