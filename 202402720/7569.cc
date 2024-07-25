#include <bits/stdc++.h>

using namespace std;

struct Point {
    int h, n, m;
};

int diff[6][3] = {{-1, 0, 0}, {1, 0, 0},  {0, -1, 0},
                  {0, 1, 0},  {0, 0, -1}, {0, 0, 1}};

void bfs(vector<vector<vector<int>>> &box, int lh, int ln, int lm) {
    queue<Point> q;
    for (int i = 0; i < lh; i++) {
        for (int j = 0; j < ln; j++) {
            for (int k = 0; k < lm; k++) {
                if (box[i][j][k] == 1) {
                    q.push({i, j, k});
                }
            }
        }
    }

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int dh = p.h + diff[i][0];
            int dn = p.n + diff[i][1];
            int dm = p.m + diff[i][2];

            if (0 <= dh && dh < lh && 0 <= dn && dn < ln && 0 <= dm &&
                dm < lm) {
                if (box[dh][dn][dm] == 0) {
                    box[dh][dn][dm] = box[p.h][p.n][p.m] + 1;
                    q.push({dh, dn, dm});
                }
            }
        }
    }
}

int findMax(vector<vector<vector<int>>> &box, int H, int N, int M) {
    int max = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 0) {
                    return -1;
                }
                if (box[i][j][k] > max) {
                    max = box[i][j][k];
                }
            }
        }
    }
    return max - 1;
}

bool complete(vector<vector<vector<int>>> &box, int H, int N, int M) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> box(H,
                                    vector<vector<int>>(N, vector<int>(M, 0)));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];
            }
        }
    }

    if (complete(box, H, N, M)) {
        cout << "0\n";
        return 0;
    }

    bfs(box, H, N, M);

    cout << findMax(box, H, N, M) << "\n";

    return 0;
}