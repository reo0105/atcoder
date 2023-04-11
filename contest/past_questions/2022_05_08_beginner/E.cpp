// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main()
// {
//     int n;
//     vector<int> a(200005), b(200005);
    
//     cin >> n;
//     for (int i = 1; i <= n; i++) cin >> a.at(i);
//     for (int i = 1; i <= n; i++) cin >> b.at(i);


//     vector<int> cnta(200005, 0), cntb(200005, 0);
//     vector<bool> eq(200005, false);
//     set<int> sa, sb;

//     for (int i = 1; i <= n; i++) {
//         if (sa.count(a.at(i))) {
//             cnta.at(i) = cnta.at(i-1);
//         } else {
//             sa.insert(a.at(i));
//             cnta.at(i) = cnta.at(i-1) + 1;
//         }

//         if (sb.count(b.at(i))) {
//             cntb.at(i) = cntb.at(i-1);
//         } else {
//             sb.insert(b.at(i));
//             cntb.at(i) = cntb.at(i-1) + 1;
//         }
//     }

//     // sa.clear(); sb.clear();

//     int cnt = 0;
//     int ia = 1, ib = 1;
//     set<int> sa1, sb1;
//     while (1) {
//         while (ia <= n && sa1.count(a.at(ia))) ia++;
//         while (ib <= n && sb1.count(b.at(ib))) ib++;
//         if (ia == n+1 || ib == n+1) break;
//         cnt++;
//         sa1.insert(a.at(ia));
//         sb1.insert(b.at(ib));
//         // cout << "cnt " << cnt << " " << a.at(ia) << " " << b.at(ib) << endl; 
//         eq.at(cnt) = (sa1 == sb1); //これが線形時間かかるからTLE
//     }

//     int q;
//     cin >> q;

//     for (int i = 0; i < q; i++) {
//         int x, y;
//         cin >> x >> y;
//         if (cnta.at(x) != cntb.at(y)) cout << "No" << endl;
//         else if (eq.at(cnta.at(x))) cout << "Yes" << endl;
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