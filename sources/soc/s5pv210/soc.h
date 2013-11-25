///////////////////////////////////////////////////////////////////////////////
//	
//	File:	soc.h
//	Description: s5pv210 register definition file
//	
///////////////////////////////////////////////////////////////////////////////


#ifndef _SOC_H
#define _SOC_H

#define __REG(reg)		((volatile unsigned long *)(reg))
#define __REG_V(reg)		(*(volatile unsigned long *)(reg))

/* S5PC110 device base addresses */
#define ELFIN_DMA_BASE			0xE0900000
#define ELFIN_LCD_BASE			0xF8000000
#define ELFIN_USB_HOST_BASE		0xEC200000
#define ELFIN_I2C_BASE			0xE1800000
#define ELFIN_I2S_BASE			0xE2100000
#define ELFIN_ADC_BASE			0xE1700000
#define ELFIN_SPI_BASE			0xE1300000


#define ELFIN_HSMMC_0_BASE		0xEB000000
#define ELFIN_HSMMC_1_BASE		0xEB100000
#define ELFIN_HSMMC_2_BASE		0xEB200000
#define ELFIN_HSMMC_3_BASE		0xEB300000

#define ELFIN_CLOCK_POWER_BASE		0xE0100000

#define IO_RET_REL			((1 << 31) | (1 << 29) | (1 << 28))

/* Clock & Power Controller for s5pc110*/
#define APLL_LOCK_OFFSET		0x00
#define MPLL_LOCK_OFFSET		0x08
#define EPLL_LOCK_OFFSET		0x10
#define VPLL_LOCK_OFFSET		0x20
#define APLL_CON0_OFFSET		0x100
#define APLL_CON1_OFFSET		0x104
#define MPLL_CON_OFFSET		0x108
#define EPLL_CON_OFFSET			0x110
#define VPLL_CON_OFFSET			0x120

#define CLK_SRC0_OFFSET			0x200
#define CLK_SRC1_OFFSET			0x204
#define CLK_SRC2_OFFSET			0x208
#define CLK_SRC3_OFFSET			0x20c
#define CLK_SRC4_OFFSET			0x210
#define CLK_SRC5_OFFSET			0x214
#define CLK_SRC6_OFFSET			0x218
#define CLK_SRC_MASK0_OFFSET		0x280
#define CLK_SRC_MASK1_OFFSET		0x284

#define CLK_DIV0_OFFSET			0x300
#define CLK_DIV1_OFFSET			0x304
#define CLK_DIV2_OFFSET			0x308
#define CLK_DIV3_OFFSET			0x30c
#define CLK_DIV4_OFFSET			0x310
#define CLK_DIV5_OFFSET			0x314
#define CLK_DIV6_OFFSET			0x318
#define CLK_DIV7_OFFSET			0x31c

#define CLK_GATE_IP0_OFFSET		0x460
#define CLK_GATE_IP1_OFFSET		0x464
#define CLK_GATE_IP2_OFFSET		0x468
#define CLK_GATE_IP3_OFFSET		0x46c
#define CLK_GATE_IP4_OFFSET		0x470
#define CLK_GATE_BLOCK_OFFSET		0x480

#define CLK_OUT_OFFSET			0x500
#define CLK_DIV_STAT0_OFFSET		0x1000
#define CLK_DIV_STAT1_OFFSET		0x1004
#define CLK_MUX_STAT0_OFFSET		0x1100
#define CLK_MUX_STAT1_OFFSET		0x1104
#define SW_RST_OFFSET			0x2000

#define rAPLL_LOCK		__REG_V(ELFIN_CLOCK_POWER_BASE + APLL_LOCK_OFFSET)
#define rMPLL_LOCK		__REG_V(ELFIN_CLOCK_POWER_BASE + MPLL_LOCK_OFFSET)

#define rAPLL_CON0 		__REG_V(ELFIN_CLOCK_POWER_BASE + APLL_CON0_OFFSET)
#define rAPLL_CON1 		__REG_V(ELFIN_CLOCK_POWER_BASE + APLL_CON1_OFFSET)	
#define rMPLL_CON 		__REG_V(ELFIN_CLOCK_POWER_BASE + MPLL_CON_OFFSET)

#define rCLK_SRC0 		__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_SRC0_OFFSET)
#define rCLK_SRC1 		__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_SRC1_OFFSET)
#define rCLK_SRC2 		__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_SRC2_OFFSET)
#define rCLK_SRC3 		__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_SRC3_OFFSET)
#define rCLK_SRC4 		__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_SRC4_OFFSET)
#define rCLK_SRC5 		__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_SRC5_OFFSET)
#define rCLK_SRC6 		__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_SRC6_OFFSET)
#define rCLK_SRC_MASK0 		__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_SRC_MASK0_OFFSET)
#define rCLK_SRC_MASK1 		__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_SRC_MASK1_OFFSET)
#define rCLK_DIV0 			__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_DIV0_OFFSET)
#define rCLK_DIV1 			__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_DIV1_OFFSET)
#define rCLK_DIV2 			__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_DIV2_OFFSET)
#define rCLK_DIV3 			__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_DIV3_OFFSET)
#define rCLK_DIV4 			__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_DIV4_OFFSET)
#define rCLK_DIV5 			__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_DIV5_OFFSET)
#define rCLK_DIV6 			__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_DIV6_OFFSET)
#define rCLK_DIV7 			__REG_V(ELFIN_CLOCK_POWER_BASE + CLK_DIV7_OFFSET)

#define ONEDRAM_CFG_OFFSET		0x6208

#define OSC_CON_OFFSET			0x8000
#define RST_STAT_OFFSET			0xa000
#define PWR_CFG_OFFSET			0xc000
#define	EINT_WAKEUP_MASK_OFFSET		0xc004
#define WAKEUP_MASK_OFFSET		0xc008
#define NORMAL_CFG_OFFSET		0xc010
#define IDLE_CFG_OFFSET			0xc020
#define STOP_CFG_OFFSET			0xc030
#define STOP_MEM_CFG_OFFSET		0xc034
#define SLEEP_CFG_OFFSET		0xc040
#define OSC_FREQ_OFFSET			0xc100
#define OSC_STABLE_OFFSET		0xc104
#define PWR_STABLE_OFFSET		0xc108
#define MTC_STABLE_OFFSET		0xc110
#define CLAMP_STABLE_OFFSET		0xc114
#define WAKEUP_STAT_OFFSET		0xc200
#define BLK_PWR_STAT_OFFSET		0xc204
#define BODY_BIAS_CON_OFFSET		0xc300
#define ION_SKEW_CON_OFFSET		0xc310
#define ION_SKEW_MON_OFFSET		0xc314
#define IOFF_SKEW_CON_OFFSET		0xc320
#define IOFF_SKEW_MON_OFFSET		0xc324
#define OTHERS_OFFSET			0xe000
#define OM_STAT_OFFSET			0xe100
#define MIE_CONTROL_OFFSET		0xe800
#define HDMI_CONTROL_OFFSET		0xe804
#define USB_PHY_CONTROL_OFFSET		0xe80c
#define DAC_CONTROL_OFFSET		0xe810
#define MIPI_DPHY_CONTROL_OFFSET	0xe814
#define ADC_CONTROL_OFFSET		0xe818
#define PS_HOLD_CONTROL_OFFSET		0xe81c

#define INFORM0_OFFSET			0xf000
#define INFORM1_OFFSET			0xf004
#define INFORM2_OFFSET			0xf008
#define INFORM3_OFFSET			0xf00c
#define INFORM4_OFFSET			0xf010
#define INFORM5_OFFSET			0xf014
#define INFORM6_OFFSET			0xf018
#define INFORM7_OFFSET			0xf01c

#define INF_REG0_OFFSET			0x00
#define INF_REG1_OFFSET			0x04
#define INF_REG2_OFFSET			0x08
#define INF_REG3_OFFSET			0x0c
#define INF_REG4_OFFSET			0x10
#define INF_REG5_OFFSET			0x14
#define INF_REG6_OFFSET			0x18
#define INF_REG7_OFFSET			0x1c


