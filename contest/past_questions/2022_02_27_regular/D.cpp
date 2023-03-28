#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// int A[1000000];
// int psum[1000000];
vector<int> a(1000000, 0);
vector<int> psum(1000000, 0);

int main() 
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        psum.at(a.at(i))++;
    }

    /* 6次元の累積和?? */
    int t = 1;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 1000000; j++) {
            if (j/t%10 != 0) psum[j] += psum[j-t];
        }
        t *= 10;
    }

    for (int j = 0; j < 1000000; j++) {
        cout << psum.at(j) << " ";
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += psum.at(999999-a.at(i));
        bool chk = true;
        for (int j = 0; j < 6; j++) {
            if (a.at(i)%10 >= 5) chk = false;
            a.at(i) /= 10;
        }
        if (chk) ans--;
    }

    ans /= 2;
    cout << ans << endl;

    return 0;
}
