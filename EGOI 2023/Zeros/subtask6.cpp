#include <bits/stdc++.h>
int v = 9;

using namespace std;

bool check(long long a, long long b, long long value) {
    long long value_new = b / value;
    value_new *= value;
    if (a <= value_new) {
        return true;
    }
    return false;
}

long long compute_largest_k(long long a, long long b, long long base) {
    long long value, k, largest_k;
    largest_k = 0;
    value = 1;
    k = 0;
    while (value <= b) {
        value *= base;
        if (value > b) {
            break;
        }
        k++;
        largest_k = check(a, b, value) ? k : largest_k;
    }
    return largest_k;
}

long long solve(long long a, long long b) {
    long long twos, fives;
    twos = compute_largest_k(a, b, 2);
    fives = compute_largest_k(a, b, 5);
    return min(twos, fives);
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}