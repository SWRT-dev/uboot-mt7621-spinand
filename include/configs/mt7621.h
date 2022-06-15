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

/* Ethernet */
#define CONFIG_IPADDR			192.168.1.1
#define CONFIG_SERVERIP			192.168.1.10
#define CONFIG_NETMASK			255.255.255.0

#if defined(CONFIG_ASUS_PRODUCT)
/* NVRAM */
#if defined(CONFIG_R6800) || defined(CONFIG_RMAC2100)
#define NAND_NVRAM_OFFSET            0x140000   /* NVRAM offset */
#define NAND_NVRAM_SIZE              0x40000  /* NVRAM max size : 128K + 128K(backup) */
#elif defined(CONFIG_H3CTX1801)
#define NAND_NVRAM_OFFSET            0x77C0000   /* NVRAM offset */
#define NAND_NVRAM_SIZE              0x40000  /* NVRAM max size : 128K + 128K(backup) */
#elif defined(CONFIG_PGBM1)
#define NAND_NVRAM_OFFSET            0x100000   /* NVRAM offset */
#define NAND_NVRAM_SIZE              0x10000  /* NVRAM max size : 128K + 128K(backup) */
#else
#define NAND_NVRAM_OFFSET            0xe0000   /* NVRAM offset */
#define NAND_NVRAM_SIZE              0x100000  /* NVRAM max size : 128K + 128K(backup) */
#endif

/* FACTORY */
#if defined(CONFIG_R6800)
#define NAND_RF_OFFSET               0x4600000
#define MAX_NAND_RF_SIZE             0x400000  /* RF max size : 256K + 256K(backup) */
#elif defined(CONFIG_RMAC2100)
#define NAND_RF_OFFSET               0x100000
#define MAX_NAND_RF_SIZE             0x40000  /* RF max size : 256K + 256K(backup) */
#elif defined(CONFIG_H3CTX1801)
#define NAND_RF_OFFSET               0x180000
#define MAX_NAND_RF_SIZE             0x80000  /* RF max size : 256K + 256K(backup) */
#elif defined(CONFIG_PGBM1)
#define NAND_RF_OFFSET               0x200000
#define MAX_NAND_RF_SIZE             0x100000
#else
#define NAND_RF_OFFSET               0x1e0000
#define MAX_NAND_RF_SIZE             0x100000  /* RF max size : 256K + 256K(backup) */
#endif

/* FACTORY2 */
#if defined(CONFIG_R6800)
#define NAND_RF_OFFSET_2             0x4600000
#define MAX_NAND_RF_SIZE_2           0x400000  /* RF max size : 256K + 256K(backup) */
#elif defined(CONFIG_RMAC2100)
#define NAND_RF_OFFSET_2             0x100000
#define MAX_NAND_RF_SIZE_2           0x40000  /* RF max size : 256K + 256K(backup) */
#elif defined(CONFIG_H3CTX1801)
#define NAND_RF_OFFSET_2             0x7740000
#define MAX_NAND_RF_SIZE_2           0x80000  /* RF max size : 256K + 256K(backup) */
#elif defined(CONFIG_PGBM1)
#define NAND_RF_OFFSET_2              0x300000
#define MAX_NAND_RF_SIZE_2            0x100000
#else
#define NAND_RF_OFFSET_2             0x2e0000
#define MAX_NAND_RF_SIZE_2           0x100000  /* RF max size : 256K + 256K(backup) */
#endif

/* KERNEL */
#if defined(CONFIG_R6800) || defined(CONFIG_RMAC2100)
#define NAND_LINUX_OFFSET            0x200000
#define MAX_NAND_LINUX_SIZE          0x2800000
#elif defined(CONFIG_RTAC85P) || defined(CONFIG_PGBM1)
#define NAND_LINUX_OFFSET          0x3e0000
#define MAX_NAND_LINUX_SIZE        0x2300000
#elif defined(CONFIG_H3CTX1801)
#define NAND_LINUX_OFFSET          0x200000
#define MAX_NAND_LINUX_SIZE        0x2300000
#elif defined(CONFIG_PGBM1)
#define NAND_LINUX_OFFSET          0x400000
#define MAX_NAND_LINUX_SIZE        0x3C00000
#else
#define NAND_LINUX_OFFSET            0x3e0000
#define MAX_NAND_LINUX_SIZE          0x3200000
#endif

/* KERNEL2 */
#if defined(CONFIG_R6800) || defined(CONFIG_RMAC2100)
#define NAND_LINUX_OFFSET_2            0x200000
#define MAX_NAND_LINUX_SIZE_2          0x2800000
#elif defined(CONFIG_RTAC85P) || defined(CONFIG_PGBM1)
#define NAND_LINUX_OFFSET_2          0x35e0000
#define MAX_NAND_LINUX_SIZE_2        0x2300000
#elif defined(CONFIG_H3CTX1801)
#define NAND_LINUX_OFFSET_2          0x2500000
#define MAX_NAND_LINUX_SIZE_2        0x2300000
#elif defined(CONFIG_PGBM1)
#define NAND_LINUX_OFFSET_2          0x400000
#define MAX_NAND_LINUX_SIZE_2        0x3C00000
#else
#define NAND_LINUX_OFFSET_2          0x35e0000
#define MAX_NAND_LINUX_SIZE_2        0x3200000
#endif

#define MAX_NAND_PAGE_SIZE           2048
#define MAX_NAND_BLOCK_SIZE          262144

#define BOOTLOADER_VER_OFFSET        0x2ff7a
#define MAC_OFFSET                   0x4
#define MAC_5G_OFFSET                0xA
#define PIN_CODE_OFFSET              0x2ff70
#define COUNTRY_CODE_OFFSET          0x2ff78
#if !defined(CONFIG_PGBM1)
#define DUAL_TRX
#endif
#endif

#if defined(CONFIG_RTAX53U) || defined(CONFIG_RTAX54)
#define WPS_BTN                 15
#define RST_BTN                 16
#define PWR_LED                 13
#define WIFI_2G_LED             18
#define WIFI_5G_LED             26
#endif 

#ifdef CONFIG_4GAX56
#define WPS_BTN                 4
#define RST_BTN                 8
#define PWR_LED                 14
#define WIFI_2G_LED             13
#define WIFI_5G_LED             16
#define WAN_LED                 15
#define LTE_2G_LED              3
#define LTE_3G_LED              7
#define LTE_4G_LED              10
#define LTE_NO_SIG_LED          0
#endif
#if defined(CONFIG_RTAC85P)
#define WPS_BTN                 6
#define RST_BTN                 3
#define PWR_LED                 4
#define WIFI_2G_LED             10
#define WIFI_5G_LED             8
#endif
#if defined(CONFIG_R6800)
#define WPS_BTN                 18
#define RST_BTN                 12
#define PWR_LED                 5
//#define WIFI_2G_LED             12
//#define WIFI_5G_LED             13
#endif
#if defined(CONFIG_RMAC2100)
//#define WPS_BTN                 6
#define RST_BTN                 18
#define PWR_LED                 8
#define WIFI_2G_LED             10
#define WIFI_5G_LED             6
#endif
#if defined(CONFIG_PGBM1)
#define RST_BTN                 7
#define PWR_LED                 5
#define WIFI_2G_LED             13
#define WIFI_5G_LED             14
#endif
#if defined(CONFIG_H3CTX1801)
#define WPS_BTN                 14
#define RST_BTN                 13
#define PWR_LED                 16
#endif

#endif /* __CONFIG_MT7621_H */
