#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    ll ans = 1e18;

    unordered_set<int> one2zero;
    vector<pair<int, int>> cid(n);
    for (int i = 0; i < n; i++)
    {
        cid[i] = {c[i], i};
    }

    sort(cid.rbegin(), cid.rend());

    int onea = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 && b[i] == 0) one2zero.insert(i);
        if (a[i] == 1) onea++;
    }

    vector<pair<int, int>> cid2(n);
    for (int i = 0; i < n; i++)
    {
        cid2[i] = {c[i], i};
    }

    sort(cid2.begin(), cid2.end());
    
    int lo = 0;
    int hi = onea;

    auto f = [&](int num) -> ll {
        ll suml = 0;
        vector<int> al(n);
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1) suml += c[i];
            al[i] = a[i];
        }

        int minusl = 0;
        ll ansl = 0;

        for (int i = 0; i < n; i++)
        {
            int idx = cid[i].second;

            if (one2zero.count(idx))
            {
                suml -= cid[i].first;
                al[idx] = 0;
                ansl += suml;
            }
            else
            {
                if (al[idx] && minusl < num) 
                {
                    minusl++;
                    suml -= cid[i].first;
                    al[idx] = 0;
                    ansl += suml;
                }
                
            }
        }
        /*
        0から1についてはもともとa[i]が1でc[i]が大きい場合などはその個所を0にしてから行った方が良い場合がある。
        どうする？
        */

        unordered_set<int> zero2onel;
        for (int i = 0; i < n; i++)
        {
            if (al[i] == 0 && b[i] == 1) zero2onel.insert(i);
        }
    
    
        for (int i = 0; i < n; i++)
        {
            int idx = cid2[i].second;
            if (zero2onel.count(idx))
            {
                suml += cid2[i].first;
                ansl += suml;
            }
        }

        return ansl;
    };
    
    while (hi - lo > 2) {
        int cl = lo + (hi - lo) / 3;
        int ch = hi - (hi - lo) / 3;
        if (f(cl) > f(ch)) lo = cl;
        else hi = ch;
    }

    for (int i = lo-10; i < hi+10; i++) 
    {
        // int pi = max(0, i);
        // pi = min(i, onea);
        int pi = i;
        if (pi < 0) pi = 0;
        if (pi > onea) pi = onea;
        ans = min(ans, f(pi));
    }

    cout << ans << endl;
}