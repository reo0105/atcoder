// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// int main() {
//     ll n;
//     string s, t;
//     cin >> n >> s >> t;

//     vector<vector<int>> cnt(26);
//     for (int i = 0; i < (int)s.size(); i++) {
//         cnt[s[i]-'a'].push_back(i);
//     }

//     ll ac = 0, wa = 1e18;

//     while (wa - ac > 1) {
//         ll wj = (ac+wa) / 2;

//         bool ok = true;
//         int now = t[0] - 'a';
//         ll ncnt = n;
//         ll tmp = wj;
//         for (int i = 0; i < (int)t.size(); i++) {
//             if ((int)cnt[now].size() == 0) {
//                 ok = false;
//                 break;
//             }
//             ll loop = tmp / (int)cnt[now].size();

//             ncnt -= loop;
//             int rem = tmp % (int)cnt[now].size();

//             if (ncnt < 0) {
//                 ok = false;
//                 break;
//             }

//             if (rem != 0) {
//                 ncnt--;
//                 if (ncnt < 0) {
//                     ok = false;
//                     break;
//                 }
//                 int id = cnt[now][rem-1] + 1;

//                 if (i == (int)t.size()-1) break;
//                 now = t[i+1] - 'a';
//                 int nrem = cnt[now].end() - lower_bound(cnt[now].begin(), cnt[now].end(), id);
//                 // cout << nrem << endl;
//                 tmp = wj - nrem;
//             } else {
//                 int id = cnt[now][(int)cnt[now].size()-1] + 1;
//                 if (i == (int)t.size()-1) break;
//                 now = t[i+1] - 'a';
//                 int nrem = cnt[now].end() - lower_bound(cnt[now].begin(), cnt[now].end(), id);
//                 // cout << nrem << endl;
//                 tmp = wj - nrem;
//             }
//         }
//         // cout << ac << " " << wa << endl;

//         if (ok) ac = wj;
//         else wa = wj;
//     }

//     cout << ac << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  ll n;
  string s, t;
  cin >> n >> s >> t;
  int m = s.size();

  vector<vector<int>> is(26);
  rep(i,m) is[s[i]-'a'].push_back(i);

  auto judge = [&](ll k) {
    ll p = 0;
    for (char c : t) {
      vector<int>& nis = is[c-'a'];
      int w = nis.size();
      if (w == 0) return false;
      ll i = lower_bound(nis.begin(), nis.end(), p%m) - nis.begin();
      i += k-1;
      p = (i/w)*m + nis[i%w] + p/m*m + 1;
      if (p > n*m) return false;
    }
    return true;
  };

  ll ac = 0, wa = n*m+1;
  while (ac+1 < wa) {
    ll wj = (ac+wa)/2;
    if (judge(wj)) ac = wj; else wa = wj;
  }
  cout << ac << endl;
  return 0;
}