#include "algo_math.h"

int gcd_int(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int t = a % b;
        a = b; b = t;
    }
    return a;
}

int lcm_int(int a, int b) {
    if (a == 0 || b == 0) return 0;
    int g = gcd_int(a, b);
    /* предотвращаем лишнее переполнение через деление до умножения,
       но гарантий на INT не даём — это учебная версия */
    return (a / g) * b;
}

int is_prime_int(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i <= n / i; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

int pow_int(int base, int exp) {
    if (exp < 0) return 0; /* вне области — учебная версия */
    int res = 1;
    int b = base;
    int e = exp;
    while (e > 0) {
        if (e & 1) res *= b;
        b *= b;
        e >>= 1;
    }
    return res;
}
