#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
multisetは多重集合でsetとは異なり同じ要素を保持できる。
ただしeraseで消すとその値がすべて消去される　<--------アホほどハマった
1つだけ消すにはイテレータを介する必要がある。
find(値)を使えばそのいてれーばが返ってくるからいける。
ただし見つからない場合にはendが返り、これをeraseすると実行時エラー
*/

int main()
{
    int n, m, k;
    ll ans = 0;
    vector<int> a(200002), sub;
    multiset<int> re_s;
    multiset<int> sum_s;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        if (i < m) sub.push_back(a.at(i));
    }

    sort(sub.begin(), sub.end());

    for (int i = 0; i < k; i++) {
        ans += sub.at(i);
        sum_s.insert(sub.at(i));
    }

    for (int i = k; i < m; i++) {
        re_s.insert(sub.at(i));
    }

    cout << ans << " ";
    
    for (int i = 0; i < n-m; i++) {
        int mini, maxi;
        if (re_s.empty()) {
            ans -= a.at(i);
            ans += a.at(i+m);
            goto end;
        }

        mini = *begin(re_s);
        maxi = *rbegin(sum_s);

        // if (a.at(i) < mini) {
        if (sum_s.count(a.at(i))) {
            ans -= a.at(i);
            ans += mini;
            sum_s.erase(sum_s.find(a.at(i)));
            sum_s.insert(mini);
            re_s.erase(re_s.find(mini));
        } else {
            re_s.erase(re_s.find(a.at(i)));
        }

        re_s.insert(a.at(i+m));
        mini = *begin(re_s);
        maxi = *rbegin(sum_s);
        
        if (mini < maxi) {
            ans -= maxi;
            ans += mini;
            sum_s.erase(sum_s.find(maxi));
            sum_s.insert(mini);
            re_s.erase(re_s.find(mini));
            re_s.insert(maxi);
        }

end:
        if (i ==n-m-1)cout << ans << " ";
        else cout << ans << endl;
    } 

    return 0;

}