#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// GCD
int64_t gcd(int64_t a, int64_t b) {
    if (b > a) {
        std::swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return gcd(a % b, b);
}

// LCM
int64_t lcm(int64_t a, int64_t b) {
    return (a * b / gcd(a, b));
}

// Fast Power
int64_t fast_power(int64_t a, int64_t b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    int64_t ret = 1;
    if (b & 1) {
        ret = a;
    }
    int64_t x = fast_power(a, b / 2);
    return ret * x * x;
}

// Fast Power Mod
int64_t fast_power_mod(int64_t a, int64_t b, int64_t mod) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a % mod;
    }
    int64_t ret = 1;
    if (b & 1) {
        ret = a % mod;
    }
    int64_t x = fast_power_mod(a, b / 2, mod);
    ret = ret * x * x;
    return ret % mod;
}

// Sieve of Eratosthenes
const int inf = 1e6;
bool prime[inf];
void sieve() {
    fill(prime, prime + inf, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < inf; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j < inf; j += i) {
                prime[j] = false;
            }
        }
    }
}

// Is Prime
bool is_prime(int64_t n) {
    if (n <= 1)
        return false;
    if (n != 2 && n % 2 == 0) {
        return false;
    }
    for (int64_t i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Divisors
vector<int64_t> divisors(int64_t n) {
    vector<int64_t> divisors;
    for (int64_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

// Prime Factors
vector<int64_t> factors(int64_t n) {
    vector<int64_t> factors;
    for (int64_t i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

// Prime Factorization (Map)
map<int64_t, int64_t> prime_factorization1(int64_t n) {
    map<int64_t, int64_t> factor;
    for (int64_t i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int64_t count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            factor[i] += count;
        }
    }
    if (n > 1) {
        factor[n]++;
    }
    return factor;
}

// Prime Factorization (Vector of Pairs)
vector<pair<int64_t, int64_t>> prime_factorization2(int64_t n) {
    vector<pair<int64_t, int64_t>> factor;
    for (int64_t i = 2; i * i <= n; i++) {
        int64_t count = 0;
        while (n % i == 0) {
            count++;
            n /= i;
        }
        if (count)
            factor.push_back({i, count});
    }
    if (n > 1)
        factor.push_back({n, 1});
    return factor;
}

// Sum of First N Natural Numbers
int64_t sum(int64_t n) {
    return (n * (n + 1)) / 2;
}
