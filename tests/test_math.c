#include <assert.h>
#include "algo_math.h"

int main(void) {
    /* gcd / lcm */
    assert(gcd_int(12, 18) == 6);
    assert(gcd_int(-12, 18) == 6);
    assert(lcm_int(12, 18) == 36);
    assert(lcm_int(0, 5) == 0);

    /* pow */
    assert(pow_int(2, 10) == 1024);
    assert(pow_int(5, 0) == 1);
    assert(pow_int(3, 1) == 3);

    /* primality */
    assert(is_prime_int(2) == 1);
    assert(is_prime_int(3) == 1);
    assert(is_prime_int(17) == 1);
    assert(is_prime_int(1) == 0);
    assert(is_prime_int(0) == 0);
    assert(is_prime_int(12) == 0);

    return 0;
}
