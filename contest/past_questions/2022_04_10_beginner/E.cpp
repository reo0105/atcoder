// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef pair<ll, ll> p;

// int main()
// {
//     int n, x, y;
//     vector<int> a(200005);

//     cin >> n >> x >> y;

//     int mini = -1, maxi = -1;
//     for (int i = 1; i <= n; i++) {
//         cin >> a.at(i);
//         if (a.at(i) == x && maxi == -1) maxi = i;
//         if (a.at(i) == y && mini == -1) mini = i;
//     }   


//     ll ans = min(maxi, mini) * (n - max(maxi, mini)+1); 
//     queue<int> tmp;
//     for (int i = max(mini, maxi)+1; i <= n ;i++) {
//         if (a.at(i) == x && maxi <= mini) {
//             ans += (mini - maxi) * (n-i+1);
//             // cout << (mini - maxi) * (n-i+1) << " ";
//             maxi = i;
//             while (!tmp.empty()) {
//                 int next = tmp.front();
//                 tmp.pop();
//                 ans += (next - mini) * (n-i+1);
//                 mini = next;
//             }
//         } else if (a.at(i) == x) {
//             tmp.push(i);
//         } else if (a.at(i) == y && mini <= maxi) {
//             ans += (maxi - mini) * (n-i+1);
//             // cout << (maxi - mini) * (n-i+1) << " m ";
//             // cout << ans << " ";
//             mini = i;
//             while (!tmp.empty()) {
//                 int next = tmp.front();
//                 tmp.pop();
//                 // cout << (next - maxi) << " whil ";
//                 ans += (next - maxi) * (n-i+1);
//                 maxi = next;
//             }
//         } else if (a.at(i) == y) {
//             tmp.push(i);
//         }
//         // cout << i << " " << ans << endl; 
//     }

//     cout << ans << endl;


//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
// int main() {
//     int N, X, Y;
//     cin>>N>>X>>Y;
//     vector<int> a(N);
//     for(int i = 0; i < N; ++i) cin>>a[i];
    
//     int posX{-1}, posY{-1}, B{-1};
//     long long res{};

//     // 右端を固定したときにどの範囲の左端が可能かを探索

//     for(int i = 0; i < N; ++i) {
//         if(a[i] == X) posX = i;
//         if(a[i] == Y) posY = i;
//         if(a[i] < Y or X < a[i]) B = i;
//         res += max(0, min(posX, posY) - B);
//         cout << res << " ";
//     }
//     cout<<res<<endl;
// }

int main()
{
    int n, x, y;
    vector<int> a(200005);

    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) cin >> a.at(i);

    ll ans = 0;
    int posX = -1, posY = -1, B = -1;

    for (int i = 0; i < n; i++) {
        if (a.at(i) == x) posX = i;
        if (a.at(i) == y) posY = i;
        if (a.at(i) < y || x < a.at(i)) B = i;
        ans += max(0, min(posX, posY) - B);
    } 
    cout << ans << endl;
}