/*
 * GPIO
 */
#define ELFIN_GPIO_BASE			0xE0200000


#define GPA0CON_OFFSET			0x000
#define GPA0DAT_OFFSET	 		0x004
#define GPA0PUD_OFFSET 			0x008
#define GPA0DRV_SR_OFFSET	 	0x00C
#define GPA0CONPDN_OFFSET 		0x010
#define GPA0PUDPDN_OFFSET 		0x014

#define GPA1CON_OFFSET 		0x020
#define GPA1DAT_OFFSET 		0x024
#define GPA1PUD_OFFSET 			0x028
#define GPA1DRV_SR_OFFSET 		0x02C
#define GPA1CONPDN_OFFSET 		0x030
#define GPA1PUDPDN_OFFSET 		0x034

#define GPBCON_OFFSET 			0x040
#define GPBDAT_OFFSET 			0x044
#define GPBPUD_OFFSET 			0x048
#define GPBDRV_SR_OFFSET 		0x04C
#define GPBCONPDN_OFFSET 		0x050
#define GPBPUDPDN_OFFSET 		0x054

#define GPC0CON_OFFSET 			0x060
#define GPC0DAT_OFFSET 			0x064
#define GPC0PUD_OFFSET 			0x068
#define GPC0DRV_SR_OFFSET 		0x06C
#define GPC0CONPDN_OFFSET 		0x070
#define GPC0PUDPDN_OFFSET 		0x074

#define GPC1CON_OFFSET 			0x080
#define GPC1DAT_OFFSET 			0x084
#define GPC1PUD_OFFSET 			0x088
#define GPC1DRV_SR_OFFSET 		0x08C
#define GPC1CONPDN_OFFSET 		0x090
#define GPC1PUDPDN_OFFSET 		0x094

#define GPD0CON_OFFSET 			0x0A0
#define GPD0DAT_OFFSET 			0x0A4
#define GPD0PUD_OFFSET 			0x0A8
#define GPD0DRV_SR_OFFSET 		0x0AC
#define GPD0CONPDN_OFFSET 		0x0B0
#define GPD0PUDPDN_OFFSET 		0x0B4

#define GPD1CON_OFFSET 			0x0C0
#define GPD1DAT_OFFSET 			0x0C4
#define GPD1PUD_OFFSET 			0x0C8
#define GPD1DRV_SR_OFFSET 		0x0CC
#define GPD1CONPDN_OFFSET 		0x0D0
#define GPD1PUDPDN_OFFSET 		0x0D4

#define GPE0CON_OFFSET 			0x0E0
#define GPE0DAT_OFFSET 			0x0E4
#define GPE0PUD_OFFSET 			0x0E8
#define GPE0DRV_SR_OFFSET 		0x0EC
#define GPE0CONPDN_OFFSET 		0x0F0
#define GPE0PUDPDN_OFFSET 		0x0F4

#define GPE1CON_OFFSET 			0x100
#define GPE1DAT_OFFSET 			0x104
#define GPE1PUD_OFFSET 			0x108
#define GPE1DRV_SR_OFFSET 		0x10C
#define GPE1CONPDN_OFFSET 		0x110
#define GPE1PUDPDN_OFFSET 		0x114

#define GPF0CON_OFFSET 			0x120
#define GPF0DAT_OFFSET 			0x124
#define GPF0PUD_OFFSET 			0x128
#define GPF0DRV_SR_OFFSET 		0x12C
#define GPF0CONPDN_OFFSET 		0x130
#define GPF0PUDPDN_OFFSET 		0x134

#define GPF1CON_OFFSET 			0x140
#define GPF1DAT_OFFSET 			0x144
#define GPF1PUD_OFFSET 			0x148
#define GPF1DRV_SR_OFFSET 		0x14C
#define GPF1CONPDN_OFFSET 		0x150
#define GPF1PUDPDN_OFFSET 		0x154

#define GPF2CON_OFFSET 			0x160
#define GPF2DAT_OFFSET 			0x164
#define GPF2PUD_OFFSET 			0x168
#define GPF2DRV_SR_OFFSET 		0x16C
#define GPF2CONPDN_OFFSET 		0x170
#define GPF2PUDPDN_OFFSET 		0x174

#define GPF3CON_OFFSET 			0x180
#define GPF3DAT_OFFSET 			0x184
#define GPF3PUD_OFFSET 			0x188
#define GPF3DRV_SR_OFFSET 		0x18C
#define GPF3CONPDN_OFFSET 		0x190
#define GPF3PUDPDN_OFFSET 		0x194

#define GPG0CON_OFFSET 			0x1A0
#define GPG0DAT_OFFSET 			0x1A4
#define GPG0PUD_OFFSET 			0x1A8
#define GPG0DRV_SR_OFFSET 		0x1AC
#define GPG0CONPDN_OFFSET 		0x1B0
#define GPG0PUDPDN_OFFSET 		0x1B4

#define GPG1CON_OFFSET 			0x1C0
#define GPG1DAT_OFFSET 			0x1C4
#define GPG1PUD_OFFSET 			0x1C8
#define GPG1DRV_SR_OFFSET 		0x1CC
#define GPG1CONPDN_OFFSET 		0x1D0
#define GPG1PUDPDN_OFFSET 		0x1D4

#define GPG2CON_OFFSET 			0x1E0
#define GPG2DAT_OFFSET 			0x1E4
#define GPG2PUD_OFFSET 			0x1E8
#define GPG2DRV_SR_OFFSET 		0x1EC
#define GPG2CONPDN_OFFSET 		0x1F0
#define GPG2PUDPDN_OFFSET 		0x1F4

#define GPG3CON_OFFSET 			0x200
#define GPG3DAT_OFFSET 			0x204
#define GPG3PUD_OFFSET 			0x208
#define GPG3DRV_SR_OFFSET 		0x20C
#define GPG3CONPDN_OFFSET 		0x210
#define GPG3PUDPDN_OFFSET 		0x214

#define MP1_0DRV_SR_OFFSET 		0x3CC
#define MP1_1DRV_SR_OFFSET 		0x3EC
#define MP1_2DRV_SR_OFFSET 		0x40C
#define MP1_3DRV_SR_OFFSET 		0x42C
#define MP1_4DRV_SR_OFFSET 		0x44C
#define MP1_5DRV_SR_OFFSET 		0x46C
#define MP1_6DRV_SR_OFFSET 		0x48C
#define MP1_7DRV_SR_OFFSET 		0x4AC
#define MP1_8DRV_SR_OFFSET 		0x4CC

#define MP2_0DRV_SR_OFFSET 		0x4EC
#define MP2_1DRV_SR_OFFSET 		0x50C
#define MP2_2DRV_SR_OFFSET 		0x52C
#define MP2_3DRV_SR_OFFSET 		0x54C
#define MP2_4DRV_SR_OFFSET 		0x56C
#define MP2_5DRV_SR_OFFSET 		0x58C
#define MP2_6DRV_SR_OFFSET 		0x5AC
#define MP2_7DRV_SR_OFFSET 		0x5CC
#define MP2_8DRV_SR_OFFSET 		0x5EC

/* GPH0 */
#define GPH0CON_OFFSET			0xc00
#define GPH0DAT_OFFSET			0xc04
#define GPH0PUD_OFFSET			0xc08
#define GPH0DRV_OFFSET			0xc0c

/* GPH1 */
#define GPH1CON_OFFSET			0xc20
#define GPH1DAT_OFFSET			0xc24
#define GPH1PUD_OFFSET			0xc28
#define GPH1DRV_OFFSET			0xc2c

/* GPH2 */
#define GPH2CON_OFFSET			0xc40
#define GPH2DAT_OFFSET			0xc44
#define GPH2PUD_OFFSET			0xc48
#define GPH2DRV_OFFSET			0xc4c

