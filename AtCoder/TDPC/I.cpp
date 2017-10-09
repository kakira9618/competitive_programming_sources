// I - イウィ: http://tdpc.contest.atcoder.jp/tasks/tdpc_iwi
// dp[i][j] = 区間[i, j)において、消せるiwiの数の最大とする
// dp[i][j] = max(max_k (dp[i][k] + dp[k][j]), dp[i+2][j-1]+1 (左端2個と右端1個に挟まれた全てが消えて、端も消える場合), dp[i+1][j-2]+1 (左端1個と右端2個に挟まれた全てが消えて、端も消える場合)
// となる。
// 類似: ICPC 2016 国内予選 D

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
 
string S;
// [i, j)
int dp[301][301];
int dfs(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    if (j - i < 3) return dp[i][j] = 0;
    if (j - i == 3) {
        if (S[i] == 'i' && S[i + 1] == 'w' && S[i + 2] == 'i') return dp[i][j] = 1;
        return dp[i][j] = 0;
    }
    int ret = 0;
    for(int k = i + 1; k < j; k++) {
        ret = max(ret, dfs(i, k) + dfs(k, j));
    }
    if (dfs(i + 2, j - 1) * 3 == j - i - 3) {
        if (S[i] == 'i' && S[i + 1] == 'w' && S[j - 1] == 'i') {
            ret = max(ret, dfs(i + 2, j - 1) + 1);
        }
    }
    if (dfs(i + 1, j - 2) * 3 == j - i - 3) {
        if (S[i] == 'i' && S[j - 2] == 'w' && S[j - 1] == 'i') {
            ret = max(ret, dfs(i + 1, j - 2) + 1);
        }
    }
    return dp[i][j] = ret;
}
 
int main() {
    for (int i = 0; i < 301; i++) {
        for (int j = 0; j < 301; j++) {
            dp[i][j] = -1;
        }
    }
    cin >> S;
    cout << dfs(0, S.size()) << endl;
    return 0;
}