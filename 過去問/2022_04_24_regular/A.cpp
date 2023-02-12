#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// int main()
// {
//     int n;
//     vector<int> t(100005);

//     cin >> n;
//     for (int i = 0; i < n; i++) cin >> t.at(i);

//     ll now = 1;
//     int dim = 1;

//     for (int i = 0; i < n; i++) {
//         int t0 = t.at(i);

//         ll loop = 1;
//         for (int j = 0; j < t0; j++) {
//             loop <<= 1;
//         }

//         if (dim < t0+1) {
//             now = 1L << t0;
//             dim = t0 + 1;
//         } else {
//             int flag = 0;
//             for (int j = t0; j < dim; j++) {
//                 if (((now>>j) & 1) == 0) {
//                     now |= 1L << j;
//                     int mask = 1L << (dim-1);
//                     ll t = 0;
//                     for (int k = dim-1; k >= t0; k--) {
//                         if ((now>>k) & 1) t += mask;
//                         mask >>= 1;
//                     }
//                     now = t;
//                     flag = 1;
//                     break;
//                 }
//             }
//             if (!flag) {
//                 now = (1L << dim) | (1L<<t0);
//                 dim++;
//             }
//         }

//         // cout << now << " " << dim << endl;
//     }

//     cout << now << endl;

//     return 0;
// }

 
int main() {
  int N;
  cin >> N;

  ll ans = 0;
  
  for (int i = 0, t; i < N; i++) {
    cin >> t;
    ll pt = 1LL << t;
    ans = (ans / pt + 1) * pt;
    if (ans % (pt * 2) == 0) ans += pt;
  }
  
  cout << ans << "\n";
}