/* GPH3 */
#define GPH3CON_OFFSET			0xc60
#define GPH3DAT_OFFSET			0xc64
#define GPH3PUD_OFFSET			0xc68
#define GPH3DRV_OFFSET			0xc6c


#define GPICON_OFFSET 			0x220
#define GPIPUD_OFFSET 			0x228
#define GPIDRV_OFFSET_SR 		0x22C
#define GPIPUDPDN_OFFSET 		0x234

#define GPJ0CON_OFFSET 			0x240
#define GPJ0DAT_OFFSET 			0x244
#define GPJ0PUD_OFFSET 			0x248
#define GPJ0DRV_SR_OFFSET 		0x24C
#define GPJ0CONPDN_OFFSET 		0x250
#define GPJ0PUDPDN_OFFSET 		0x254

#define GPJ1CON_OFFSET 			0x260
#define GPJ1DAT_OFFSET 			0x264
#define GPJ1PUD_OFFSET 			0x268
#define GPJ1DRV_SR_OFFSET 		0x26C
#define GPJ1CONPDN_OFFSET 		0x270
#define GPJ1PUDPDN_OFFSET 		0x274

#define GPJ2CON_OFFSET 			0x280
#define GPJ2DAT_OFFSET 			0x284
#define GPJ2PUD_OFFSET 			0x288
#define GPJ2DRV_SR_OFFSET 		0x28C
#define GPJ2CONPDN_OFFSET 		0x290
#define GPJ2PUDPDN_OFFSET 		0x294

#define GPJ3CON_OFFSET 			0x2A0
#define GPJ3DAT_OFFSET 			0x2A4
#define GPJ3PUD_OFFSET 			0x2A8
#define GPJ3DRV_SR_OFFSET 		0x2AC
#define GPJ3CONPDN_OFFSET 		0x2B0
#define GPJ3PUDPDN_OFFSET 		0x2B4

#define GPJ4CON_OFFSET 			0x2C0
#define GPJ4DAT_OFFSET 			0x2C4
#define GPJ4PUD_OFFSET 			0x2C8
#define GPJ4DRV_SR_OFFSET 		0x2CC
#define GPJ4CONPDN_OFFSET 		0x2D0
#define GPJ4PUDPDN_OFFSET 		0x2D4

#define  rGPJ2CON		__REG_V(ELFIN_GPIO_BASE + GPJ2CON_OFFSET)
#define  rGPJ2DAT		__REG_V(ELFIN_GPIO_BASE + GPJ2DAT_OFFSET)

/*
 * Interrupt
 */
#define ELFIN_VIC0_BASE_ADDR		(0xF2000000)
#define ELFIN_VIC1_BASE_ADDR		(0xF2100000)
#define ELFIN_VIC2_BASE_ADDR		(0xF2200000)
#define ELFIN_VIC3_BASE_ADDR		(0xF2300000)

#define ELFIN_TZIC0_BASE_ADDR		(0xF2800000)
#define ELFIN_TZIC1_BASE_ADDR		(0xF2900000)
#define ELFIN_TZIC2_BASE_ADDR		(0xF2A00000)

#define oINTMOD				(0x0C)		// VIC INT SELECT (IRQ or FIQ)
#define oINTUNMSK			(0x10)		// VIC INT EN (Unmask by writing 1)
#define oINTMSK				(0x14)		// VIC INT EN CLEAR (Mask by writing 1)
#define oINTSUBMSK			(0x1C)		// VIC SOFT INT CLEAR
#define oVECTADDR			(0xF00)		// VIC ADDRESS

/*
 * Watchdog timer
 */
#define ELFIN_WATCHDOG_BASE		0xE2700000

#define WTCON_OFFSET			0x00
#define WTDAT_OFFSET			0x08
#define WTCNT_OFFSET			0x0C

#define WTCON_REG			__REG(ELFIN_WATCHDOG_BASE+WTCON_OFFSET)
#define WTDAT_REG			__REG(ELFIN_WATCHDOG_BASE+WTDAT_OFFSET)
#define WTCNT_REG			__REG(ELFIN_WATCHDOG_BASE+WTCNT_OFFSET)

/*
 * UART
 */
#define ELFIN_UART_BASE			0XE2900000

#define ELFIN_UART0_OFFSET		0x0000
#define ELFIN_UART1_OFFSET		0x0400
#define ELFIN_UART2_OFFSET		0x0800
#define ELFIN_UART3_OFFSET		0x0c00

#if defined(CONFIG_SERIAL0)
#define ELFIN_UART_CONSOLE_BASE (ELFIN_UART_BASE + ELFIN_UART0_OFFSET)
#elif defined(CONFIG_SERIAL1)
#define ELFIN_UART_CONSOLE_BASE (ELFIN_UART_BASE + ELFIN_UART1_OFFSET)
#elif defined(CONFIG_SERIAL2)
#define ELFIN_UART_CONSOLE_BASE (ELFIN_UART_BASE + ELFIN_UART2_OFFSET)
#elif defined(CONFIG_SERIAL3)
#define ELFIN_UART_CONSOLE_BASE (ELFIN_UART_BASE + ELFIN_UART3_OFFSET)
#else
#define ELFIN_UART_CONSOLE_BASE (ELFIN_UART_BASE + ELFIN_UART0_OFFSET)
#endif

#define ULCON_OFFSET			0x00
#define UCON_OFFSET			0x04
#define UFCON_OFFSET			0x08
#define UMCON_OFFSET			0x0C
#define UTRSTAT_OFFSET			0x10
#define UERSTAT_OFFSET			0x14
#define UFSTAT_OFFSET			0x18
#define UMSTAT_OFFSET			0x1C
#define UTXH_OFFSET			0x20
#define URXH_OFFSET			0x24
#define UBRDIV_OFFSET			0x28
#define UDIVSLOT_OFFSET			0x2C
#define UINTP_OFFSET			0x30
#define UINTSP_OFFSET			0x34
#define UINTM_OFFSET			0x38

#define UTRSTAT_TX_EMPTY		BIT2
#define UTRSTAT_RX_READY		BIT0
#define UART_ERR_MASK			0xF


/*
 * PWM timer
 */
#define ELFIN_TIMER_BASE		0xE2500000

#define rTCFG0			__REG_V(0xE2500000)
#define rTCFG1			__REG_V(0xE2500004)
#define rTCON			__REG_V(0xE2500008)
#define rTCNTB0			__REG_V(0xE250000c)
#define rTCMPB0			__REG_V(0xE2500010)
#define rTCNTO0			__REG_V(0xE2500014)
#define rTCNTB1			__REG_V(0xE2500018)
#define rTCMPB1			__REG_V(0xE250001c)
#define rTCNTO1			__REG_V(0xE2500020)
#define rTCNTB2			__REG_V(0xE2500024)
#define rTCMPB2			__REG_V(0xE2500028)
#define rTCNTO2			__REG_V(0xE250002c)
#define rTCNTB3			__REG_V(0xE2500030)
#define rTCMPB3			__REG_V(0xE2500034)
#define rTCNTO3			__REG_V(0xE2500038)
#define rTCNTB4			__REG_V(0xE250003c)
#define rTCNTO4			__REG_V(0xE2500040)
#define rTINT_CSTAT		__REG_V(0xE2500044)

