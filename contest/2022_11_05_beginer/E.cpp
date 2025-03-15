#include <bits/stdc++.h>
using namespace std;

struct UnionFind {

    // iが属する親番号
    vector<int> par;

    UnionFind(int n) {
        par.assign(n, -1);
    }

    int root(int x) {
        return par.at(x) < 0 ? x : (par.at(x) = root(par.at(x)));
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (par.at(x) > par.at(y)) swap(x, y);
        par.at(x) += par.at(y);
        par.at(y) = x;
    }

    bool equal(int x, int y) {
        return (root(x) == root(y));
    }
};

int main()
{
    int h, w;
    int x, y;
    bool ans = false;
    struct UnionFind uf(1000002);
    vector<vector<char>> M(1000002);

    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            M.at(i).push_back(c);
            if (c == 'S') {
                x = j; y = i;
                M.at(i).at(j) = '#';
            }
        }
    }
    
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w; j++) {
            if (M.at(i).at(j) == '.' && M.at(i+1).at(j) == '.') {
                uf.unite(i*w + j, (i+1)*w + j);
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w - 1; j++) {
            if (M.at(i).at(j) == '.' && M.at(i).at(j+1) == '.') {
                uf.unite(i*w+j, i*w+j+1);
            }
        }
    }

    if (y-1 >= 0 && x+1 < w) {
        if (uf.equal((y-1)*w+x, y*w+x+1)) {
            ans = true;
        }
    }

    if (y-1 >= 0 && y+1 < h) {
        if (uf.equal((y-1)*w+x, (y+1)*w+x)) {
            ans = true;
        }
    }

    if (y-1 >= 0 && x-1 >= 0) {
        if (uf.equal((y-1)*w+x, y*w+x-1)) {
            ans = true;
        }
    }

    if (x+1 < w && y+1 < h) {
        if (uf.equal(y*w+x+1, (y+1)*w+x)) {
            ans = true;
        }
    }

    if (x+1 < w && x-1 >= 0) {
        if (uf.equal(y*w+x+1, y*w+x-1)) {
            ans = true;
        }
    }

    if (y+1 < h && x-1 >= 0) {
        if (uf.equal((y+1)*w+x, y*w+x-1)) {
            ans = true;
        }
    }

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}