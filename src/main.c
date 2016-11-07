#include "twist.h"
#include <stdio.h>
#include <time.h>

#define N_NUMS       10
#define N_CYCLES 100000

int
main( int argc, char *argv[] ) {
	int i,x;
	float counts[N_NUMS] = {0};

	/* Seed the random number generator */	
	grand_twist_seed(time(NULL));

	/* Generate N random numbers and count how often we see each number */
	for(i=0; i<N_CYCLES; i++) {
		x= grand_twist_random()%N_NUMS;
		counts[x]++;
	}

	/* Print distribution of numbers (and pray that it's even) */
	for(i=0; i<N_NUMS; i++) {
		printf("%2d: %.2f%%\n", i, (counts[i])/N_CYCLES);
	}
}