/* Fields */
#define fTCFG0_DZONE		Fld(8,16)       /* the dead zone length (= timer 0) */
#define fTCFG0_PRE1			Fld(8,8)        /* prescaler value for time 2,3,4 */
#define fTCFG0_PRE0			Fld(8,0)        /* prescaler value for time 0,1 */
#define fTCFG1_MUX4			Fld(4,16)
/* bits */
#define TCFG0_DZONE(x)			FInsrt((x), fTCFG0_DZONE)
#define TCFG0_PRE1(x)			FInsrt((x), fTCFG0_PRE1)
#define TCFG0_PRE0(x)			FInsrt((x), fTCFG0_PRE0)
#define TCON_4_AUTO			(1 << 22)       /* auto reload on/off for Timer 4 */
#define TCON_4_UPDATE			(1 << 21)       /* manual Update TCNTB4 */
#define TCON_4_ONOFF			(1 << 20)       /* 0: Stop, 1: start Timer 4 */
#define COUNT_4_ON			(TCON_4_ONOFF*1)
#define COUNT_4_OFF			(TCON_4_ONOFF*0)
#define TCON_3_AUTO			(1 << 19)       /* auto reload on/off for Timer 3 */
#define TIMER3_ATLOAD_ON		(TCON_3_AUTO*1)
#define TIMER3_ATLAOD_OFF		FClrBit(TCON, TCON_3_AUTO)
#define TCON_3_INVERT			(1 << 18)       /* 1: Inverter on for TOUT3 */
#define TIMER3_IVT_ON			(TCON_3_INVERT*1)
#define TIMER3_IVT_OFF			(FClrBit(TCON, TCON_3_INVERT))
#define TCON_3_MAN			(1 << 17)       /* manual Update TCNTB3,TCMPB3 */
#define TIMER3_MANUP			(TCON_3_MAN*1)
#define TIMER3_NOP			(FClrBit(TCON, TCON_3_MAN))
#define TCON_3_ONOFF			(1 << 16)       /* 0: Stop, 1: start Timer 3 */
#define TIMER3_ON			(TCON_3_ONOFF*1)
#define TIMER3_OFF			(FClrBit(TCON, TCON_3_ONOFF))

/* macros */
#define GET_PRESCALE_TIMER4(x)		FExtr((x), fTCFG0_PRE1)
#define GET_DIVIDER_TIMER4(x)		FExtr((x), fTCFG1_MUX4)


#define MP01CON_OFFSET 			0x2E0
#define MP01DAT_OFFSET 			0x2E4
#define MP01PUD_OFFSET 			0x2E8
#define MP01DRV_SR_OFFSET 		0x2EC
#define MP01CONPDN_OFFSET 		0x2E0
#define MP01PUDPDN_OFFSET 		0x2E4

#define MP02CON_OFFSET                  0x300
#define MP02DAT_OFFSET                  0x304
#define MP02PUD_OFFSET                  0x308
#define MP02DRV_SR_OFFSET               0x30c
#define MP02CONPDN_OFFSET               0x310
#define MP02PUDPDN_OFFSET               0x314

#define MP03CON_OFFSET                  0x320
#define MP03DAT_OFFSET                  0x324
#define MP03PUD_OFFSET                  0x328
#define MP03DRV_SR_OFFSET               0x32c
#define MP03CONPDN_OFFSET               0x330
#define MP03PUDPDN_OFFSET               0x334

#define MP06CON_OFFSET                  0x380
#define MP06DAT_OFFSET                  0x384
#define MP06PUD_OFFSET                  0x388
#define MP06DRV_SR_OFFSET               0x38C
#define MP06CONPDN_OFFSET               0x390
#define MP06PUDPDN_OFFSET               0x394

#define MP07CON_OFFSET                  0x3A0
#define MP07DAT_OFFSET                  0x3A4
#define MP07PUD_OFFSET                  0x3A8
#define MP07DRV_SR_OFFSET               0x3AC
#define MP07CONPDN_OFFSET               0x3B0
#define MP07PUDPDN_OFFSET               0x3B4

/*
 * RTC
 */
#define RTC_BASE		(0xE2800000)

#define	 rINTP      		( *((volatile unsigned long *)(RTC_BASE + 0x30)) )
#define	 rRTCCON    	( *((volatile unsigned long *)(RTC_BASE + 0x40)) )
#define	 rTICCNT    	( *((volatile unsigned long *)(RTC_BASE + 0x44)) )
#define	 rRTCALM    	( *((volatile unsigned long *)(RTC_BASE + 0x50)) )
#define	 rALMSEC    	( *((volatile unsigned long *)(RTC_BASE + 0x54)) )
#define	 rALMMIN    	( *((volatile unsigned long *)(RTC_BASE + 0x58)) )
#define	 rALMHOUR  	( *((volatile unsigned long *)(RTC_BASE + 0x5c)) )
#define	 rALMDATE    	( *((volatile unsigned long *)(RTC_BASE + 0x60)) )
#define	 rALMMON    	( *((volatile unsigned long *)(RTC_BASE + 0x64)) )
#define	 rALMYEAR  	( *((volatile unsigned long *)(RTC_BASE + 0x68)) )
#define	 rRTCRST     	( *((volatile unsigned long *)(RTC_BASE + 0x6c)) )
#define	 rBCDSEC    	( *((volatile unsigned long *)(RTC_BASE + 0x70)) )
#define	 rBCDMIN   	( *((volatile unsigned long *)(RTC_BASE + 0x74)) )
#define	 rBCDHOUR 	( *((volatile unsigned long *)(RTC_BASE + 0x78)) )
#define	 rBCDDATE    ( *((volatile unsigned long *)(RTC_BASE + 0x7c)) )
#define	 rBCDDAY     	( *((volatile unsigned long *)(RTC_BASE + 0x80)) )
#define	 rBCDMON     ( *((volatile unsigned long *)(RTC_BASE + 0x84)) )
#define	 rBCDYEAR    ( *((volatile unsigned long *)(RTC_BASE + 0x88)) )
#define	 rCURTICCNT 	( *((volatile unsigned long *)(RTC_BASE + 0x90)) )
#define	 rRTCLVD   	( *((volatile unsigned long *)(RTC_BASE + 0x94)) )

/*
 * Nand flash controller
 */
#define ELFIN_NAND_BASE			0xB0E00000
#define ELFIN_NAND_ECC_BASE		0xB0E20000

#define NFCONF_OFFSET           	0x00
#define NFCONT_OFFSET           	0x04
#define NFCMMD_OFFSET           	0x08
#define NFADDR_OFFSET           	0x0c
#define NFDATA_OFFSET			0x10
#define NFMECCDATA0_OFFSET      	0x14
#define NFMECCDATA1_OFFSET      	0x18
#define NFSECCDATA0_OFFSET      	0x1c
#define NFSBLK_OFFSET           	0x20
#define NFEBLK_OFFSET           	0x24
#define NFSTAT_OFFSET           	0x28
#define NFESTAT0_OFFSET         	0x2c
#define NFESTAT1_OFFSET         	0x30
#define NFMECC0_OFFSET          	0x34
#define NFMECC1_OFFSET          	0x38
#define NFSECC_OFFSET           	0x3c
#define NFMLCBITPT_OFFSET       	0x40
#define NFECCCONF_OFFSET 		0x000 // R/W ECC configuration register 0x0000_0000
#define NFECCCONT_OFFSET 		0x020 // R/W ECC control register 0x0000_0000
#define NFECCSTAT_OFFSET 		0x030 // R ECC status register 0x0000_0000
#define NFECCSECSTAT_OFFSET 		0x040 // R ECC sector status register 0x0000_0000
#define NFECCPRGECC0_OFFSET 		0x090 // R ECC parity code0 register for page program 0x0000_0000
#define NFECCPRGECC1_OFFSET 		0x094 // R ECC parity code1 register for page program 0x0000_0000
#define NFECCPRGECC2_OFFSET 		0x098 // R ECC parity code2 register for page program 0x0000_0000
#define NFECCPRGECC3_OFFSET 		0x09C // R ECC parity code3 register for page program 0x0000_0000
#define NFECCPRGECC4_OFFSET 		0x0A0 // R ECC parity code4 register for page program 0x0000_0000
#define NFECCPRGECC5_OFFSET 		0x0A4 // R ECC parity code5 register for page program 0x0000_0000
#define NFECCPRGECC6_OFFSET 		0x0A8 // R ECC parity code6 register for page program 0x0000_0000
#define NFECCERL0_OFFSET		0x0C0 // R ECC error byte location0 register 0x0000_0000
#define NFECCERL1_OFFSET		0x0C4 // R ECC error byte location1 register 0x0000_0000
#define NFECCERL2_OFFSET		0x0C8 // R ECC error byte location2 register 0x0000_0000
#define NFECCERL3_OFFSET 		0x0CC // R ECC error byte location3 register 0x0000_0000
#define NFECCERL4_OFFSET 		0x0D0 // R ECC error byte location4 register 0x0000_0000
#define NFECCERL5_OFFSET 		0x0D4 // R ECC error byte location5 register 0x0000_0000
#define NFECCERL6_OFFSET 		0x0D8 // R ECC error byte location6 register 0x0000_0000
#define NFECCERL7_OFFSET 		0x0DC // R ECC error byte location7 register 0x0000_0000
#define NFECCERP0_OFFSET 		0x0F0 // R ECC error bit pattern0 register 0x0000_0000
#define NFECCERP1_OFFSET 		0x0F4 // R ECC error bit pattern1 register 0x0000_0000
#define NFECCERP2_OFFSET 		0x0F8 // R ECC error bit pattern2 register 0x0000_0000
#define NFECCERP3_OFFSET 		0x0FC // R ECC error bit pattern3 register 0x0000_0000
#define NFECCCONECC0_OFFSET 		0x110 // R/W ECC parity conversion code0 register 0x0000_0000
#define NFECCCONECC1_OFFSET 		0x114 // R/W ECC parity conversion code1 register 0x0000_0000
#define NFECCCONECC2_OFFSET 		0x118 // R/W ECC parity conversion code2 register 0x0000_0000
#define NFECCCONECC3_OFFSET 		0x11C // R/W ECC parity conversion code3 register 0x0000_0000
#define NFECCCONECC4_OFFSET 		0x120 // R/W ECC parity conversion code4 register 0x0000_0000
#define NFECCCONECC5_OFFSET 		0x124 // R/W ECC parity conversion code5 register 0x0000_0000
#define NFECCCONECC6_OFFSET		0x128 // R/W ECC parity conversion code6 register 0x0000_0000

