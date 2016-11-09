#include "lcg.h"
#include "asymp.h"
#include "twist.h"
#include <stdio.h>

#define N_SAMPLES     0x00200000
#define ALPHABET_SIZE       1024
#define WORD_LENGTH           32

#define N_BIGRAMS     (ALPHABET_SIZE*ALPHABET_SIZE)
#define N_FLAG_INTS   (N_BIGRAMS/WORD_LENGTH)

#define EXPECTED_AVERAGE  141909
#define EXPECTED_VARIANCE    290

float
evaluate(uint32_t (*get_rand)(void)) {
	uint32_t found;
	uint32_t c1, c2, c3;
	uint32_t i, z;

	/* Initialize bigram counts */
	uint32_t bigram_flags[N_FLAG_INTS] = {0};
	
	/* Generate our first set of random keystrokes */
	c1 = get_rand()%ALPHABET_SIZE;
	c2 = get_rand()%ALPHABET_SIZE;
	
	/* Note presence/absence of bigrams */
	for( i=0; i<N_SAMPLES; i++ ) {
		/* Note bigram */
		z = c1 * ALPHABET_SIZE + c2;
		bigram_flags[z/WORD_LENGTH] |= (1 << z%WORD_LENGTH);

		/* Remember old keystroke */
		c1 = c2;

		/* Get next keystroke */
		c2 = get_rand()%ALPHABET_SIZE;
	}

	found = 0;

	/* Count the number of bigrams we found by counting the set bits in
	 * each bin and adding to running total */
	for( i=0; i<N_FLAG_INTS; i++ ) {
		z = bigram_flags[i] - ((bigram_flags[i] >> 1) & 0x55555555);
		z = ( z & 0x33333333) + ( (z>>2) & 0x33333333);
		found += ((( z + (z >> 4)) & 0x0F0F0F0F) * 0x01010101 ) >> 24;
	}

	return ((float)N_BIGRAMS-found-EXPECTED_AVERAGE)/EXPECTED_VARIANCE;
}

int
main( int argc, char *argv[] ) {
	float lcg_result;
	float asymp_result;
	float twist_result;
	float rand_result;
	
	/* Seed the random number generators */	
	grand_lcg_seed(time(NULL));
	grand_asymp_seed(time(NULL));
	grand_twist_seed(time(NULL));
	srand(time(NULL));
	
	printf("OPSO Evaluation Of PRNGs\n\n");
	printf("Evaluating LCG   : %f\n", evaluate(&grand_lcg_random));
	printf("Evaluating Asymp : %f\n", evaluate(&grand_asymp_random));
	printf("Evaluating Twist : %f\n", evaluate(&grand_twist_random));

	return 0;
}
