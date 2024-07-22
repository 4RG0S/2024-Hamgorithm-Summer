#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(10000 + 1);
int check[10000 + 1];
int result[10000 + 1];

int dfs(int here) {
	int total = 1;

	check[here] = 1;

	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];
		if (check[next] == 0) {
			total += dfs(next);
		}
	}

	return total;
}

int main() {
	int N, M;
	cin >> N >> M;

	while (M > 0) {
		int A, B;
		cin >> A >> B;

		adj[B].push_back(A);

		M--;
	}

	for (int i = 1; i <= N; i++) {
		result[i] = dfs(i);
		memset(check, 0, sizeof(check));
	}

	int max = 0;

	for (int i = 1; i <= N; i++) {
		if (result[i] > max) {
			max = result[i];
		}
	}

	for (int i = 1; i <= N; i++) {
		if (result[i] == max) {
			cout << i << " ";
		}
	}

	cout << endl;

	return 0;
}