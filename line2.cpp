#include <iostream>
#include <cassert>
#include <string>
#include <vector>

#define MOD 1000000000
typedef long long ll;

using namespace std;

bool ChcekInt(string sn, string sm)
{
    int sz_n = (int)sn.size();
    int sz_m = (int)sm.size();

    if (sz_n >= 3 || sz_m >= 3)
        return false;

    if (sz_n == 2 && sn != "10")
        return false;
    if (sz_m == 2 && sm != "10")
        return false;

    if (!('1' <= sn[0] && sn[0] <= '9'))
        return false;
    if (!('1' <= sm[0] && sm[0] <= '9'))
        return false;

    return true;
}

void nCr(vector<vector<ll>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        v[i][0] = 1;
        v[i][i] = 1;
    }

    for (int i = 1; i < (int)v.size(); i++)
    {
        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            v[i][j] %= MOD;
        }
    }
}

int main()
{
    string sn, sm;

    cin >> sn >> sm;

    if (!ChcekInt(sn, sm))
        exit(100);

    int n = stoi(sn);
    int m = stoi(sm);

    int mal = n * m;
    if (mal % 2 == 1)
    {
        cout << "000000000" << endl;
        return 0;
    }

    vector<vector<ll>> v(mal + 1, vector<ll>(mal + 1, 0));

    nCr(v);

    char ans[10];

    sprintf(ans, "%09lld", v[mal][mal / 2]);

    cout << ans << endl;

    return 0;
}