#define NFCONF				(ELFIN_NAND_BASE+NFCONF_OFFSET)
#define NFCONT				(ELFIN_NAND_BASE+NFCONT_OFFSET)
#define NFCMMD				(ELFIN_NAND_BASE+NFCMMD_OFFSET)
#define NFADDR           		(ELFIN_NAND_BASE+NFADDR_OFFSET)
#define NFDATA          		(ELFIN_NAND_BASE+NFDATA_OFFSET)
#define NFMECCDATA0     		(ELFIN_NAND_BASE+NFMECCDATA0_OFFSET)
#define NFMECCDATA1     		(ELFIN_NAND_BASE+NFMECCDATA1_OFFSET)
#define NFSECCDATA0      		(ELFIN_NAND_BASE+NFSECCDATA0_OFFSET)
#define NFSBLK          		(ELFIN_NAND_BASE+NFSBLK_OFFSET)
#define NFEBLK           		(ELFIN_NAND_BASE+NFEBLK_OFFSET)
#define NFSTAT           		(ELFIN_NAND_BASE+NFSTAT_OFFSET)
#define NFESTAT0         		(ELFIN_NAND_BASE+NFESTAT0_OFFSET)
#define NFESTAT1         		(ELFIN_NAND_BASE+NFESTAT1_OFFSET)
#define NFMECC0          		(ELFIN_NAND_BASE+NFMECC0_OFFSET)
#define NFMECC1          		(ELFIN_NAND_BASE+NFMECC1_OFFSET)
#define NFSECC           		(ELFIN_NAND_BASE+NFSECC_OFFSET)
#define NFMLCBITPT           		(ELFIN_NAND_BASE+NFMLCBITPT_OFFSET)

#define NFECCCONF			(ELFIN_NAND_ECC_BASE+NFECCCONF_OFFSET)
#define NFECCCONT			(ELFIN_NAND_ECC_BASE+NFECCCONT_OFFSET)
#define NFECCSTAT			(ELFIN_NAND_ECC_BASE+NFECCSTAT_OFFSET)
#define NFECCSECSTAT			(ELFIN_NAND_ECC_BASE+NFECCSECSTAT_OFFSET)
#define NFECCPRGECC0			(ELFIN_NAND_ECC_BASE+NFECCPRGECC0_OFFSET)
#define NFECCPRGECC1			(ELFIN_NAND_ECC_BASE+NFECCPRGECC1_OFFSET)
#define NFECCPRGECC2			(ELFIN_NAND_ECC_BASE+NFECCPRGECC2_OFFSET)
#define NFECCPRGECC3			(ELFIN_NAND_ECC_BASE+NFECCPRGECC3_OFFSET)
#define NFECCPRGECC4			(ELFIN_NAND_ECC_BASE+NFECCPRGECC4_OFFSET)
#define NFECCPRGECC5			(ELFIN_NAND_ECC_BASE+NFECCPRGECC5_OFFSET)
#define NFECCPRGECC6			(ELFIN_NAND_ECC_BASE+NFECCPRGECC6_OFFSET)
#define NFECCERL0			(ELFIN_NAND_ECC_BASE+NFECCERL0_OFFSET)
#define NFECCERL1			(ELFIN_NAND_ECC_BASE+NFECCERL1_OFFSET)
#define NFECCERL2			(ELFIN_NAND_ECC_BASE+NFECCERL2_OFFSET)
#define NFECCERL3			(ELFIN_NAND_ECC_BASE+NFECCERL3_OFFSET)
#define NFECCERL4			(ELFIN_NAND_ECC_BASE+NFECCERL4_OFFSET)
#define NFECCERL5			(ELFIN_NAND_ECC_BASE+NFECCERL5_OFFSET)
#define NFECCERL6			(ELFIN_NAND_ECC_BASE+NFECCERL6_OFFSET)
#define NFECCERL7			(ELFIN_NAND_ECC_BASE+NFECCERL7_OFFSET)
#define NFECCERP0			(ELFIN_NAND_ECC_BASE+NFECCERP0_OFFSET)
#define NFECCERP1			(ELFIN_NAND_ECC_BASE+NFECCERP1_OFFSET)
#define NFECCERP2			(ELFIN_NAND_ECC_BASE+NFECCERP2_OFFSET)
#define NFECCERP3			(ELFIN_NAND_ECC_BASE+NFECCERP3_OFFSET)
#define NFECCCONECC0			(ELFIN_NAND_ECC_BASE+NFECCCONECC0_OFFSET)
#define NFECCCONECC1			(ELFIN_NAND_ECC_BASE+NFECCCONECC1_OFFSET)
#define NFECCCONECC2			(ELFIN_NAND_ECC_BASE+NFECCCONECC2_OFFSET)
#define NFECCCONECC3			(ELFIN_NAND_ECC_BASE+NFECCCONECC3_OFFSET)
#define NFECCCONECC4			(ELFIN_NAND_ECC_BASE+NFECCCONECC4_OFFSET)
#define NFECCCONECC5			(ELFIN_NAND_ECC_BASE+NFECCCONECC5_OFFSET)
#define NFECCCONECC6			(ELFIN_NAND_ECC_BASE+NFECCCONECC6_OFFSET)


