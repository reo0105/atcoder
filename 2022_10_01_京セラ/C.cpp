#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, x, count;
    set<int> a;
 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x; 
        a.insert(x);
    }
 
    count = 0;
    while(n > 0) {
        if (a.count(++count)) {
            n--;
        } else {
            n -= 2;
        }
    }
    if (n < 0) count--;
 
    cout << count << endl;
 
}