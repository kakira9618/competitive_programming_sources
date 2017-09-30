// B - ゲーム: http://tdpc.contest.atcoder.jp/tasks/tdpc_game
// dp[i][j] := A個の山からi個、B個の山からj個取られている場合のすぬけ君が得られる価値の合計の最大値
// として、現在のターンがすぬけ君かすめけ君かでmin, maxを変える。実装はメモ化再帰。O(AB)

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
 
int dp[1001][1001];
 
int N, M;
vector<int> A, B;
int dfs(int i, int j, int turn) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == N && j == M) return dp[i][j] = 0;
    if (turn == 0) {
        if (i == N) return dp[i][j] = dfs(i, j + 1, 1 - turn) + B[j];
        if (j == M) return dp[i][j] = dfs(i + 1, j, 1 - turn) + A[i];
        return dp[i][j] = max(dfs(i + 1, j, 1 - turn) + A[i], dfs(i, j + 1, 1 - turn) + B[j]);
    } else {
        if (i == N) return dp[i][j] = dfs(i, j + 1, 1 - turn);
        if (j == M) return dp[i][j] = dfs(i + 1, j, 1 - turn);
        return dp[i][j] = min(dfs(i + 1, j, 1 - turn), dfs(i, j + 1, 1 - turn));
    }
    return dp[i][j];
}
 
int main() {
    cin >> N >> M;
    A.resize(N); B.resize(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            dp[i][j] = -1;
        }
    }
    cout << dfs(0, 0, 0) << endl;
 
    return 0;
}