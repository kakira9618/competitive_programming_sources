// H - ナップザック: http://tdpc.contest.atcoder.jp/tasks/tdpc_knapsack
// 色の昇順にソートしても結果は変わらない。ソートすると、色昇順に品物をチェックしたとき、最後に入れたものと比較して色が変わっている品物を入れた場合に合計の色数が1増えることがわかる。
// よって、dp[i][j][k][l] := i番目までの品物を見たときに、重さがjで、色の総数がk種、すでにi番目の品物と同じ色の品物を選択済みか(l=0: まだ, l=1: 選択済み)　としてDPすればよい。
// メモリ制限があるので、dp[i]とdp[i + 1]の間の関連性しか使わないことを利用して、dp[i]とdp[i + 1]でdp配列を再利用する。

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
 
struct good {
    int w, v, c;
};
 
int dp[2][10001][51][2];
int main() {
    int N, W, C;
    cin >> N >> W >> C;
    vector<good> G;
    for (int i = 0; i < N; i++) {
        int w, v, c;
        cin >> w >> v >> c;
        G.push_back((good){w, v, c});
    }
    sort(all(G), [](good a, good b){return a.c < b.c;});

    memset((int *)dp, -1, sizeof(int) * 2 * 10001 * 51 * 2); // 到達し得ない場所には-1を入れておく
    
    dp[0][0][0][0] = 0;
    for(int i = 0; i < N; i++) {
        int i_ = i % 2; // 現在
        int i__ = (i + 1) % 2; // 遷移先
        for(int j = 0; j < 10001; j++) {
            for(int k = 0; k < 51; k++) {
                
                // 品物を選択しない場合
                if (i == N - 1 || G[i].c != G[i + 1].c) { 
                    // この選択後、次の品物の色が変わる場合
                    if (dp[i_][j][k][0] != -1) dp[i__][j][k][0] = max(dp[i__][j][k][0], dp[i_][j][k][0]);
                    if (dp[i_][j][k][1] != -1) dp[i__][j][k][0] = max(dp[i__][j][k][0], dp[i_][j][k][1]);
                } else {
                    // この選択後も、次の品物の色が変わらない場合
                    if (dp[i_][j][k][0] != -1) dp[i__][j][k][0] = max(dp[i__][j][k][0], dp[i_][j][k][0]);
                    if (dp[i_][j][k][1] != -1) dp[i__][j][k][1] = max(dp[i__][j][k][1], dp[i_][j][k][1]);
                }
 
                if (!(j + G[i].w < 10001 && k + 1 < 51)) continue;
                
                // 品物を選択する場合
                if (i == N - 1 || G[i].c != G[i + 1].c) {
                    if (dp[i_][j][k][0] != -1) dp[i__][j + G[i].w][k + 1][0] = max(dp[i__][j + G[i].w][k + 1][0], dp[i_][j][k][0] + G[i].v);
                    if (dp[i_][j][k][1] != -1) dp[i__][j + G[i].w][k][0] = max(dp[i__][j + G[i].w][k][0], dp[i_][j][k][1] + G[i].v);
                }  else {
                    if (dp[i_][j][k][0] != -1) dp[i__][j + G[i].w][k + 1][1] = max(dp[i__][j + G[i].w][k + 1][1], dp[i_][j][k][0] + G[i].v);
                    if (dp[i_][j][k][1] != -1) dp[i__][j + G[i].w][k][1] = max(dp[i__][j + G[i].w][k][1], dp[i_][j][k][1] + G[i].v);
                }
            }
        }
        memset((int *)(dp + i_), -1, sizeof(int) * 10001 * 51 * 2); // 現在の部分の配列を再利用
    }
 
    int ans = 0;
    for (int j = 0; j <= W; j++) {
        for (int k = 0; k <= C; k++) {
            for (int l = 0; l < 2; l++) {
                ans = max(ans, dp[N % 2][j][k][l]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
