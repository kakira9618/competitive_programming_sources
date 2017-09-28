// A - コンテスト: http://tdpc.contest.atcoder.jp/tasks/tdpc_contest
// dp[i][j] := i問目まで見たとき、合計得点がjとなりうるか
// O(N^2 max p_i)

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
 
int dp[101][10001];
 
int main() {
    int N;
    cin >> N;
    vector<int> P(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    dp[0][0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 10001; j++) {
            if (j + P[i] < 10001) {
                dp[i + 1][j + P[i]] |= dp[i][j];
            }
            dp[i + 1][j] |= dp[i][j];
        }
    }
    int ans = 0;
    for (int j = 0; j < 10001; j++) {
        if (dp[N][j]) ans++;
    }
    cout << ans << endl;
    return 0;
}