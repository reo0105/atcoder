#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

struct Trie {
	struct Node {
		int cnt;
		map<char, int> to;
		Node () : cnt(0) {}
	};
	vector<Node> d;
	Trie(): d(1) {}

	void add(const string &s) {
		int v = 0;
		for (char c : s) {
			if (!d[v].to.count(c)) {
				d[v].to[c] = (int)d.size();
				d.push_back(Node());
			}
			v = d[v].to[c];
		}
		d[v].cnt++;
	}

	ll ans = 0;
	ll dfs(int from) {
		int res = d[from].cnt;
		for (auto p : d[from].to) {
			res += dfs(p.second);
		}
		if (from) ans += (ll)res * (res-1) / 2;
		return res;
	}


	ll solve(int root) {
		dfs(0);
		return ans;
	}

};

int main() {
    int n;
	cin >> n;

	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];

	Trie t;
	for (int i = 0; i < n; i++) {
		t.add(s[i]);
	}

	cout << t.solve(0) << endl;

	return 0;
}