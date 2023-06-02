#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s, t, m;
    cin >> s >> t >> m;

    vector<vector<int>> G(300005);
    vector<vector<int>> done(3005, vector<int>(3005, -1));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v-s);
    }

    // for (int i = 1; i <= t; i++) {
    //     for (int j = 0; j < (int)G.at(i).size(); j++) {
    //         cout << G.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }

    int x;
    for (int i = 1; i <= s; i++) {
        int d = (int)G.at(i).size();

        for (int j = 0; j < d; j++) {
            for (int k = j+1; k < d; k++) {
                if (done.at(G.at(i).at(j)).at(G.at(i).at(k)) == -1) {
                    done.at(G.at(i).at(j)).at(G.at(i).at(k)) = i;
                    done.at(G.at(i).at(k)).at(G.at(i).at(j)) = i;
                }
                else {
                    cout << i << " " << done.at(G.at(i).at(k)).at(G.at(i).at(j)) << " " << G.at(i).at(j)+s << " " << G.at(i).at(k)+s << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}