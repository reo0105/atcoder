#include <bits/stdc++.h>
using namespace std;
typedef pair<long double, int> pd;
typedef long long ll;
typedef tuple<ll, int, int> tup;

// /// long double
// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> a(200005), b(200005);
//     for (int i = 1; i <= n; i++) cin >> a.at(i) >> b.at(i);

//     vector<pd> p;
//     for (int i = 1; i <= n; i++) {
//         p.push_back(make_pair((long double)a.at(i) / (a.at(i) + b.at(i)), -i));
//     }

//     sort(p.rbegin(), p.rend());

//     for (int i = 0; i < n; i++) {
//         cout << p.at(i).second * -1 << " ";
//     }
//     cout << endl;
 

//     return 0; 
// }

// // 比較関数
// int main()
// {
//     int n;
//     vector<tup> ab;

//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         int a, b;
//         cin >> a >> b;
//         ab.push_back(make_tuple((ll)a, a + b, i+1));
//     }

//     sort(ab.begin(), ab.end(), [](tup a, tup b) {
//         if (get<0>(b) * get<1>(a) == get<0>(a) * get<1>(b)) return get<2>(a) < get<2>(b);
//         return get<0>(b) * get<1>(a) < get<0>(a) * get<1>(b);
//     });

//     for (int i = 0; i < n; i++) cout << get<2>(ab.at(i)) << " ";
//     cout << endl;
// }

// 比較関数　tupleなし
int main()
{
    int n;
    vector<int> a, b, id;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
        id.push_back(i);
    }

    sort(id.begin(), id.end(), [&](int l, int r){
        ll x = (ll)a.at(l) * (a.at(r) + b.at(r));
        ll y = (ll)a.at(r) * (a.at(l) + b.at(l));
        if (x == y) return l < r;
        else return x > y;
    });

    for (int i = 0; i < n; i++) cout << id.at(i)+1 << " ";
    cout << endl;

    return 0;
}