#include <bits/stdc++.h>

using namespace std;

long long solve(long long a, long long b) {
    if (b < 5)
        return 0;
    if (b < 25)
        return 1;
    if (b < 125)
        return 2;
    return 3;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}