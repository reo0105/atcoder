#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> p;

/*
q番目のクエリで(i, j)を出力するとし、それまでの最新q'でi行目をxで代入しているとする。
1,2,....kでj列目に足し合わされる値をSk,jとおくと、x + Sq,j - Sq', jが答え。
*/

// Runtime errorがどこで起きてるのか分からん

ll op(ll a, ll b) { return a+b; } 
ll e() { return 0L; }

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    segtree<ll, op, e> t(n+5);
    vector<p> latest(200005, make_pair(-1, 0));
    vector<int> qi(200005), a(200005), b(200005), c(200005);
    vector<vector<int>> subt(200005);
    vector<ll> ans;


    for (int i = 0; i < q; i++) {
        cin >> qi.at(i);
        if (qi.at(i) == 1) {
            cin >> a.at(i) >> b.at(i) >> c.at(i); // l, rと加算する値を保存
        } else if (qi.at(i) == 2) {
            cin >> a.at(i) >> b.at(i); // setを行う行と値を保存
            latest.at(a.at(i)) = make_pair(i, b.at(i)); //latestのsetを行った行番号に、その時間と値を保存
        } else {
            cin >> a.at(i) >> b.at(i); //出力する座標を保存
            int j = latest.at(a.at(i)).first; //現在の時点でi行目にsetを行った最新の時点を取得
            int x = latest.at(a.at(i)).second; //現在の時点でi行目にsetを行った最新の値を取得
            int id = (int)ans.size(); // 現在の出力の個数を取得
            ans.push_back(x); //出力個数を1個増加させる //この時点でans.at(i) = x;
            c.at(i) = id; //現在の時刻のクエリで出力すべきans配列のindexを保存
            if (j >= 0) subt.at(j).push_back(i); // setを行った時刻jにクエリの出力時刻iを記録
        }
    }

    for (int i = 0; i < q; i++) {
        if (qi.at(i) == 1) {
            ll nowl = t.get(a.at(i)); //seg木の前からl番目の現在の値
            ll nowr = t.get(b.at(i)+1);//seg木の前からr番目の現在の値
            t.set(a.at(i), nowl+c.at(i)); //値を+xで更新
            t.set(b.at(i)+1, nowr-c.at(i)); //値を-xで更新
        } else if (qi.at(i) == 2) {
            for (int j : subt.at(i)) {
                ans.at(c.at(j)) -= t.prod(1, b.at(j)+1); //この時点でans.at(i) = x - Sq', jになる
            }
        } else {
            ans.at(c.at(i)) += t.prod(1, b.at(i)+1);
        }
    }

    for (ll x : ans) cout << x << endl;

    return 0;
}