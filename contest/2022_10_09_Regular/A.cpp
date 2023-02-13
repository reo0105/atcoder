#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> p0(n + 1);
    vector<int> p1(n + 1);
    for (int i = 0; i < n; i++) {
      p0[i + 1] = p0[i] + (s[i] == '0');
      p1[i + 1] = p1[i] + (s[i] == '1');
    }
    for (int i = 0; i < n; i++) {
      cout << p0[i + 1];
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
      cout << p1[i + 1];
    }
    cout << endl;
    
    int ways = 0;
    for (int i = 0; i <= n - k; i++) {
      if (p0[i + k] - p0[i] == 0) {
        if (p1[i] == 0 && p1[n] - p1[i + k] == 0) {
          ways += 1;
        }
      }
    }
    cout << (ways == 1 ? "Yes" : "No") << '\n';
  }
  return 0;
}