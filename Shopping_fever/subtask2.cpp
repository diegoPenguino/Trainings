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

    sort(precios.begin(), precios.end());
    reverse(precios.begin(), precios.end());
    // sort(precios.rbegin(), precios.rend());

    long long costo, minimo, costo_total = 0;

    for (int i = 0; i < N; i += 3) {
        costo = precios[i] + precios[i + 1] + precios[i + 2];
        minimo = min(precios[i], min(precios[i + 1], precios[i + 2]));
        costo_total += (costo - minimo);
    }
    cout << costo_total << endl;
    return 0;
}