#define NFCONF_REG			__REG(ELFIN_NAND_BASE+NFCONF_OFFSET)
#define NFCONT_REG			__REG(ELFIN_NAND_BASE+NFCONT_OFFSET)
#define NFCMD_REG			__REG(ELFIN_NAND_BASE+NFCMMD_OFFSET)
#define NFADDR_REG           		__REG(ELFIN_NAND_BASE+NFADDR_OFFSET)
#define NFDATA_REG          		__REG(ELFIN_NAND_BASE+NFDATA_OFFSET)
#define NFDATA8_REG          		__REGb(ELFIN_NAND_BASE+NFDATA_OFFSET)
#define NFMECCDATA0_REG     		__REG(ELFIN_NAND_BASE+NFMECCDATA0_OFFSET)
#define NFMECCDATA1_REG     		__REG(ELFIN_NAND_BASE+NFMECCDATA1_OFFSET)
#define NFSECCDATA0_REG      		__REG(ELFIN_NAND_BASE+NFSECCDATA0_OFFSET)
#define NFSBLK_REG          		__REG(ELFIN_NAND_BASE+NFSBLK_OFFSET)
#define NFEBLK_REG           		__REG(ELFIN_NAND_BASE+NFEBLK_OFFSET)
#define NFSTAT_REG           		__REG(ELFIN_NAND_BASE+NFSTAT_OFFSET)
#define NFESTAT0_REG         		__REG(ELFIN_NAND_BASE+NFESTAT0_OFFSET)
#define NFESTAT1_REG         		__REG(ELFIN_NAND_BASE+NFESTAT1_OFFSET)
#define NFMECC0_REG          		__REG(ELFIN_NAND_BASE+NFMECC0_OFFSET)
#define NFMECC1_REG          		__REG(ELFIN_NAND_BASE+NFMECC1_OFFSET)
#define NFSECC_REG           		__REG(ELFIN_NAND_BASE+NFSECC_OFFSET)
#define NFMLCBITPT_REG         		__REG(ELFIN_NAND_BASE+NFMLCBITPT_OFFSET)

#define NFCONF_ECC_MLC			(1<<24)

#define NFCONF_ECC_1BIT			(0<<23)
#define NFCONF_ECC_4BIT			(2<<23)
#define NFCONF_ECC_8BIT			(1<<23)

#define NFCONT_ECC_ENC			(1<<18)
#define NFCONT_WP			(1<<16)
#define NFCONT_MECCLOCK			(1<<7)
#define NFCONT_SECCLOCK			(1<<6)
#define NFCONT_INITMECC			(1<<5)
#define NFCONT_INITSECC			(1<<4)
#define NFCONT_INITECC			(NFCONT_INITMECC | NFCONT_INITSECC)
#define NFCONT_CS			(1<<1)
#define NFSTAT_ECCENCDONE		(1<<25)
#define NFSTAT_ECCDECDONE		(1<<24)
#define NFSTAT_RnB			(1<<0)
#define NFESTAT0_ECCBUSY		(1<<31)


/* Access Controller (TZPC) */
#define TZPC_DECPROT0SET_OFFSET		0x804
#define TZPC_DECPROT1SET_OFFSET		0x810
#define TZPC_DECPROT2SET_OFFSET		0x81C
#define TZPC_DECPROT3SET_OFFSET		0x828


/*************************************************************
 * OneNAND Controller
 *************************************************************/
#define ELFIN_ONENAND_BASE		0xB0000000
#define ELFIN_ONENANDCON_BASE		(ELFIN_ONENAND_BASE + 0x600000)

#define ONENAND_IF_CTRL_OFFSET			0x100
#define ONENAND_IF_CMD_OFFSET			0x104
#define ONENAND_IF_ASYNC_TIMING_CTRL_OFFSET	0x108
#define ONENAND_IF_STATUS_OFFSET		0x10C
#define DMA_SRC_ADDR_OFFSET			0x400
#define DMA_SRC_CFG_OFFSET			0x404
#define DMA_DST_ADDR_OFFSET			0x408
#define DMA_DST_CFG_OFFSET			0x40C
#define DMA_TRANS_SIZE_OFFSET			0x414
#define DMA_TRANS_CMD_OFFSET			0x418
#define DMA_TRANS_STATUS_OFFSET			0x41C
#define DMA_TRANS_DIR_OFFSET			0x420
#define SQC_SAO_OFFSET				0x600
#define SQC_CMD_OFFSET				0x608
#define SQC_STATUS_OFFSET			0x60C
#define SQC_CAO_OFFSET				0x610
#define SQC_REG_CTRL_OFFSET			0x614
#define SQC_REG_VAL_OFFSET			0x618
#define SQC_BRPAO0_OFFSET			0x620
#define SQC_BRPAO1_OFFSET			0x624
#define INTC_SQC_CLR_OFFSET			0x1000
#define INTC_DMA_CLR_OFFSET			0x1004
#define INTC_ONENAND_CLR_OFFSET			0x1008
#define INTC_SQC_MASK_OFFSET			0x1020
#define INTC_DMA_MASK_OFFSET			0x1024
#define INTC_ONENAND_MASK_OFFSET		0x1028
#define INTC_SQC_PEND_OFFSET			0x1040
#define INTC_DMA_PEND_OFFSET			0x1044
#define INTC_ONENAND_PEND_OFFSET		0x1048
#define INTC_SQC_STATUS_OFFSET			0x1060
#define INTC_DMA_STATUS_OFFSET			0x1064
#define INTC_ONENAND_STATUS_OFFSET		0x1068

/*
 * Memory controller
 */
#define ELFIN_SROM_BASE			0xE8000000

#define SROM_BW_REG			__REG(ELFIN_SROM_BASE+0x0)
#define SROM_BC0_REG			__REG(ELFIN_SROM_BASE+0x4)
#define SROM_BC1_REG			__REG(ELFIN_SROM_BASE+0x8)
#define SROM_BC2_REG			__REG(ELFIN_SROM_BASE+0xC)
#define SROM_BC3_REG			__REG(ELFIN_SROM_BASE+0x10)
#define SROM_BC4_REG			__REG(ELFIN_SROM_BASE+0x14)
#define SROM_BC5_REG			__REG(ELFIN_SROM_BASE+0x18)

/*
 * SDRAM Controller
 */
#define APB_DMC_0_BASE			0xF0000000
#define APB_DMC_1_BASE			0xF1400000
#define ASYNC_MSYS_DMC0_BASE		0xF1E00000

#define DMC_CONCONTROL 			0x00
#define DMC_MEMCONTROL 			0x04
#define DMC_MEMCONFIG0 			0x08
#define DMC_MEMCONFIG1 			0x0C
#define DMC_DIRECTCMD 			0x10
#define DMC_PRECHCONFIG 		0x14
#define DMC_PHYCONTROL0 		0x18
#define DMC_PHYCONTROL1 		0x1C
#define DMC_RESERVED 			0x20
#define DMC_PWRDNCONFIG 		0x28
#define DMC_TIMINGAREF 			0x30
#define DMC_TIMINGROW 			0x34
#define DMC_TIMINGDATA 			0x38
#define DMC_TIMINGPOWER 		0x3C
#define DMC_PHYSTATUS 			0x40
#define DMC_CHIP0STATUS 		0x48
#define DMC_CHIP1STATUS 		0x4C
#define DMC_AREFSTATUS 			0x50
#define DMC_MRSTATUS 			0x54
#define DMC_PHYTEST0 			0x58
#define DMC_PHYTEST1 			0x5C
#define DMC_QOSCONTROL0 		0x60
#define DMC_QOSCONFIG0 			0x64
#define DMC_QOSCONTROL1 		0x68
#define DMC_QOSCONFIG1 			0x6C
#define DMC_QOSCONTROL2 		0x70
#define DMC_QOSCONFIG2 			0x74
#define DMC_QOSCONTROL3 		0x78
#define DMC_QOSCONFIG3 			0x7C
#define DMC_QOSCONTROL4 		0x80
#define DMC_QOSCONFIG4 			0x84
#define DMC_QOSCONTROL5 		0x88
#define DMC_QOSCONFIG5 			0x8C
#define DMC_QOSCONTROL6 		0x90
#define DMC_QOSCONFIG6 			0x94
#define DMC_QOSCONTROL7 		0x98
#define DMC_QOSCONFIG7 			0x9C
#define DMC_QOSCONTROL8 		0xA0
#define DMC_QOSCONFIG8 			0xA4
#define DMC_QOSCONTROL9 		0xA8
#define DMC_QOSCONFIG9 			0xAC
#define DMC_QOSCONTROL10 		0xB0
#define DMC_QOSCONFIG10 		0xB4
#define DMC_QOSCONTROL11 		0xB8
#define DMC_QOSCONFIG11 		0xBC
#define DMC_QOSCONTROL12 		0xC0
#define DMC_QOSCONFIG12 		0xC4
#define DMC_QOSCONTROL13 		0xC8
#define DMC_QOSCONFIG13 		0xCC
#define DMC_QOSCONTROL14 		0xD0
#define DMC_QOSCONFIG14 		0xD4
#define DMC_QOSCONTROL15 		0xD8
#define DMC_QOSCONFIG15 		0xDC

