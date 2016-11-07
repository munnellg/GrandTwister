#ifndef GRAND_TWIST_H_
#define GRAND_TWIST_H_
#include <stdint.h>

#define GRAND_TWIST_W         32 /* Word Size                                */
#define GRAND_TWIST_N        624 /* Degree of recurrence                     */
#define GRAND_TWIST_M        397 /* Middle Word                              */
#define GRAND_TWIST_R         31 /* Separation point of a word 0 <= R <= W-1 */

/* Coefficient of rational normal form twist matrix */
#define GRAND_TWIST_A 0x9908B0DF 

#define GRAND_TWIST_U         11 /* Additional MT tempering bit shift */
#define GRAND_TWIST_D 0xFFFFFFFF /* Additional MT tempering bit mask  */

#define GRAND_TWIST_S          7 /* TGFSR tempering Bit shift */
#define GRAND_TWIST_B 0x9D2C5680 /* TGFSR tempering Bitmask   */

#define GRAND_TWIST_T         15 /* TGFSR tempering Bit shift */
#define GRAND_TWIST_C 0xEFC60000 /* TGFSR tempering Bitmask   */

#define GRAND_TWIST_L         18 /* Additional MT tempering bit shift */

#define GRAND_TWIST_F 0x6C078965 /* Constant used in initialization   */

/* Masks used when twisting */
#define GRAND_TWIST_LOWER_MASK 0x7FFFFFFF
#define GRAND_TWIST_UPPER_MASK 0x80000000

void     grand_twist_seed   ( uint32_t seed );
uint32_t grand_twist_random ( void );

#endif /* GRAND_TWIST_H_ */
