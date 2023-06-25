#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

vector<string> S;

template<typename T>
struct Matrix {
    int h, w;
    vector<vector<T>> d;
    Matrix() {}
    Matrix(int h, int w, T val = 0): h(h), w(w), d(h, vector<T>(w, val)) {}
    Matrix& unit() {
        assert(h == w);
        for (int i = 0; i < h; i++) {
            d[i][i] = 1;
        }
        return *this;
    }
    const vector<T>& operator[](int i) const { return d[i]; }
    vector<T>& operator[](int i) { return d[i]; }
    Matrix operator*(const Matrix &a) const {
        assert(w == a.h);
        Matrix r(h, a.w);
        for (int k = 0; k < w; k++) {
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < a.w; j++) {
                    r[i][j] += d[i][k]*a[k][j];
                }
            }
        }
        return r;
    }

    Matrix pow(long long t) const {
        assert(h == w);
        if (!t) return Matrix(h, h).unit();
        if (t == 1) return *this;
        Matrix r = pow(t>>1);
        r = r*r;
        if (t&1) r = r*(*this);
        return r;
    }
};

bool check(int t, int w)
{
    string ts;
    for (int i = 0; i < w; i++) { ts += 'a'+(t&1); t>>= 1; }
    reverse(ts.begin(), ts.end());
    for (string s : S) {
        if (ts.find(s) != string::npos) return false;
    }
    return true;
}

int main()
{
    ll n;
    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        S.push_back(t);
    }

    int l = 5;
    int d = 1<<l;

    if (n < l) {
        int ans = 0;
        for (int i = 0; i < (1<<n); i++) {
            if (check(i, n)) ans++;
        }
        cout << ans << endl;
        return 0;
    }

    Matrix<mint> a(d, d);
    Matrix<mint> x(1, d);

    for (int i = 0; i < d; i++) {
        for (int c = 0; c < 2; c++) {
            int j = (i<<1)|c;
            if (!check(j, l+1)) continue;
            j &= d-1;
            a[i][j] += 1;
        }
    }

    for (int i = 0; i < d; i++) {
        if (check(i, l)) x[0][i] = 1;
    }

    x = x * a.pow(n-l);
    mint ans;
    for (int i = 0; i < d; i++) ans += x[0][i];
    cout << ans.val() << endl;
    return 0;
}

