#include <bits/stdc++.h>

using namespace std;

long long solve(long long a, long long b) {
    long long res = 1;
    for (long long i = a; i <= b; i++) {
        res = res * i / __gcd(res, i);
    }
    long long zeros = 0;
    while (res % 10 == 0) {
        zeros++;
        res /= 10;
    }
    return zeros;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}