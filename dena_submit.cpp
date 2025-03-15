#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

#define STEP1 1
#define STEP2 2
#define STEP3 3
#define STEP4 4

void input_menus(int m, map<int, pii>& menus)
{
    for (int i = 0; i < m; i++) {
        int d, s, p;
        cin >> d >> s >> p;
        menus[d] = make_pair(s, p);
    }
}

void do_step1(map<int, pii>& menus)
{
    while (!cin.eof()) {
        string str1;
        int t, d, n;

        cin >> str1; 
        if (str1 != "order") break;
        cin >> t >> d >> n;

        if (menus[d].first < n) {
            cout << "sold out " << t << endl;
        } else {
            for (int i = 0; i < n; i++) {
                cout << "received order " << t << " " << d << endl;
            }
            menus[d].first -= n;
        }
    }
}

void do_step2(int& k, queue<int>& wait_que, map<int, int>& making)
{
    while (!cin.eof()) {
        string str1, str2;
        int t, d;

        cin >> str1; 
        if (str1 != "received" && str1 != "complete") break;
        else if (str1 == "received") {
            // 注文受理
            cin >> str2 >> t >> d;
            if (k != 0) {
                cout << d << endl;
                making[d]++;
                k--;
            } else {
                cout << "wait" << endl;
                wait_que.push(d);
            }
        } else {
            // 完成情報
            cin >> d;
            if (making[d] != 0) {
                making[d]--;
                cout << "ok";
                if (wait_que.size()) {
                    int next = wait_que.front();
                    wait_que.pop();
                    cout << " " << next << endl;
                    making[next]++;
                } else {
                    k++;
                    cout << endl;
                } 
            } else {
                cout << "unexpected input" << endl;
            }
        }
    } 
}

void do_step3(map<int, queue<int>>& ready)
{
    while (!cin.eof()) {
        string str1, str2;
        int t, d;

        cin >> str1; 
        if (str1 != "received" && str1 != "complete") break;
        else if (str1 == "received") {
            // 注文受理
            cin >> str2 >> t >> d;
            ready[d].push(t);
        } else {
            // 完成情報
            cin >> d;
            t = ready[d].front();
            ready[d].pop();

            cout << "ready " << t << " " << d << endl;
        }
    }
}

void do_step4(map<int, pii>& menus, map<int, int>& cnt, map<int, int>& sum)
{
    while (!cin.eof()) {
        string str1, str2;
        int t, d;

        cin >> str1; 
        if (str1 != "received" && str1 != "ready" && str1 != "check") break;
        else if (str1 == "received") {
            // 注文受理
            cin >> str2 >> t >> d;
            cnt[t]++;
            sum[t] += menus[d].second;
        } else if (str1 == "ready") {
            // 注文提供
            cin >> t >> d;
            cnt[t]--;
        } else {
            // 会計申請
            cin >> t;
            if (cnt[t] == 0) {
                cout << sum[t] << endl;
                sum[t] = 0; 
            } else {
                cout << "please wait" << endl;
            }
        }
    }
}


int main()
{
    int step;
    // for step1
    map<int, pii> menus;

    // for step2
    queue<int> wait_que;
    map<int, int> making;

    // for step3
    map<int, queue<int>> ready;

    // for step4
    map<int, int> cnt;
    map<int, int> sum;

    cin >> step;

    if (step == STEP1) {
        int m;
        cin >> m;

        input_menus(m, menus);
        do_step1(menus);
    } else if (step == STEP2) {
        int m, k;
        cin >> m >> k;
        
        input_menus(m, menus);
        do_step2(k, wait_que, making);
    } else if (step == STEP3) {
        int m;
        cin >> m;
        
        input_menus(m, menus);
        do_step3(ready);
    } else if (step == STEP4) {
        int m;
        cin >> m;

        input_menus(m, menus);
        do_step4(menus, cnt, sum);
    }

    return 0;

}