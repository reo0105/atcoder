#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<pii> head;
    head.push_back(make_pair(1, 0));
    int ni = 1, nj = 0;

    for (int i = 0; i < q; i++) {
        int qi;

        cin >> qi;

        if (qi == 1) {
            char c;
            cin >> c;
            if (c == 'U') {
                nj++;
            } else if (c == 'R') {
                ni++;
            } else if (c == 'L') {
                ni--;
            } else {
                nj--;
            }
            head.push_back(make_pair(ni, nj));
        } else {
            int p;
            cin >> p;
            
            int sz = (int)head.size();

            if (sz >= p) {
                cout << head[sz-p].first << " " << head[sz-p].second << endl;
            } else {
                cout << p-sz+1 << " " << 0 << endl;
            }
        }
    }

    return 0;
}