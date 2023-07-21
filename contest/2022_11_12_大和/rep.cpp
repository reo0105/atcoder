#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    int loop = 0;
    if (a.at(0) == 0) loop = 1;

    ll now = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (a.at(i) == 0) {
            ans = max(ans, now);
            now = 0;
        }
        now += a.at(i);
    }    
    ans = max(ans, now);

    if (loop) {
        
    }




    return 0;
}