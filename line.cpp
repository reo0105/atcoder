#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

#define INF 2e9+5

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    vector<ll> ans(n+1, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    a.push_back(INF);

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;

        int near = lower_bound(a.begin(), a.end(), l) - a.begin(); // index;
        int dist = a[near] - l; 

        int ansl = INF, ansr = INF;

        if (near != 0) {
            if (dist >= l - a[near-1]) {
                dist = min(dist, l - a[near - 1]);
                near--;
            }
        }

        // lにどれがが到達した状態
        for (int i = 0; i < n; i++) {
            if (l - a[i] >= 0) a[i] += dist;
            else a[i] -= dist;
        }

        // for (int i = 0; i < n; i++) cout << a[i] << " ";
        // cout << endl;

        int flag = 0;
        for (int i = 0; i <= n; i++) {
            if (flag == 0 && a[i] == l) {
                ansl = i;
                flag = 1;
            } else if (flag && a[ansl] != a[i]) {
                ansr = i;
                break;
            }
        }

        ans[ansl]++;
        ans[ansr]--;

        int rem = r-l;
        int cnt = 0;
        int now = l+1;
        int next = ansr-1;
        while (rem > 0) {
            near++;

            if (near >= n) break;

            int step = (a[near]-a[near-1]-1) / 2;

            ans[ansl] += step;
            ans[ansr] -= step;
            rem -= step;
            now += step;

            rem--;
            if ((a[near]-a[near-1]-1) % 2) {

                while (near < n && now - a[ansl] == a[near] - now) {
                    near++;
                }
                ansr = near;
                ans[ansl]++;
                ans[ansr]--;

            } else {
                ansl = near;
                while (near < n && now - a[ansl] == ans[near] - now) {
                    near++;
                }
                ansr = near;
                ans[ansl]++;
                ans[ansr]--;

                cnt++;

            }

        }

        if (rem > 0) {
            ans[ansl] += rem;
            ans[ansr] -= rem;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] > r) a[i] = max(r, a[i] - (r-l-cnt));
            else a[i] = min(r, a[i] + (r-l-cnt)); 
        }

    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ans[i];
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}