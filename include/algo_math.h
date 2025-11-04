#ifndef ALGO_MATH_H
#define ALGO_MATH_H

/* gcd/lcm on ints; lcm(0, x) = 0 */
int gcd_int(int a, int b);
int lcm_int(int a, int b);

/* primality test: 1 if prime, else 0 (n >= 0) */
int is_prime_int(int n);

/* fast power for non-negative exponent; overflow not checked */
int pow_int(int base, int exp);

#endif /* ALGO_MATH_H */