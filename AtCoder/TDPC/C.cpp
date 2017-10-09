// C - トーナメント: http://tdpc.contest.atcoder.jp/tasks/tdpc_tournament
// dp[k][i]: 第kラウンドでi番目の人が勝つ確率としてDP。
// kラウンド目において、i番目の人が戦いうる相手は、i & ~((1 << k) - 1)　+ (1 << (k - 1)) 番目から i & ~((1 << k) - 1)　+ (1 << k) 番目まで。

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
 
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};
 
int main() {
    int K;
    cin >> K;

    
    vector<int> R;
    for(int i = 0; i < 1 << K; i++) {
        int r;
        cin >> r;
        R.push_back(r);
    }
    vector<vector<double> > dp(K + 1, vector<double>(1 << K, 0));
    for (int i = 0; i < 1 << K; i++) {
        dp[0][i] = 1;
    }
 
    for(int k = 1; k <= K; k++) {
        for(int i = 0; i < 1 << K; i++) {
            for (int j = i & ~((1 << k) - 1); j < (i & ~((1 << k) - 1)) + (1 << k); j++) {    
                if (((i >> (k - 1)) & 1) == ((j >> (k - 1)) & 1)) continue;
                dp[k][i] += dp[k - 1][i] * dp[k - 1][j] * (1.0 / (1.0 + pow(10, (R[j] - R[i]) / 400.0)));
            }
        }
    }
 
    for(int i = 0; i < 1 << K; i++) {
        cout << std::setprecision(10) << dp[K][i] << endl;
    }
 
    return 0;
}