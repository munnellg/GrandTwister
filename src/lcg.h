#ifndef GRAND_LCG_H_
#define GRAND_LCG_H_
#include <stdint.h>

#define GRAND_LCG_M 0x80000000
#define GRAND_LCG_A 0x41C64E6D
#define GRAND_LCG_C 0x00003039

void     grand_lcg_seed   ( uint32_t seed );
uint32_t grand_lcg_random ( void );

#endif /* GRAND_LCG_H_ */
