#include "lcg.h"

static uint32_t g_seed = 0;

void
grand_lcg_seed( uint32_t seed ) {
	g_seed = seed;
}

uint32_t
grand_lcg_random( void ) {
	g_seed = (g_seed * GRAND_LCG_A + GRAND_LCG_C) % GRAND_LCG_M;
	return g_seed;
}