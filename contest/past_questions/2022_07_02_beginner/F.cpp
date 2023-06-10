#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        ll b, k, sx, sy, gx, gy;
        cin >> b >> k >> sx >> sy >> gx >> gy;

        ll ans = (abs(sx-gx) + abs(sy-gy)) * k;
        
        ll syoko = sx % b;
        ll state = sy % b;
        ll gyoko = gx % b;
        ll gtate = gy % b;

        vector<p> ss, gs;
        vector<ll> cnts(4, 0);
        vector<ll> cntg(4, 0);
        ss.push_back(make_pair(sx-syoko, sy));
        ss.push_back(make_pair(sx+b-syoko, sy));
        ss.push_back(make_pair(sx, sy-state));
        ss.push_back(make_pair(sx, sy+b-state));
        cnts.at(0) = syoko * k;
        cnts.at(1) = (b - syoko) * k;
        cnts.at(2) = state * k;
        cnts.at(3) = (b - state) * k;

        gs.push_back(make_pair(gx-gyoko, gy));
        gs.push_back(make_pair(gx+b-gyoko, gy));
        gs.push_back(make_pair(gx, gy-gtate));
        gs.push_back(make_pair(gx, gy+b-gtate));
        cntg.at(0) = gyoko * k;
        cntg.at(1) = (b - gyoko) * k;
        cntg.at(2) = gtate * k;
        cntg.at(3) = (b - gtate) * k;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                ll t = cnts.at(i) + cntg.at(j);
                sx = ss.at(i).first; sy = ss.at(i).second;
                gx = gs.at(j).first; gy = gs.at(j).second;

                if ((sx % b == 0 && sy % b == 0) || (gx % b == 0 && gy % b == 0)) {
                    ans = min(ans, t+abs(sx-gx) + abs(sy-gy));
                } else if ((sx % b == 0 && gy % b == 0) || (sy % b == 0 && gx % b == 0)) {
                    ans = min(ans, t+abs(sx-gx) + abs(sy-gy));
                } else if ((sx % b == 0 && gx % b == 0 && sy / b != gy / b)) {
                    ans = min(ans, t+abs(sx-gx) + abs(sy-gy));
                } else if ((sy % b == 0 && gy % b == 0 && sx / b != gx / b)) {
                    ans = min(ans, t+abs(sx-gx) + abs(sy-gy));
                } else if (sx % b == 0 && gx % b == 0) {
                    ans = min(ans, t+abs(sx-gx)+(sy%b)+(gy%b));
                    ans = min(ans, t+abs(sx-gx)+(b-sy%b)+(b-gy%b));
                    ans = min(ans, t+abs(sx-gx)*b+abs(sy-gy));
                } else {
                    ans = min(ans, t+abs(sy-gy)+(sx%b)+(gx%b));
                    ans = min(ans, t+abs(sy-gy)+(b-sx%b)+(b-gx%b));
                    ans = min(ans, t+abs(sy-gy)*b+abs(sx-gx));
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
