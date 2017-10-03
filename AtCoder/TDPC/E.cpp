// E - 数: http://tdpc.contest.atcoder.jp/tasks/tdpc_number
// dp[i][j][k] := 大きい桁から数えてj桁目までの和のmod Dがkで、今までにNより小さい数字をつかっている(i=1)もしくはいない(i=0)場合の数
// 大きい桁から考え、一度でもNのj桁目より小さい数を使った場合、j+1桁以降の桁kではNのk桁目より大きい数が使える。このためのフラグを用意する必要がある。
// 最後に-1しているのは、0がカウントされてしまっているため。

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
 
int main() {
    string N;
    int D;
    cin >> D >> N;
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(N.size() + 1, vector<int>(D, 0)));
    dp[0][0][0] = 1;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < N.size(); j++) {
            for(int k = 0; k < D; k++) {
                if (i == 0) {
                    for(int l = 0; l < N[j] - '0'; l++) {
                        dp[1][j + 1][(k + l) % D] += dp[i][j][k];
                        dp[1][j + 1][(k + l) % D] %= mod;
                    }
                    dp[0][j + 1][(k + N[j] - '0') % D] += dp[i][j][k];
                    dp[0][j + 1][(k + N[j] - '0') % D] %= mod;
                } else {
                    for(int l = 0; l < 10; l++) {
                        dp[1][j + 1][(k + l) % D] += dp[i][j][k];
                        dp[1][j + 1][(k + l) % D] %= mod;
                    }
                }
            }
        }
    }
    cout << (dp[0][N.size()][0] + dp[1][N.size()][0] - 1) % mod << endl;
    return 0;
}