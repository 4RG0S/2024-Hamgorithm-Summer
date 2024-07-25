#include <bits/stdc++.h>

using namespace std;

int check[1001];
vector<vector<int>> adj(1001);

void bfs(int node) {
	queue<int> q;
	q.push(node);

	check[node] = 1;

	while (q.size()) {
		int num = q.front();
		q.pop();

		for (int i = 0; i < adj[num].size(); i++) {
			int next = adj[num][i];
			if (check[next] == 0) {
				check[next] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int result = 0;

	for (int i = 1; i <= N; i++) {
		if (check[i] == 0) {
			bfs(i);
			result++;
		}
	}

	cout << result << endl;
	return 0;
}