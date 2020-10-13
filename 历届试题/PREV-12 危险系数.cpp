#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int n, m;
int bg, ed;
vector<int> v[3000];
int used[3000];
int ans, mark;

void dfs(int x) {
	if (x == ed) {
		mark = 0; return;
	}
	for (int i = 0; i < v[x].size(); i++) {
		if (used[v[x][i]] == 0) {
			used[v[x][i]] = 1;
			dfs(v[x][i]);
			used[v[x][i]] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;
	memset(used, 0, sizeof(used));
	for (int i = 0; i <= n; i++)
		v[i].clear();
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin >> bg >> ed;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(used, 0, sizeof(used));
		used[i] = 1;
		mark = 1;
		for (int j = 0; j < v[bg].size(); j++) {
			used[v[bg][j]] = 1;
			dfs(v[bg][j]);
			used[v[bg][j]] = 0;
		}
		used[i] = 0;
		if (mark)ans++;

	}
	cout << ans << endl;
	return 0;
}