#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, opcion1, opcion2;
    double q;
    cin >> N >> q;
    vector<int> precios(N);
    for (int i = 0; i < N; i++) {
        cin >> precios[i];
    }

    opcion1 = (100 - q) / 100 * (precios[0] + precios[1] + precios[2]);
    opcion2 = (precios[0] + precios[1] + precios[2]) - min(precios[0], min(precios[1], precios[2]));
    cout << min(opcion1, opcion2) << endl;

    return 0;
}