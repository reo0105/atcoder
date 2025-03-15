#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    if ((sx + sy)%2== 1) sx--;
    if ((tx + ty)%2== 1) tx--;

    ll ans_y = abs(sy - ty);
    ll ans_x = abs(sx - tx);

    ans_x -= ans_y;
    if (ans_x < 0) ans_x = 0;

    ans_y += ans_x / 2;
    cout << ans_y << endl;

    return 0;
}
