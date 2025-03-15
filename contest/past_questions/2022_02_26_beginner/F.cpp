#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int h, w, n;
    int si, sj, gi, gj;

    cin >> h >> w >> n;
    cin >> si >> sj >> gi >> gj;

    map<int, set<int>> oi, oj;
    for (int k = 0; k < n; k++) {
        int i, j;
        cin >> i >> j;

        oi[i].insert(j);
        oj[j].insert(i);
    }

    queue<p> que;
    map<p, int> dist;

    que.push(make_pair(si, sj));
    dist[(make_pair(si, sj))] = 1;

    while (que.size()) {
        p now = que.front();
        que.pop();
        int ni = now.first;
        int nj = now.second;
        // cout << ni << " " << nj << " " << dist[make_pair(ni, nj)] << endl;

        if (ni == gi && gj == nj) {
            cout << dist[make_pair(ni, nj)]-1 << endl;
            return 0;
        }
        
        auto itr = oi[ni].lower_bound(nj);
        if (itr != oi[ni].end()) {
            if (dist[make_pair(ni, *itr-1)] == 0) {
                que.push(make_pair(ni, *itr-1));
                dist[make_pair(ni, *itr-1)] = dist[make_pair(ni, nj)] +1;
            }
        }

        if (itr != oi[ni].begin()) {
            itr--;
            if (dist[make_pair(ni, *itr+1)] == 0) {
                que.push(make_pair(ni, *itr+1));
                dist[make_pair(ni, *itr+1)] = dist[make_pair(ni, nj)]+1;
            }
        }

        itr = oj[nj].lower_bound(ni);
        if (itr != oj[nj].end()) {
            if (dist[make_pair(*itr-1, nj)] == 0) {
                que.push(make_pair(*itr-1, nj));
                dist[make_pair(*itr-1, nj)] = dist[make_pair(ni, nj)]+1;
            }
        }

        if (itr != oj[nj].begin()) {
            itr--;
            if (dist[make_pair(*itr+1, nj)] == 0) {
                que.push(make_pair(*itr+1, nj));
                dist[make_pair(*itr+1, nj)] = dist[make_pair(ni, nj)]+1;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}