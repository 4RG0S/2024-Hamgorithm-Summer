#include <bits/stdc++.h>

using namespace std;

int check[50][50];
vector<int> resultMap;

int directionMap[8][2] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1},
};

void dfs(int h, int w, int maxH, int maxW, vector<vector<int>> &map) {
    check[h][w] = 1;

    int dH, dW;
    for (int i = 0; i < 8; i++) {
        dH = h + directionMap[i][0];
        dW = w + directionMap[i][1];

        if (dH < 0 || dH >= maxH || dW < 0 || dW >= maxW) {
            continue;
        }

        if (map[dH][dW] == 1 && check[dH][dW] == 0) {
            dfs(dH, dW, maxH, maxW, map);
        }
    }
}

int main() {
    while (true) {
        int w, h;
        cin >> w >> h;

        if (w == 0 && h == 0) {
            break;
        }

        vector<vector<int>> map(h + 1, vector<int>(w + 1));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
                check[i][j] = 0;
            }
        }

        int result = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1) {
                    if (check[i][j] == 1) {
                        continue;
                    }
                    dfs(i, j, h, w, map);
                    result++;
                }
            }
        }

        resultMap.push_back(result);
    }

    for (int i = 0; i < resultMap.size(); i++) {
        cout << resultMap[i] << endl;
    }

    return 0;
}