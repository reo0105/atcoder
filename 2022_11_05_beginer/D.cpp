#include <bits/stdc++.h>
using namespace std;


int gcd_arr(vector<int> a)
{
    int n = a.size();
    for (int i = n-2; i>=0; i--) {
        a.at(i) = gcd(a.at(i), a.at(i+1));
    }

    return a.front();
}

int main()
{
    int n, goal, ans = 0;
    vector<int> a(1002);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> goal;
        a.at(i) = goal;
    }
    
    goal = gcd_arr(a);

    for (int i = 0; i < n; i++) {
        a.at(i) /= goal;
        while((a.at(i) % 2) == 0) {
            a.at(i) /= 2;
            ans++;
        }

        while((a.at(i) % 3) == 0) {
            a.at(i) /= 3;
            ans++;
        }

        if (a.at(i) != 1) {
            ans = -1;
            break;
        }
    }

    cout << ans << endl;
    

    return 0;
}