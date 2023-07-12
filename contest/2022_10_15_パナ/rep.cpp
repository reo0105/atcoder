#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main()
{
    int h, w, rs, cs;
    map<int, vector<int>> mr;
    map<int, vector<int>> mc;
    int n;

    cin >> h >> w >> rs >> cs;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        mr[r].push_back(c);
        mc[c].push_back(r);
    }

    for (auto &x : mr) sort(x.second.begin(), x.second.end());
    for (auto &x : mc) sort(x.second.begin(), x.second.end());

    int q;
    cin >> q;
    int nr = rs, nc = cs;
    for (int i = 0; i < q; i++) {
        char d; 
        int l;
        cin >> d >> l;

        if (d == 'U') {
            auto it = lower_bound(mc[nc].begin(), mc[nc].end(), nr);
            if (it != mc[nc].begin()) {
                it--;
                int obj = *it;
                if (nr - obj <= l) nr = obj + 1;
                else nr -= l;
            } else {
                if (nr <= l) nr = 1;
                else nr -= l;
            }
        } else if (d == 'D') {
            auto it = lower_bound(mc[nc].begin(), mc[nc].end(), nr);
            if (it != mc[nc].end()) {
                int obj = *it;
                if (obj - nr <= l) nr = obj - 1;
                else nr += l;
            } else {
                if (h-nr <= l) nr = h;
                else nr += l;
            }
        } else if (d == 'L') {
            auto it = lower_bound(mr[nr].begin(), mr[nr].end(), nc);
            if (it != mr[nr].begin()) {
                it--;
                int obj = *it;
                if (nc - obj <= l) nc = obj + 1;
                else nc -= l;
            } else {
                if (nc <= l) nc = 1;
                else nc -= l;
            }
        } else {
            auto it = lower_bound(mr[nr].begin(), mr[nr].end(), nc);
            if (it != mr[nr].end()) {
                int obj = *it;
                if (obj - nc <= l) nc = obj - 1;
                else nc += l;
            } else {
                if (w-nc <= l) nc = w;
                else nc += l;
            }
        }

        cout << nr << " " << nc << endl;
    }
} 