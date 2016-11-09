#include "lcg.h"
#include "asymp.h"
#include "twist.h"
#include <stdio.h>

#define N_SAMPLES     1757603
#define KEYBOARD_SIZE      26
#define WORD_WIDTH          3

#define N_BIGRAMS  (KEYBOARD_SIZE*KEYBOARD_SIZE)
#define N_TRIGRAMS (N_BIGRAMS*KEYBOARD_SIZE)

#define EXPECTED_BIGRAM_COUNT  (N_SAMPLES/N_BIGRAMS)
#define EXPECTED_TRIGRAM_COUNT (N_SAMPLES/N_TRIGRAMS)

float
evaluate(uint32_t (*get_rand)(void)) {
	float q3, q2;
	int   c1, c2, c3;
	int   i, z;

	/* Initialize bigram and trigram counts */
	int bigram_count[N_BIGRAMS]   = {0};
	int trigram_count[N_TRIGRAMS] = {0};
	
	/* Generate our first set of random keystrokes */
	c1 = get_rand()%KEYBOARD_SIZE;
	c2 = get_rand()%KEYBOARD_SIZE;
	c3 = get_rand()%KEYBOARD_SIZE;
	
	/* Count bigrams and trigrams */
	for( i=0; i<N_SAMPLES; i++ ) {
		/* Count bigram */
		z = c1 * KEYBOARD_SIZE + c2;
		bigram_count[z]++;

		/* Count trigram */
		z = z * KEYBOARD_SIZE + c3;
		trigram_count[z]++;
		
		/* Remember old keystrokes */
		c1 = c2;
		c2 = c3;

		/* Get next keystroke */
		c3 = get_rand()%KEYBOARD_SIZE;
	}

	/* Initialize pearson quadratic form values */
	q3 = q2 = 0;

  /* Compute pearson quadratic form for bigrams */
	for( i=0; i<N_BIGRAMS; i++ ) {
		z = bigram_count[i] - EXPECTED_BIGRAM_COUNT;
		z *= z;
		q2 += ((float)z)/EXPECTED_BIGRAM_COUNT;
	}
	
	/* Compute pearson quadratic form for trigrams */
	for( i=0; i<N_TRIGRAMS; i++ ) {
		z = trigram_count[i] - EXPECTED_TRIGRAM_COUNT;
		z *= z;
		q3 += ((float)z)/EXPECTED_TRIGRAM_COUNT;
	}

	return ((q3 - q2))/(N_TRIGRAMS-N_BIGRAMS);
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
	printf("Chi-Squared Evaluation Of PRNGs\n\n");
	
	printf("Evaluating LCG   : %f\n", evaluate(&grand_lcg_random));
	printf("Evaluating Asymp : %f\n", evaluate(&grand_asymp_random));
	printf("Evaluating Twist : %f\n", evaluate(&grand_twist_random));

	return 0;
}
