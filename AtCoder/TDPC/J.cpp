// J - ボール: http://tdpc.contest.atcoder.jp/submissions/1634679
// dp[X]: ボールの状態がX（Xのibit目が、ものがx=iに置かれているかを示す）のとき、投げるボールの期待値　とする
// Xの連続する3bitを見たとき、立っているビット数をsとすると、その場所に向かってボールを投げる場合、期待値は
// 立っているビットのうちどれか1つを倒した場合の期待値の合計/s + 3/s …★
// となる。これらのmaxを取れば良い。
//
// [★の例]
// E[11001] = max(  (E[01001] + E[10001] + E[11001]) / 3 + 1
//                 ,(E[10001] + E[11001] + E[11001]) / 3 + 1
//                 ,(E[11001] + E[11001] + E[11000]) / 3 + 1 )
// 各候補について、E[11001]を左辺に移項すると、★の式となる


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
    int target = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        target |= 1 << x;
    }
    vector<double> dp(1 << 16, 1e30);
    dp[0] = 0;
    for(int i = 1; i < 1 << 16; i++) {
        for(int j = 1; j < 15; j++) {
            int cnt = 0;
            double sum = 0;
            for(int k = -1; k <= 1; k++) {
                if (i >> (j + k) & 1) {
                    cnt++;
                    sum += dp[i & ~(1UL << (j + k))];
                }
            }
            if (cnt == 0) continue;
            dp[i] = min(dp[i], sum / cnt + 3.0 / cnt);
        }
    }
    printf("%.9f\n", dp[target]);
 
    return 0;
}