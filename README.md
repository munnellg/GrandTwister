# Random Numbers

Investigation of various simple pseudo random number
generators. Written purely for educational purposes.

First PRNG uses an asymptotic chaos function - 0.5(x - 1/x) - to
produce numbers which look random, but a simple examination of the
distribution of values it produces shows that it is quite biased
towards numbers near zero.

Second PRNG is a linear congruential generator of the form
x<sub>n+1</sub>(aX<sub>n</sub>+c). Common enough in the early 90s, it
produces values with an even distribution, but fails a chi-square test
for generating bigrams and trigrams. Essentially, if we look at
patterns produced by the PRNG, no single short pattern should be more
common than any other. e.g. there are only 676 possible bigrams and
17576 trigrams when using 26 characters. In a long enough run of
characters, these should all occur with equal frequency. A chi-squared
test for LCG shows that this is not the case.

Finally we examine the Mersenne Twister algorithm. This is very
popular and (I believe) is the standard PRNG for Python. It passes the
previous two simple tests, but I would like to run a few more just to
demonstrate various properties of PRNGs.
