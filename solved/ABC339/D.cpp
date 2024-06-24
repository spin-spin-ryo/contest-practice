#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+8
#define rep(i, x) for(int i = 0; i < (x); i++)

using vector2d = vector<vector<int>>;

int point2index(int x, int y, int n) {
    return x + y * n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> grid(n);
    rep(i, n) cin >> grid[i];

    queue<pair<int, int>> que;
    vector<int> dis(n*n*n*n,INF);
    vector<bool> visited(n*n*n*n,false);
    int index1 = -1, index2 = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'P') {
                if (index1 == -1) {
                    index1 = point2index(j, i, n);
                } else {
                    index2 = point2index(j, i, n);
                }
            }
        }
    }

    que.push({index1, index2});
    dis[index1 * n * n + index2] = 0;
    visited[index1 * n * n + index2] = true;

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!que.empty()) {
        auto [index1, index2] = que.front();
        que.pop();
        int x1 = index1 % n;
        int y1 = index1 / n;
        int x2 = index2 % n;
        int y2 = index2 / n;

        for (auto& dir : directions) {
            int nextx1 = x1 + dir[0];
            int nexty1 = y1 + dir[1];
            int nextx2 = x2 + dir[0];
            int nexty2 = y2 + dir[1];

            // Check bounds and obstacles for nextx1 and nexty1
            if (nextx1 >= 0 && nextx1 < n && grid[y1][nextx1] != '#') {
                nextx1 = x1 + dir[0];
            } else {
                nextx1 = x1;
            }
            if (nexty1 >= 0 && nexty1 < n && grid[nexty1][x1] != '#') {
                nexty1 = y1 + dir[1];
            } else {
                nexty1 = y1;
            }

            // Check bounds and obstacles for nextx2 and nexty2
            if (nextx2 >= 0 && nextx2 < n && grid[y2][nextx2] != '#') {
                nextx2 = x2 + dir[0];
            } else {
                nextx2 = x2;
            }
            if (nexty2 >= 0 && nexty2 < n && grid[nexty2][x2] != '#') {
                nexty2 = y2 + dir[1];
            } else {
                nexty2 = y2;
            }

            int new_index1 = point2index(nextx1, nexty1, n);
            int new_index2 = point2index(nextx2, nexty2, n);
            int new_pair = new_index1 * n * n + new_index2;

            if (!visited[new_pair]) {
                visited[new_pair] = true;
                dis[new_pair] = dis[index1 * n * n + index2] + 1;
                que.push({new_index1, new_index2});
            }
        }
    }

    int ans = INF;
    rep(i, n) {
        rep(j, n) {
            int index = point2index(i, j, n);
            int pair_index = index * n * n + index;
            if (visited[pair_index]) {
                ans = min(ans, dis[pair_index]);
            }
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}
