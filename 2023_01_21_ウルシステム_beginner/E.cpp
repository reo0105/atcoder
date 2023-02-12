#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int , ll> p;
#define INF 1<<29

int main()
{
    ll n;
    vector<ll> a(305);
    vector<string> s(305);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a.at(i);
    for (int i = 0; i < n; i++) cin >> s.at(i);

    vector<vector<p>> dist(305, vector<p>(305, make_pair(INF, 0))); //本数、最大値
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s.at(i-1).at(j-1) == 'Y') {
                dist.at(i).at(j) = make_pair(1, a.at(i-1));
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist.at(i).at(j).first > dist.at(i).at(k).first + dist.at(k).at(j).first) {
                    dist.at(i).at(j).first = dist.at(i).at(k).first + dist.at(k).at(j).first;
                    dist.at(i).at(j).second = dist.at(i).at(k).second + dist.at(k).at(j).second;
                } else if (dist.at(i).at(j).first == dist.at(i).at(k).first + dist.at(k).at(j).first && dist.at(i).at(j).second < dist.at(i).at(k).second + dist.at(k).at(j).second) {
                    dist.at(i).at(j).second = dist.at(i).at(k).second + dist.at(k).at(j).second;
                }
            }
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        if (dist.at(u).at(v).first != INF) {
            cout << dist.at(u).at(v).first << " " << a.at(v-1) + dist.at(u).at(v).second << endl; 
        } else {
            cout << "Impossible" << endl;
        }
    }

    // vector<bool> seen(305, false);
    // vector<int> dist(305, -1)
    // queue<p> que; //都市、コスト
    // for (int i = 1; i <= n; i++) {
    //     if (!seen.at(i)) {
    //         que.push(make_pair(i, a.at(i)));
    //         seen.at(i) = true;
    //         dist.at(i) = 0;

    //         while(!que.empty()) {
    //             p tmp = que.top();
    //             int from = tmp.first; //都市
    //             ll cost = tmp.second; //こすと
    //             que.pop();

    //             for (char next : s.at(from)) {
    //                 if (next == 'N') continue;
    //                 if (dist.at(next) < dist.at(from) + 1) continue;
    //                 dist.at(next) = dist.at(from) + 1;
                    
    //             }
    //         }

    //     }
    // }



    return 0;
}