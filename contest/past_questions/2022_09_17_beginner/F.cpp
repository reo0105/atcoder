#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

ll n, m;
mint sum2(int x, int y, mint a)
{
    mint res = a+(a+mint(x-1)*m*2+(y-1)*2); //平均×含まれる数
    return res*x*y/2;
}

mint sum(int x, int y)
{
    mint res;

    res = sum2((x+1)/2, (y+1)/2, 1); //縦の長さ、横の長さ、左上の数
    res += sum2(x/2, y/2, m+2); //縦の長さ、 横の長さ、 左上の数

    return res;
}

int main()
{
    cin >> n >> m;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        mint ans;
        ans = sum(b, d);
        ans -= sum(a-1, d);
        ans -= sum(b, c-1);
        ans += sum(a-1, c-1);

        cout << ans.val() << endl;
    }

}