#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (h > w) swap(h, w);

    sort(a.rbegin(), a.rend());

    multiset<pii> st;
    st.insert(make_pair(h, w));

    int ok = 1;

    for (int i = 0; i < n; i++) {
        int line = pow(2, a[i]);

        auto miniptr = st.lower_bound(make_pair(line, line));
        pii mini = *st.lower_bound(make_pair(line, line));

        // cout << mini.first << " " << mini.second << endl;

        if (miniptr == st.end()) {
            ok = 0;
            break;
        }

        // st.erase(st.find(make_pair(line, line)));
        st.erase(miniptr);

        int ch = mini.first - line;
        int cw = line;

        // cout << ch << " " << cw << endl;


        if (ch > 0 && cw > 0) st.insert(make_pair(ch, cw));

        // cout << mini.first << " : " << mini.second << endl;
        int ch2 = mini.first;
        int cw2 = mini.second - line;

        // cout << ch2 << " " << cw2 << endl;
        if (ch2 > cw2) swap(ch2, cw2);



        if (ch2 > 0 && cw2 > 0) st.insert(make_pair(ch2, cw2));
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}