#include <bits/stdc++.h>
using namespace std;
 
vector<int> fx, fy;
vector<vector<int>> ans(405, vector<int>(405, -1));
int cnt = 0;
 
void bfs(int cnt, int n)
{
    // BFS のためのデータ構造
    //vector<vector<int>> done(405, vectot<int>(405, -1)); // 全頂点を「未訪問」に初期化
    queue<pair<int, int>> que;
 
    // 初期条件 (頂点 0 を初期ノードとする)
    ans.at(0).at(0) = 0;
    que.push(make_pair(0, 0)); // 0 を橙色頂点にする
 
    int x, y, cur_x, cur_y;
    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        pair<int, int> v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        cur_x = v.first;
        cur_y = v.second;
 
        // v から辿れる頂点をすべて調べる
        for(int i = 0; i < cnt; i++) {
            x = fx.at(i);
            y = fy.at(i);
            if (cur_x+x>=n || cur_y+y >=n) {
                continue;
            }
            if(ans.at(cur_x+x).at(cur_y+y) != -1) {
                continue;
            }
            ans.at(cur_x+x).at(cur_y+y) = ans.at(cur_x).at(cur_y) + 1;
            que.push(make_pair(cur_x+x, cur_y+y));
        }
 
        for(int i = 0; i < cnt; i++) {
            x = fx.at(i);
            y = fy.at(i);
            if (cur_x-x<0 || cur_y+y >=n) {
                continue;
            }
            if(ans.at(cur_x-x).at(cur_y+y) != -1) {
                continue;
            }
            ans.at(cur_x-x).at(cur_y+y) = ans.at(cur_x).at(cur_y) + 1;
            que.push(make_pair(cur_x-x, cur_y+y));
        }
 
        for(int i = 0; i < cnt; i++) {
            x = fx.at(i);
            y = fy.at(i);
            if (cur_x-x<0 || cur_y-y < 0) {
                continue;
            }
            if(ans.at(cur_x-x).at(cur_y-y) != -1) {
                continue;
            }
            ans.at(cur_x-x).at(cur_y-y) = ans.at(cur_x).at(cur_y) + 1;
            que.push(make_pair(cur_x-x, cur_y-y));
        }
 
        for(int i = 0; i < cnt; i++) {
            x = fx.at(i);
            y = fy.at(i);
            if (cur_x+x>=n || cur_y-y<0) {
                continue;
            }
            if(ans.at(cur_x+x).at(cur_y-y) != -1) {
                continue;
            }
            ans.at(cur_x+x).at(cur_y-y) = ans.at(cur_x).at(cur_y) + 1;
            que.push(make_pair(cur_x+x, cur_y-y));
        }
        
    }
 
}
 
 
int main()
{
    int n, m, tmp;
    cin >> n >> m;
 
    for (int i = 0; i*i <= m; i++) {
        tmp = sqrt(m - i*i);
        if (tmp*tmp == m - i*i) {
            fx.push_back(i);
            fy.push_back(sqrt(m - i*i));
            cnt++;
        }
    }
 
    // for (int i = 0; i < cnt; i++) {
    //     cout << fx.at(i) << " " << fy.at(i) << endl;
    // }
 
    bfs(cnt, n);
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans.at(i).at(j) << " ";
        }
        cout << endl;
    }
 
    return 0;
}