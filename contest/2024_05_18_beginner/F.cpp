#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 与えられた配列のLISを求める関数
vector<int> findLIS(const vector<int>& A) {
    vector<int> lis;
    vector<int> dp(A.size(), 0);
    for (int i = 0; i < A.size(); ++i) {
        auto it = lower_bound(lis.begin(), lis.end(), A[i]);
        if (it == lis.end()) {
            lis.push_back(A[i]);
        } else {
            *it = A[i];
        }
        dp[i] = distance(lis.begin(), it) + 1;
    }
    return dp;
}

// LISに含まれるかをチェックする関数
vector<int> checkLIS(const vector<int>& A, const vector<int>& lis_left, const vector<int>& lis_right) {
    int n = A.size();
    int lis_length = lis_left[n - 1];
    vector<int> result;
    
    for (int i = 0; i < n; ++i) {
        if (lis_left[i] + lis_right[i] - 1 == lis_length) {
            result.push_back(i + 1); // 1-indexed
        }
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        vector<int> lis_left = findLIS(A);
        reverse(A.begin(), A.end());
        vector<int> lis_right = findLIS(A);
        reverse(lis_right.begin(), lis_right.end());
        
        vector<int> lis_elements = checkLIS(A, lis_left, lis_right);
        
        cout << lis_elements.size() << endl;
        for (int i : lis_elements) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}
