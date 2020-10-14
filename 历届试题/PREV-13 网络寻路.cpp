//#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
long int ans;
const int maxn = 100000;
vector<int> g[maxn];

void dfs(int u, int pre, int num) {
	if (num == 4) {
		ans++;
		return;
	}
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v != pre)
			dfs(v, u, num + 1);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m;j++) {
		ans = 0;
		for (int i = 0; i < maxn; i++)
			g[i].clear();
		while (m--) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i = 0; i <= n; i++)
			dfs(i, 0, 1);
		cout << ans;
	}
	
	return 0;
}