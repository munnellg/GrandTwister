#include "asymp.h"
#include "lcg.h"
#include "twist.h"
#include <stdio.h>
#include <time.h>

#define N_NUMS       10
#define N_CYCLES 100000

int
main( int argc, char *argv[] ) {
	int i,x;
	float lcg_counts[N_NUMS]   = {0};
	float asymp_counts[N_NUMS] = {0};
	float twist_counts[N_NUMS] = {0};

	/* Seed the random number generators */	
	grand_lcg_seed(time(NULL));
	grand_asymp_seed(time(NULL));
	grand_twist_seed(time(NULL));

	printf("Generating %d random numbers in range [0 %d)\n", N_CYCLES, N_NUMS);

	/* Generate random numbers and count how often we see each number */
	for(i=0; i<N_CYCLES; i++) {
		x = grand_lcg_random()%N_NUMS;
		lcg_counts[x]++;
		
		x = grand_asymp_random()%N_NUMS;
		asymp_counts[x]++;

		x = grand_twist_random()%N_NUMS;
		twist_counts[x]++;
	}

	printf("\nDisplaying value probability distributions for each method\n\n");

	printf("------------------------------------------------------------------------------\n");
	printf("|      ");
	for( i=0; i<N_NUMS; i++ ) {
		printf("|%3d   ", i);
	}
	printf("|\n");
	printf("------------------------------------------------------------------------------\n");
	printf("|%-6s", "LCG");
	for( i=0; i<N_NUMS; i++ ) {
		printf("| %4.2f ", lcg_counts[i]/N_CYCLES);
	}
	printf("|\n");
	
	printf("|%-6s", "Asymp");
	for( i=0; i<N_NUMS; i++ ) {
		printf("| %4.2f ", asymp_counts[i]/N_CYCLES);
	}
	printf("|\n");
	
	printf("|%-6s", "Twist");
	for( i=0; i<N_NUMS; i++ ) {
		printf("| %4.2f ", twist_counts[i]/N_CYCLES);
	}
	printf("|\n");
	printf("------------------------------------------------------------------------------\n");
}

