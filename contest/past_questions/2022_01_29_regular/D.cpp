#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a(200005);

    cin >> n;
    for (int i = 0; i < 2*n; i++) cin >> a.at(i);

    vector<int> minia(100005, 1e9+5);
    vector<int> minib(100005, 1e9+5);

    for (int i = n-1; i >= 0; i--) minia.at(i) = min(minia.at(i+1), a.at(i));
    for (int i = n-1; i >= 0; i--) minib.at(i) = min(minib.at(i+1), a.at(i+n));


    int mini = minia.at(0);
    if (mini >= minib.at(0)) {
        int sec = 1e9+5;
        for (int i = 0; i < n; i++) {
            if (a.at(i) == mini && a.at(i+n) < sec) {
                sec = a.at(i+n);
            }
        }
        if (sec <= mini) {
            cout << mini << " " << sec << endl;
            return 0;
        }
    }

    // cout << minia.at(0) << " " << minib.at(0) << endl; 

    int firb = 1e9+5;
    int secb = 1e9+5;
    vector<int> ans;
   
    for (int i = 0; i < n; i++) {
        if (a.at(i) == mini) {
            if ((int)ans.size() == 0) firb = a.at(i+n);
            else if ((int)ans.size() == 1) secb = a.at(i+n);
            ans.push_back(i);
        } else if (minia.at(i) > mini) {
            if (minia.at(i) == a.at(i) && a.at(i) < firb) ans.push_back(i);
            else if (minia.at(i) == a.at(i) && a.at(i) == firb) {
                if (firb < secb) ans.push_back(i);
            }
        }
    }

    int si = (int)ans.size();
    for (int i = 0; i < si; i++) cout << a.at(ans.at(i)) << " ";
    for (int i = 0; i < si; i++) cout << a.at(ans.at(i)+n) << " ";

    return 0;
}
// 832690585 154417510