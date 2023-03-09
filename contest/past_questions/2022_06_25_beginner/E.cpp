#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1<<29

int main()
{
    int n;
    vector<int> c(10);

    cin >> n;
    for (int i = 1; i <= 9; i++) cin >> c.at(i);

    int l = INF;
    for (int i = 1; i <= 9; i++) l = min(l, c.at(i));

    int k = n/l;
    string ans;
    
    while (k > 0) {
        for (int i = 9; i >= 1; i--) {
            if (n-c.at(i) >= 0 && (n-c.at(i))/l == k-1) { 
                ans.push_back(i+'0');
                n -= c.at(i);
                break;
            }
        }
        k--;
    }

    cout << ans << endl;


    return 0;
}