/*
 * Vectored Interrupt Controller
 */
 
//INT NUM - VIC0
#define NUM_EINT0				(0)
#define NUM_EINT1				(1)
#define NUM_EINT2				(2)
#define NUM_EINT3				(3)
#define NUM_EINT4				(4)
#define NUM_EINT5				(5)
#define NUM_EINT6				(6)
#define NUM_EINT7				(7)
#define NUM_EINT8				(8)
#define NUM_EINT9				(9)
#define NUM_EINT10				(10)
#define NUM_EINT11				(11)
#define NUM_EINT12				(12)
#define NUM_EINT13				(13)
#define NUM_EINT14				(14)
#define NUM_EINT15				(15)
#define NUM_EINT16_31			(16)
#define NUM_Reserved17			(17) 
#define NUM_MDMA				(18)
#define NUM_PDMA0				(19)
#define NUM_PDMA1				(20)
#define NUM_TIMER0				(21)
#define NUM_TIMER1				(22)
#define NUM_TIMER2				(23)
#define NUM_TIMER3				(24)
#define NUM_TIMER4				(25)
#define NUM_SYSTIMER			(26)
#define NUM_WDT					(27)
#define NUM_RTC_ALARM			(28)
#define NUM_RTC_TICK			(29)
#define NUM_GPIOINT				(30)
#define NUM_FIMC3				(31)

//INT NUM - VIC1
#define NUM_CORTEX0				(32+0)
#define NUM_CORTEX1				(32+1)
#define NUM_CORTEX2				(32+2)
#define NUM_CORTEX3				(32+3)
#define NUM_CORTEX4				(32+4)
#define NUM_IEM_APC				(32+5)
#define NUM_IEM_IEC				(32+6)
#define NUM_Reserved39			(32+7)
#define NUM_NFC					(32+8)
#define NUM_CFC					(32+9)
#define NUM_UART0				(32+10)
#define NUM_UART1				(32+11)
#define NUM_UART2				(32+12)
#define NUM_UART3				(32+13)
#define NUM_I2C					(32+14)
#define NUM_SPI0				(32+15)
#define NUM_SPI1				(32+16)
#define NUM_SPI2				(32+17)
#define NUM_AUDIO				(32+18)
#define NUM_I2C_PMIC			(32+19)
#define NUM_I2C_HDMI			(32+20)
#define NUM_HSIRX				(32+21)
#define NUM_HSITX				(32+22)
#define NUM_UHOST				(32+23)
#define NUM_OTG					(32+24)
#define NUM_MSM					(32+25)
#define NUM_HSMMC0				(32+26)
#define NUM_HSMMC1				(32+27)
#define NUM_HSMMC2				(32+28)
#define NUM_MIPI_CSI			(32+29)
#define NUM_MIPI_DSI			(32+30)
#define NUM_ONENAND_AUDI		(32+31)

//INT NUM - VIC2
#define NUM_LCD0				(64+0)
#define NUM_LCD1				(64+1)
#define NUM_LCD2				(64+2)
#define NUM_LCD3				(64+3)
#define NUM_ROTATOR				(64+4)
#define NUM_FIMC_A				(64+5)
#define NUM_FIMC_B				(64+6)
#define NUM_FIMC_C				(64+7)
#define NUM_JPEG				(64+8)
#define NUM_2D					(64+9)
#define NUM_3D					(64+10)
#define NUM_MIXER				(64+11)
#define NUM_HDMI				(64+12)
#define NUM_HDMI_I2C			(64+13)
#define NUM_MFC					(64+14)
#define NUM_TVENC				(64+15)
#define NUM_I2S0				(64+16)
#define NUM_I2S1				(64+17)
#define NUM_I2S2				(64+18)
#define NUM_AC97				(64+19)
#define NUM_PCM0				(64+20)
#define NUM_PCM1				(64+21)
#define NUM_SPDIF				(64+22)
#define NUM_ADC 				(64+23)
#define NUM_PENDN				(64+24)
#define NUM_KEYPAD				(64+25)
#define NUM_Reserved90			(64+26) 
#define NUM_HASH				(64+27) 
#define NUM_FEEDCTRL			(64+28) 
#define NUM_PCM2				(64+29)
#define NUM_SDM_IRQ				(64+30)
#define NUM_SMD_FIQ				(64+31)

//INT NUM - VIC3
#define NUM_IPC					(96+0)
#define NUM_HOSTIF				(96+1)
#define NUM_HSMMC3				(96+2)
#define NUM_CEC					(96+3)
#define NUM_TSI					(96+4)
#define NUM_MDNIE0				(96+5)
#define NUM_MDNIE1				(96+6)
#define NUM_MDNIE2				(96+7)
#define NUM_MDNIE3				(96+8)
#define NUM_ADC1				(96+9)
#define NUM_PENDN1				(96+10)
#define NUM_ALL					(200)

#define VIC0_BASE					(0xF2000000)
#define VIC1_BASE					(0xF2100000)
#define VIC2_BASE					(0xF2200000)
#define VIC3_BASE					(0xF2300000)

// VIC0
#define VIC0IRQSTATUS			__REG(VIC0_BASE + 0x00)
#define VIC0FIQSTATUS			__REG(VIC0_BASE + 0x04)
#define VIC0RAWINTR			__REG(VIC0_BASE + 0x08)
#define VIC0INTSELECT			__REG(VIC0_BASE + 0x0c)
#define VIC0INTENABLE			__REG(VIC0_BASE + 0x10)
#define VIC0INTENCLEAR		__REG(VIC0_BASE + 0x14)
#define VIC0SOFTINT				__REG(VIC0_BASE + 0x18)
#define VIC0SOFTINTCLEAR	__REG(VIC0_BASE + 0x1c)
#define VIC0PROTECTION		__REG(VIC0_BASE + 0x20)
#define VIC0SWPRIORITYMASK	__REG(VIC0_BASE + 0x24)
#define VIC0PRIORITYDAISY		__REG(VIC0_BASE + 0x28)
#define VIC0VECTADDR(index)		__REG(VIC0_BASE + 0x100 + ((index) << 2))
#define VIC0VECPRIORITY(index)	__REG(VIC0_BASE + 0x200 + ((index) << 2))
#define VIC0ADDR				__REG(VIC0_BASE + 0xf00)
#define VIC0PERID0				__REG(VIC0_BASE + 0xfe0)
#define VIC0PERID1				__REG(VIC0_BASE + 0xfe4)
#define VIC0PERID2				__REG(VIC0_BASE + 0xfe8)
#define VIC0PERID3				__REG(VIC0_BASE + 0xfec)
#define VIC0PCELLID0			__REG(VIC0_BASE + 0xff0)
#define VIC0PCELLID1			__REG(VIC0_BASE + 0xff4)
#define VIC0PCELLID2			__REG(VIC0_BASE + 0xff8)
#define VIC0PCELLID3			__REG(VIC0_BASE + 0xffc)

