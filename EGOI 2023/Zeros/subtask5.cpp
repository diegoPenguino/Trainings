#include <bits/stdc++.h>

using namespace std;

long long solve(long long a, long long b) {
    long long k = 0, pot = 1;
    while (pot <= b) {
        pot *= 5;
        k++;
    }
    return k - 1;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}