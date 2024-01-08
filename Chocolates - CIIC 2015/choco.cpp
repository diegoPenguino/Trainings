#include <bits/stdc++.h>

using namespace std;

// Solucion para 30 pts

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n + 5);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long chocos_tot = 0;
    long long res = -1;
    for (int diario = 1;; diario++) {
        chocos_tot = 0;
        for (int i = 0; i < n; i++) {
            chocos_tot += v[i];
            chocos_tot -= diario;
            if (chocos_tot < 0) {
                res = diario - 1;
                break;
            }
        }
        if (res != -1)
            break;
    }

    cout << res << endl;

    return 0;
}
