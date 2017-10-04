// F - 準急: http://tdpc.contest.atcoder.jp/tasks/tdpc_semiexp
// A[i][j] := i番目の駅まで考えたとき、現在連続でj駅泊まっている場合の数
// とすると、A[i+1][j+1]=A[i][j]となることから、A[i][j]=A[i-j][0]が導ける。
// これにより、dp[i] := A[i][0]とすると一次元のdpをすることで解ける。
// i>=2においてdp[i + 1] = dp[i] + dp[i - 1] + ... + dp[i - (K - 1)]となる。
// これから更に、dp2[i] := dp[i + 1] - dp[i] とするとdpを効率的に計算できるが、ここではそうせずに尺取法のように和を更新している。

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
const int mod = 1000000007;
 
// A[i][j] := i番目まで考えたとき、現在連続でj駅泊まっている場合の数
// A[0][0] = 1, A[1][0] = 0, dp[N][0] = 0
// A[i + 1][j + 1] = A[i][j]
// A[i + 1][0] = A[i][0] + A[i][1] + ... + A[i][K - 1]
// 求めるもの: A[N][0] + A[N][1] + ... + A[N][K - 1]
//
// A[i + 1][j + 1] = A[i][j] から、 A[i][j] = A[i - j][0]
// A[i + 1][0] = A[i][0] + A[i - 1][1] + ... + A[i - (K - 1)][0]
// 求めるもの: A[N][0] + A[N - 1][0] + ... + A[N - (K - 1)][0]
//
// dp[i] := A[i][0]
// dp[0] = 1, dp[1] = 0, dp[N] = 0
// dp[i + 1] = dp[i] + dp[i - 1] + ... + dp[i - (K - 1)]
// 求めるもの: dp[N + 1]
int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> dp(N + 2, 0);
    dp[0] = 1;
    ll sum = 1;
    for(int i = 1; i < K; i++) {
        sum = (sum + dp[i]) % mod;
        dp[i + 1] = sum;
    }
    for (int i = K; i <= N; i++) {
        if (i == N) {
            sum = (sum - dp[N] + mod) % mod; // N番目の駅には必ず止まる
        }
        sum = (sum + dp[i] - dp[i - K] + mod) % mod; // sum + dp[i] + mod が INT_MAXを超えうることに注意
        dp[i + 1] = sum;
    }
    cout << dp[N + 1] << endl; 
 
    return 0;
}