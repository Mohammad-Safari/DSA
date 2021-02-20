#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <math.h>
#include <string>
#include <queue> 
#include <iomanip>
#include <set>
#include <unordered_set>
#include <array>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define all(k) k.begin(),k.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 100 * 1000 + 100;
const ll mod = 1e9 + 7;
const ll INF = 1e18;

int n, m;
vector<pair<int, int>> adj[maxn];
bool marked[maxn];
int main()
{
	cin >> n>>m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[v].push_back({ u,i });
		adj[u].push_back({ v,i });
	}
	vector<int> ans;
	queue<int> bfs;
	bfs.push(1);
	marked[1] = 1;
	while (!bfs.empty()) {
		int node = bfs.front();
		bfs.pop();
		for (auto v : adj[node]) {
			if (!marked[v.first]) {
				marked[v.first] = 1;
				bfs.push(v.first);
				ans.push_back(v.second);
			}
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans) {
		cout << x << " ";
	}
	return 0;
}