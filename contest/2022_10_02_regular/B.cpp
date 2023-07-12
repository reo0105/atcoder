#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int lis(vector<pi> ab)
{
    vector<int> dp;

    for (pi x : ab) {
        int t = x.second;

        auto itr = lower_bound(dp.begin(), dp.end(), t);

        if (itr == dp.end()) dp.push_back(t);
        else *itr = t;
    }

    return (int)dp.size();
}

int main()
{
    int n;
    cin >> n;
    vector<pi> ab(n);

    for (int i = 0; i < n; i++) cin >> ab.at(i).first;
    for (int i = 0; i < n; i++) cin >> ab.at(i).second;

    sort(ab.begin(), ab.end());

    int ans = n;

    ans += lis(ab);

    cout << ans << endl;

    return 0;
}



template<typename T>
struct segment_tree {
    using F = function<T(T, T)>; // 型Tの値を2つ受け取って型Tの値を返すような関数型

    int n;
    vector<T> node;
    F combine; // 区間の結合を行う演算
    T identity; // 単位元

    segment_tree(int n, F combine, T identity)
        : n(n), node(n<<1, identity), combine(combine), identity(identity) {}

    T operator[](int i) { return node[i + n]; }

    void set(int i, T x) {
        node[i += n] = x;
        // combine関数により、2つの子ノードを結合した結果を親ノードに記録
        while (i >>= 1) node[i] = combine(node[i<<1|0], node[i<<1|1]); 

    }

    T fold(int l, int r) {
        T res = identity; // 初期値は単位元
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            // 区間内のものを左右から結合
            if (l & 1) res = combine(res, node[l++]); 
            if (r & 1) res = combine(node[--r], res);
        }
        return res;
    }
};

int main()
{
    auto combine = [](int a, int b) { return min(a, b); };
}