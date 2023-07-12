#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
  
    ll three = 3;
    while (1) {
	      three *= 3;
        if (three >= 1e18) break;
    }
  
    for (int i = 0; i < t; i++) {
	      ll n, k;
        ll t = three;
        cin >> n >> k;
        int cnt = 0;


        while (t != 0) {
		        if (n / t != 0) {
          	    cnt += n / t;
			          n -= n / t * t;
            }
   		      t /= 3;
        }
    
        if (k >= cnt && k % 2 == cnt % 2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
  
    return 0;
}