#include "asymp.h"

static float g_seed = 0;

void
grand_asymp_seed( uint32_t seed ) {
	g_seed = seed;
}

uint32_t
grand_asymp_random( void ) {
	g_seed = 0.5f * ( g_seed - 1/((g_seed != 0)? g_seed : 1) );
	return (uint32_t)g_seed;
}
