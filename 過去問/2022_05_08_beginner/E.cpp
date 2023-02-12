#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tup;

// int main()
// {
//     int n;
//     vector<int> a(200005), b(200005);
//     vector<bool> ans(200005);

//     cin >> n;
//     for (int i = 0; i < n; i++) cin >> a.at(i);
//     for (int i = 0; i < n; i++) cin >> b.at(i);

//     int q;
//     vector<tup> p;

//     cin >> q;
//     for (int i = 0; i < q; i++) {
//         int x, y;
//         tup tmp;
//         cin >> x >> y;
//         tmp = make_tuple(x, y, i);
//         p.push_back(tmp);
//     }
//     // for (int i = 0; i < q; i++) {
//     //     cout << get<0>(p.at(i)) <<" ";
//     //     // get<1>(p.at(i)) = y;
//     //     // get<2>(p.at(i)) = i;
//     // }

//     sort(p.begin(), p.end());


//     int nx = 0, ny = 0, pre_x = 0;
//     unordered_set<int> sx, sy;

//     for (int i = 0; i < q; i++) {
//         int x, y, ind;
//         x = get<0>(p.at(i));
//         y = get<1>(p.at(i));
//         if (x > nx) {
//             for (int j = nx; j < x; j++) sx.insert(a.at(j));
//             nx = x;
//         }

//         if (pre_x != x) {
//             sy.clear();
//             ny = 0;
//         }

//         if (y > ny) {
//             for (int j = ny; j < y; j++) sy.insert(b.at(j));
//             ny = y;
//         }

//         // cout << sx.size() << " " << sy.size() << endl;

//         ind = get<2>(p.at(i));
//         pre_x = x;
//         if (sx == sy) ans.at(ind) = true;
//         else ans.at(ind) = false;
//     }

//     for (int i = 0; i < q; i++) {
//         if (ans.at(i)) cout << "Yes" << endl;
//         else cout << "No" << endl;
//     }

//     return 0;
// }

 
int main() {
    int n, q;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a.at(i);
    for (int i = 0; i < n; i++) cin >> b.at(i);

    vector<int> ca(n), cb(n), mx(n);
    map<int,int> mp;

    for (int i = 0; i < n; i++) {
        if (!mp.count(a.at(i))) mp[a.at(i)] = mp.size()+1 ;

        ca.at(i) = mp.size();
    }

    const int INF = 1001001001;
    int m = 0;
    set<int> st;

    for (int i = 0; i < n; i++) {
        st.insert(b.at(i));
        int x = mp[b[i]];
        if (x == 0) x = INF;
        m = max(m, x);
        mx[i] = m;
        cb[i] = st.size();
    }
    
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (ca[x] == cb[y] && mx[y] == cb[y]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}