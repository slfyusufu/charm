///////////////////////////////////////////////////////////////////////////////
//	
//	File:	clock.c
//	Description: Make PLL and Clock settings
//	
///////////////////////////////////////////////////////////////////////////////


#define rAPLL_LOCK 			( *((volatile unsigned long *)0xE0100000) )		
#define rMPLL_LOCK 			( *((volatile unsigned long *)0xE0100008) )

#define rAPLL_CON0 			( *((volatile unsigned long *)0xE0100100) )
#define rAPLL_CON1 			( *((volatile unsigned long *)0xE0100104) )
#define rMPLL_CON 			( *((volatile unsigned long *)0xE0100108) )

#define rCLK_SRC0 			( *((volatile unsigned long *)0xE0100200) )
#define rCLK_SRC1 			( *((volatile unsigned long *)0xE0100204) )
#define rCLK_SRC2 			( *((volatile unsigned long *)0xE0100208) )
#define rCLK_SRC3 			( *((volatile unsigned long *)0xE010020c) )
#define rCLK_SRC4 			( *((volatile unsigned long *)0xE0100210) )
#define rCLK_SRC5 			( *((volatile unsigned long *)0xE0100214) )
#define rCLK_SRC6 			( *((volatile unsigned long *)0xE0100218) )
#define rCLK_SRC_MASK0 		( *((volatile unsigned long *)0xE0100280) )
#define rCLK_SRC_MASK1 		( *((volatile unsigned long *)0xE0100284) )

#define rCLK_DIV0 			( *((volatile unsigned long *)0xE0100300) )
#define rCLK_DIV1 			( *((volatile unsigned long *)0xE0100304) )
#define rCLK_DIV2 			( *((volatile unsigned long *)0xE0100308) )
#define rCLK_DIV3 			( *((volatile unsigned long *)0xE010030c) )
#define rCLK_DIV4 			( *((volatile unsigned long *)0xE0100310) )
#define rCLK_DIV5 			( *((volatile unsigned long *)0xE0100314) )
#define rCLK_DIV6 			( *((volatile unsigned long *)0xE0100318) )
#define rCLK_DIV7 			( *((volatile unsigned long *)0xE010031c) )

#define CLK_DIV0_MASK		0x7fffffff

// Values for FIN 24MHz and APLL at 1GHz
#define APLL_MDIV       	0x7d
#define APLL_PDIV       	0x3
#define APLL_SDIV      	 	0x1

// Values for FIN 24MHz and MPLL at 667 MHz
#define MPLL_MDIV			0x29b
#define MPLL_PDIV			0xc
#define MPLL_SDIV			0x1

#define SET_PLL(mdiv, pdiv, sdiv)	(1<<31 | mdiv<<16 | pdiv<<8 | sdiv)
#define APLL_VAL		SET_PLL(APLL_MDIV,APLL_PDIV,APLL_SDIV)
#define MPLL_VAL		SET_PLL(MPLL_MDIV,MPLL_PDIV,MPLL_SDIV)

void _platform_clock_init()
{
	// 1 to set various clock switch, temporarily using a PLL
	rCLK_SRC0 = 0x0;
	
	// 2 Set lock time, use the default value
	// Set the PLL, the clock frequency from Fin upgrade to the target, you need some time, namely lock time
	rAPLL_LOCK = 0x0000ffff;
	rMPLL_LOCK = 0x0000FFFF;					
	
	// 3 Set the division
	rCLK_DIV0 = 0x14131440;

	// 4 to set the PLL
	// FOUT = MDIV * FIN / (PDIV * 2 ^ (SDIV-1)) = 0x7d * 24 / (0x3 * 2 ^ (1-1)) = 1000 MHz
	rAPLL_CON0 = APLL_VAL;
	
	// FOUT = MDIV * FIN / (PDIV * 2 ^ SDIV) = 0x29b * 24 / (0xc * 2 ^ 1) = 667 MHz
	rMPLL_CON  = MPLL_VAL;					

	// Enable all PLLs and select various Muxes
	rCLK_SRC0 = 0x10001111;
}
