// C - pushpush: https://beta.atcoder.jp/contests/arc077/tasks/arc077_a
// 実装問題。dequeを用いると簡単にかける。

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <memory>
#include <functional>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
 
    deque<int> B;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            B.push_back(A[i]);
        } else {
            B.push_front(A[i]);
        }   
    }
 
    if (n % 2 == 1) {
        for (int i = n - 1; i >= 0; i--) {
            cout << B[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << B[i] << " ";
        }
        cout << endl;
    }
 
    return 0;
}