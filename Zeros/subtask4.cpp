#include <bits/stdc++.h>

using namespace std;

long long multiplicity(long long val, long long divisor) {
    long long mult = 0;
    while (val > 1) {
        if (val % divisor == 0)
            mult++;
        else
            return mult;
        val /= divisor;
    }
    return mult;
}

long long solve(long long a, long long b) {
    long long twos = 0, fives = 0;
    for (long long i = a; i <= b; i++) {
        twos = max(twos, multiplicity(i, 2));
        fives = max(fives, multiplicity(i, 5));
    }
    return min(twos, fives);
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}