all:
	gcc src/distribution.c src/twist.h src/twist.c src/lcg.h src/lcg.c src/asymp.h src/asymp.c -o distribution
	gcc src/chi_squared.c src/twist.h src/twist.c src/lcg.h src/lcg.c src/asymp.h src/asymp.c -o chi_squared
	gcc src/opso.c src/twist.h src/twist.c src/lcg.h src/lcg.c src/asymp.h src/asymp.c -o opso_test
