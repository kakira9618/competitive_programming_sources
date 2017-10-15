// M - 家: http://tdpc.contest.atcoder.jp/tasks/tdpc_house
// 1階からH階に昇ると考えても良い。昇ることにする。
// まず、フロア内にて、部屋sから部屋tに同じ部屋を2度通らずに行く場合の数を求める。これをA[s][t]とする。
// これを求めるには、dp[i][j] := 現在部屋iに居て、今までに通ってきた部屋の集合がjの場合
// として、dp[i][j] = \sum_k dp[k][j & ~(1 << k)] (ただしj >> k & 1は1)　を計算すれば良い。(c.f. 巡回セールスマン問題)
// また、A[s][t] = \sum_k dp[t][k] (ただしk >> t & 1は1, dp[s][1 << s] = 1) となる。
//
// 次に、1階の部屋1から、h階の部屋iに行く場合の数をb^h[i]とする。(h=0のときb^0[i] = 1 (i=0), or 0 (i!=0) )
// このとき、
// Ab^h = b^{h+1}
// が成り立つ。よって、b^H = A^H b^0 = A^H[1][1]となる。
// A^Hは行列べき乗であるので、行列のサイズがR\times Rのとき、O(R^3 log H)で計算できる。（高速に計算する方法もある（c.f. きたまさ法）が、今回は必要ない）
// 行列積の内部でスカラーの積を計算する。ここでオーバーフローしないように気をつける。
// 全体 O(R^3(2^R + log H)) (R=16のとき実行時間が少し長いが、制約時間が8秒と長いので間にあう)

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

using Mat = vector<vector<int>>;

// A, B must be N * N
Mat matmul(Mat &A, Mat &B, int mod) {
    int N = A.size();
    Mat ret(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += ((ll)A[i][k] * B[k][j]) % mod; // オーバーフロー注意
                sum %= mod;
            }
            ret[i][j] = sum;
        }
    }
    return ret;
}

vector<vector<int> > matpow(Mat &A, ull p, int mod) {
    int N = A.size();
    Mat ret(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        ret[i][i] = 1;
    }
    while(p > 0) {
        if (p & 1) {
            ret = matmul(A, ret, mod);
        }
        A = matmul(A, A, mod);
        p >>= 1;
    }
    return ret;
}

Mat calcFloorMat(Mat &G, int mod) {
    int R = G.size();
    vector<vector<int> > A(R, vector<int>(R, 0));
    for (int i = 0; i < R; i++) {
        Mat dp(R, vector<int>(1 << R, 0));
        dp[i][1 << i] = 1;
        for (int j = 0; j < 1 << R; j++) {
            for (int s = 0; s < R; s++) {
                if (!(j >> s & 1)) continue;
                for (int t = 0; t < R; t++) {
                    if (!(j >> t & 1) && G[s][t]) {
                        dp[t][j | (1 << t)] += dp[s][j];
                        dp[t][j | (1 << t)] %= mod;
                    }
                }
            }
        }
        for (int t = 0; t < R; t++) {
            int sum = 0;
            for (int j = 0; j < 1 << R; j++) {
                if (j >> t & 1) {
                    sum += dp[t][j];
                    sum %= mod;
                }
            }
            A[i][t] = sum;
        }
    }
    return A;
}

int main() {
    const int mod = 1000000007;
    ull H; int R;
    cin >> H >> R;
    Mat G(R, vector<int>(R, 0));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R; j++) {
            cin >> G[i][j];
        }
    }
    Mat A = calcFloorMat(G, mod);
    Mat A_h = matpow(A, H, mod);
    cout << A_h[0][0] << endl;
    return 0;
}