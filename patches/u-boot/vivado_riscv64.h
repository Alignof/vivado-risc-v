/* SPDX-License-Identifier: GPL-2.0+ */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

#define CONFIG_SYS_SDRAM_BASE           0x80000000
#define CONFIG_SYS_INIT_RAM_ADDR        0x80000000
#define CONFIG_SYS_INIT_RAM_SIZE        0x00200000
#define CONFIG_STANDALONE_LOAD_ADDR     0x80201000

#define MMU_SECTION_SIZE 0x1000

#define CONFIG_SYS_BOOTM_LEN            SZ_32M
#define CONFIG_SYS_INIT_SP_ADDR         (CONFIG_SYS_SDRAM_BASE + SZ_2M)
/* Environment options */

#define BOOT_TARGET_DEVICES(func) \
        func(MMC, mmc, 0) \
        func(DHCP, dhcp, na)

#include <config_distro_bootcmd.h>

#define CONFIG_EXTRA_ENV_SETTINGS \
        "bootm_low=0x80300000\0" \
        "bootm_size=0x00800000\0" \
        "initrd_high=0xffffffffffffffff\0" \
        BOOTENV

#endif /* __CONFIG_H */
