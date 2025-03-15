#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 状態のメモ化
unordered_map<int, bool> memo;

// 状態が勝ちかどうかを判定する関数
bool canWin(int state, const vector<int>& A, const vector<int>& B, int N) {
    if (memo.find(state) != memo.end()) {
        return memo[state];
    }

    for (int i = 0; i < N; ++i) {
        if (state & (1 << i)) {
            for (int j = i + 1; j < N; ++j) {
                if (state & (1 << j)) {
                    if (A[i] == A[j] || B[i] == B[j]) {
                        int newState = state & ~(1 << i) & ~(1 << j);
                        if (!canWin(newState, A, B, N)) {
                            memo[state] = true;
                            return true;
                        }
                    }
                }
            }
        }
    }

    memo[state] = false;
    return false;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }

    int initialState = (1 << N) - 1;
    bool result = canWin(initialState, A, B, N);

    if (result) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }

    return 0;
}
