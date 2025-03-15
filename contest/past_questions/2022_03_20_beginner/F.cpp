#include <bits/stdc++.h>
using namespace std;
#define INF 1<<29
typedef pair<int, int> p;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(2005);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    vector<vector<int>> dist((1<<17)+5, vector<int>(20, INF));
    queue<p> que;

    for (int i = 0; i < n; i++) {
        dist.at(1<<i).at(i) = 1;
        que.push(make_pair((1<<i), i));
    }
    
    while (que.size()) {
        int s = que.front().first;
        int u = que.front().second;
        que.pop();

        for (int v : G.at(u)) {
            int ns = s ^ (1<<v);
            if (dist.at(ns).at(v) < INF) continue;
            dist.at(ns).at(v) = dist.at(s).at(u) + 1;
            que.push(make_pair(ns, v));
        }
    }

    long long ans = 0;
    for (int i = 1; i < (1<<n); i++) {
        int x = INF;
        for (int j = 0; j < n; j++) x = min(x, dist.at(i).at(j));
        ans += x;
    }
    cout << ans << endl;

    return 0;
}

/*

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
const int inf = 1000000000;

int n, m;
vector<int> G[20];
int dist[1<<17][17];

int main(void)
{
  cin >> n >> m;
  int u, v;
  for(int i = 1; i <= m; i++){
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int N = 1<<n;
  for(int i = 0; i < N; i++) for(int j = 0; j < n; j++) dist[i][j] = inf;
  queue<pair<int, int>> Q;
  for(int i = 0; i < n; i++) dist[1<<i][i] = 1, Q.push({1<<i, i});

  while(Q.size()){
    int s = Q.front().first, v = Q.front().second; Q.pop();
    for(auto u : G[v]){
      int ns = s ^ (1<<u);
      if(dist[ns][u] < inf) continue;
      dist[ns][u] = dist[s][v] + 1;
      Q.push({ns, u});
    }
  }

  long long ans = 0;
  for(int i = 1; i < N; i++){
    int mn = inf;
    for(int j = 0; j < n; j++) mn = min(mn, dist[i][j]);
    ans += mn;
  }
  cout << ans << endl;

  return 0;
}


*/