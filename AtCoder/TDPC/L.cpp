// L - 猫: http://tdpc.contest.atcoder.jp/tasks/tdpc_cat
// dp[i][j] := i番目までの猫を見たときに、有効範囲の左端の猫がj番目であるときの解
// とすると、 dp[i][j] = (2 * sum_{j <= l <= i} f[i][l]) + (max_{k <= j} dp[i - 1][k])
// である。
//　　[漸化式の導出]
//　　状態(i, j) := i番目までの猫を見たときに、有効範囲の左端の猫がj番目である状態とする。
//　　状態(i - 1, k) -> 状態(i, j)　にジャンプする事を考える。
//　　まず、k <= jである必要がある（i-1番目の猫のx座標はi番目の猫のx座標より小さいから）
//　　逆にk <= j を満たすkであれば、ジャンプする可能性が存在する。そのようなジャンプが起こった場合、幸福度の合計の最大は、
//　　前の状態での幸福度の合計の最大 + i番目の猫が増えたことによる幸福度の増加分
//　　となる。これらのジャンプはどのジャンプを選択しても、状態(i, j)になるため、この中で最も幸福度が大きくなるようなジャンプを選択すれば良い。
//　　これをそのまま漸化式にすれば良い。
// このDPは愚直に書くとO(N^3)となるが、sum部分は累積和、max部分はその都度maxを更新していくことで、
// 各(i, j)に対しO(1)で計算できるため、全体O(N^2)でこの問題を解くことができる。
// 答えが負になりうることに注意。

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


int main() {
    int N;
    cin >> N;
    vector<vector<int>> f(N, vector<int>(N, 0));
    vector<vector<int>> dp(N + 1, vector<int>(N, -INF));
    vector<vector<int>> acc(N + 1, vector<int>(N, 0)); // acc[i][j + 1] := f[i][0] から f[i][j]までの累積和
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            cin >> f[i][j];
            sum += f[i][j];
            acc[i][j + 1] = sum;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        int ma = -INF;
        for (int j = 0; j <= i + 1; j++) {
            ma = max(ma, dp[i][j]);
            dp[i + 1][j] = ma + 2 * (acc[i][i + 1] - acc[i][j]);
        }
    }

    int ans = 0;
    for (int j = 0; j < N; j++) {
        ans = max(ans, dp[N][j]);
    }

    cout << ans << endl;

    return 0;
}