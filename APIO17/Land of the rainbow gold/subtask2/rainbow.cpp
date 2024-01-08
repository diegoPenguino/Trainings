#include "rainbow.h"

#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> land;
vector<int> acum[3];

void init(int R, int C, int sr, int sc, int M, char *S) {
    char c;
    acum[0].resize(C + 1);
    acum[1].resize(C + 1);
    acum[2].resize(C + 1);
    land = vector<vector<bool>>(R + 1, vector<bool>(C + 1, true));
    land[sr][sc] = false;
    land[1][0] = land[2][0] = false;
    for (int i = 0; i < M; i++) {
        c = S[i];
        if (c == 'N')
            sr--;
        else if (c == 'S')
            sr++;
        else if (c == 'W')
            sc--;
        else
            sc++;
        land[sr][sc] = false;
    }

    acum[0][0] = acum[1][0] = acum[2][0] = 0;

    for (int r = 1; r <= R; r++) {
        for (int i = 1; i <= C; i++) {
            acum[r][i] = acum[r][i - 1];
            if (land[r][i] && !land[r][i - 1])
                acum[r][i]++;
        }
    }
    for (int i = 1; i <= C; i++) {
        acum[0][i] = acum[0][i - 1];
        if (!land[1][i - 1] && !land[2][i - 1] && (land[1][i] || land[2][i]))
            acum[0][i]++;
        if (land[1][i] && !land[1][i - 1] && !land[2][i] && land[2][i - 1])
            acum[0][i]++;
        if (!land[1][i] && land[1][i - 1] && land[2][i] && !land[2][i - 1])
            acum[0][i]++;
    }

    land[1][0] = land[2][0] = true;
}

int colour(int ar, int ac, int br, int bc) {
    int ans = 0;
    if (ar == br) {
        ans = acum[ar][bc] - acum[ar][ac];
        if (land[ar][ac])
            ans++;
    } else {
        ans = acum[0][bc] - acum[0][ac];
        if (land[1][ac] || land[2][ac])
            ans++;
    }
    return ans;
}
