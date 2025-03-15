#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    int n;
    cin >> n;

    vector<ll> repu;

    for (ll i = 1; i <= 1e12; i = i*10+1) repu.push_back(i);

    set<ll> ans;

    for (ll a: repu) {
        for (ll b: repu) {
            for (ll c : repu) {
                ans.insert(a+b+c);
            }
        }
    }


    for (int i = 0; i < n-1; i++) ans.erase(*ans.begin());
    cout << *ans.begin() << endl;

    return 0;

}