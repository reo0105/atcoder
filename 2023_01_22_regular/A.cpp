#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long ll;
 
int main()
{
    int n;
    cin >> n;
 
    string a, b;
 
    cin >> a >> b;
    if (b < a) swap(a, b);
 
    for (int i = 0; i < n; i++) {
        if (a.at(i) > b.at(i)) swap(a.at(i), b.at(i));
    }
	
  	int l;
    if (n > 9) l = 9;
  	else l = n;
 
    ll x = 0, y = 0;
    ll cnt = 1;
 
    for (int i = 0; i < n; i++) { // i桁目を入れ替える
        x += (a.at(n-i-1) - '0') * cnt;
        y += (b.at(n-i-1) - '0') * cnt;
        cnt *= 10;
        x %= MOD;
        y %= MOD;
        cnt %= MOD;
    }
 
    cout << (x * y) % MOD << endl;
 
 
    return 0;
}