// VIC1
#define VIC1IRQSTATUS			__REG(VIC1_BASE + 0x00)
#define VIC1FIQSTATUS			__REG(VIC1_BASE + 0x04)
#define VIC1RAWINTR			__REG(VIC1_BASE + 0x08)
#define VIC1INTSELECT			__REG(VIC1_BASE + 0x0c)
#define VIC1INTENABLE			__REG(VIC1_BASE + 0x10)
#define VIC1INTENCLEAR		__REG(VIC1_BASE + 0x14)
#define VIC1SOFTINT				__REG(VIC1_BASE + 0x18)
#define VIC1SOFTINTCLEAR	__REG(VIC1_BASE + 0x1c)
#define VIC1PROTECTION		__REG(VIC1_BASE + 0x20)
#define VIC1SWPRIORITYMASK	__REG(VIC1_BASE + 0x24)
#define VIC1PRIORITYDAISY		__REG(VIC1_BASE + 0x28)
#define VIC1VECTADDR(index)		__REG(VIC1_BASE + 0x100 + ((index) << 2))
#define VIC1VECPRIORITY(index)	__REG(VIC1_BASE + 0x200 + ((index) << 2))
#define VIC1ADDR				__REG(VIC1_BASE + 0xf00)
#define VIC1PERID0				__REG(VIC1_BASE + 0xfe0)
#define VIC1PERID1				__REG(VIC1_BASE + 0xfe4)
#define VIC1PERID2				__REG(VIC1_BASE + 0xfe8)
#define VIC1PERID3				__REG(VIC1_BASE + 0xfec)
#define VIC1PCELLID0			__REG(VIC1_BASE + 0xff0)
#define VIC1PCELLID1			__REG(VIC1_BASE + 0xff4)
#define VIC1PCELLID2			__REG(VIC1_BASE + 0xff8)
#define VIC1PCELLID3			__REG(VIC1_BASE + 0xffc)

// VIC2
#define VIC2IRQSTATUS			__REG(VIC2_BASE + 0x00)
#define VIC2FIQSTATUS			__REG(VIC2_BASE + 0x04)
#define VIC2RAWINTR			__REG(VIC2_BASE + 0x08)
#define VIC2INTSELECT			__REG(VIC2_BASE + 0x0c)
#define VIC2INTENABLE			__REG(VIC2_BASE + 0x10)
#define VIC2INTENCLEAR		__REG(VIC2_BASE + 0x14)
#define VIC2SOFTINT				__REG(VIC2_BASE + 0x18)
#define VIC2SOFTINTCLEAR		__REG(VIC2_BASE + 0x1c)
#define VIC2PROTECTION			__REG(VIC2_BASE + 0x20)
#define VIC2SWPRIORITYMASK	__REG(VIC2_BASE + 0x24)
#define VIC2PRIORITYDAISY		__REG(VIC2_BASE + 0x28)
#define VIC2VECTADDR(index)		__REG(VIC2_BASE + 0x100 + ((index) << 2))
#define VIC2VECPRIORITY(inex)	__REG(VIC2_BASE + 0x200 + ((index) << 2))
#define VIC2ADDR				__REG(VIC2_BASE + 0xf00)
#define VIC2PERID0				__REG(VIC2_BASE + 0xfe0)
#define VIC2PERID1				__REG(VIC2_BASE + 0xfe4)
#define VIC2PERID2				__REG(VIC2_BASE + 0xfe8)
#define VIC2PERID3				__REG(VIC2_BASE + 0xfec)
#define VIC2PCELLID0			__REG(VIC2_BASE + 0xff0)
#define VIC2PCELLID1			__REG(VIC2_BASE + 0xff4)
#define VIC2PCELLID2			__REG(VIC2_BASE + 0xff8)
#define VIC2PCELLID3			__REG(VIC2_BASE + 0xffc)

// VIC3
#define VIC3IRQSTATUS			__REG(VIC3_BASE + 0x00)
#define	VIC3FIQSTATUS		__REG(VIC3_BASE + 0x04)
#define VIC3RAWINTR			__REG(VIC3_BASE + 0x08)
#define VIC3INTSELECT			__REG(VIC3_BASE + 0x0c)
#define VIC3INTENABLE		__REG(VIC3_BASE + 0x10)
#define VIC3INTENCLEAR		__REG(VIC3_BASE + 0x14)
#define VIC3SOFTINT			__REG(VIC3_BASE + 0x18)
#define VIC3SOFTINTCLEAR	__REG(VIC3_BASE + 0x1c)
#define VIC3PROTECTION		__REG(VIC3_BASE + 0x20)
#define VIC3SWPRIORITYMASK	__REG(VIC3_BASE + 0x24)
#define	VIC3PRIORITYDAISY		__REG(VIC3_BASE + 0x28)
#define VIC3VECTADDR(index)		__REG(VIC3_BASE + 0x100 + ((index) << 2))
#define VIC3VECPRIORITY(index)	__REG(VIC3_BASE + 0x200 + ((index) << 2))
#define VIC3ADDR				__REG(VIC3_BASE + 0xf00)
#define VIC3PERID0				__REG(VIC3_BASE + 0xfe0)
#define VIC3PERID1				__REG(VIC3_BASE + 0xfe4)
#define VIC3PERID2				__REG(VIC3_BASE + 0xfe8)
#define VIC3PERID3				__REG(VIC3_BASE + 0xfec)
#define VIC3PCELLID0			__REG(VIC3_BASE + 0xff0)
#define VIC3PCELLID1			__REG(VIC3_BASE + 0xff4)
#define VIC3PCELLID2			__REG(VIC3_BASE + 0xff8)
#define VIC3PCELLID3			__REG(VIC3_BASE + 0xffc)

/*
* Memory Chip direct command
*/

/****************************************************************
 Definitions for memory configuration
 Set memory configuration
	active_chips	 = 1'b0 (1 chip)
	qos_master_chip  = 3'b000(ARID[3:0])
	memory burst	 = 3'b010(burst 4)
	stop_mem_clock	 = 1'b0(disable dynamical stop)
	auto_power_down  = 1'b0(disable auto power-down mode)
	power_down_prd	 = 6'b00_0000(0 cycle for auto power-down)
	ap_bit		 = 1'b0 (bit position of auto-precharge is 10)
	row_bits	 = 3'b010(# row address 13)
	column_bits	 = 3'b010(# column address 10 )

 Set user configuration
	2'b10=SDRAM/mSDRAM, 2'b11=DDR, 2'b01=mDDR

 Set chip select for chip [n]
	 row bank control, bank address 0x3000_0000 ~ 0x37ff_ffff
	 CHIP_[n]_CFG=0x30F8,  30: ADDR[31:24], F8: Mask[31:24]
******************************************************************/

#define INF_REG_BASE			0xE010F000

#define INF_REG0_REG			__REG(INF_REG_BASE+INF_REG0_OFFSET)
#define INF_REG1_REG			__REG(INF_REG_BASE+INF_REG1_OFFSET)
#define INF_REG2_REG			__REG(INF_REG_BASE+INF_REG2_OFFSET)
#define INF_REG3_REG			__REG(INF_REG_BASE+INF_REG3_OFFSET)
#define INF_REG4_REG			__REG(INF_REG_BASE+INF_REG4_OFFSET)
#define INF_REG5_REG			__REG(INF_REG_BASE+INF_REG5_OFFSET)
#define INF_REG6_REG			__REG(INF_REG_BASE+INF_REG6_OFFSET)
#define INF_REG7_REG			__REG(INF_REG_BASE+INF_REG7_OFFSET)

#define NFCONF_VAL	(7<<12)|(7<<8)|(7<<4)|(0<<3)|(0<<2)|(1<<1)|(0<<0)
#define NFCONT_VAL      (0x1<<23)|(0x1<<22)|(0<<18)|(0<<17)|(0<<16)|(0<<10)|(0<<9)|(0<<8)|(0<<7)|(0<<6)|(0x2<<1)|(1<<0)
#define MP03CON_VAL	(1<<29)|(1<<25)|(1<<21)|(1<<17)|(1<<13)|(1<<9)|(1<<5)|(1<<1)

#define ELFIN_TZPC0_BASE		0xF1500000
#define ELFIN_TZPC1_BASE		0xFAD00000
#define ELFIN_TZPC2_BASE		0xE0600000
#define ELFIN_TZPC3_BASE		0xE1C00000


#endif // _SOC_H