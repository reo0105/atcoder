#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main()
{
    int w, h;
    int n;
    vector<int> p(200005), q(200005);
    int A, B;
    vector<int> a, b;

    cin >> w >> h >> n;
    for (int i = 0; i < n; i++) cin >> p.at(i) >> q.at(i);
    cin >> A;
    for (int i = 0 ; i < A; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    } 
    cin >> B;
    for (int i = 0 ; i < B; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    } 

    map<pi, int> cnt;

    for (int i = 0; i < n; i++) {
        int x = p.at(i);
        int y = q.at(i);

        x = lower_bound(a.begin(), a.end(), x) - a.begin();
        y = lower_bound(b.begin(), b.end(), y) - b.begin();
    
        cnt[make_pair(x, y)]++;
    }

    int mini = 1e9, maxi = -1;
    int area = 0;

    for (auto x : cnt) {
        area++;
        if (x.second > maxi) maxi = x.second;
        if (x.second < mini) mini = x.second;
    }

    if (area < (long long)(A+1)*(B+1)) mini = 0;

    cout << mini << " " << maxi << endl;

    return 0;
}