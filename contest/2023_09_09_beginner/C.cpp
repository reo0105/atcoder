#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

bool check(vector<int> c, vector<int> ids, int i, int j, int k)
{
    vector<pii> d;
    d.emplace_back(ids[i], c[i]);
    d.emplace_back(ids[j], c[j]);
    d.emplace_back(ids[k], c[k]);
    sort(d.begin(), d.end());

    return (d[0].second == d[1].second);
}

int main()
{
    vector<int> c(9);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i*3+j];
        }
    }

    vector<int> ids = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    int numerator = 0;
    int denominator = 0;

    do {
        bool ok = false;
                
        ok |= check(c ,ids, 0, 1, 2);
        if (!ok) ok |= check(c ,ids, 3, 4, 5);
        if (!ok) ok |= check(c ,ids, 6, 7, 8);
        if (!ok) ok |= check(c ,ids, 0, 3, 6);
        if (!ok) ok |= check(c ,ids, 1, 4, 7);
        if (!ok) ok |= check(c ,ids, 2, 5, 8);
        if (!ok) ok |= check(c ,ids, 0, 4, 8);
        if (!ok) ok |= check(c ,ids, 2, 4, 6);

        if (!ok) numerator++;
        denominator++;
    } while (next_permutation(ids.begin(), ids.end()));

    cout << fixed << setprecision(12) << (double)numerator / denominator << endl;

    return 0;
}