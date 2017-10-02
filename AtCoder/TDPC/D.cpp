// D - サイコロ: http://tdpc.contest.atcoder.jp/tasks/tdpc_dice
// dp[i][j][k][l]: サイコロをi回振った時、その積の因数のうち2がj個、3がk個、5がl個であるような確率
// Kを素因数分解したときの因数2,3,5の数をJ, K, Lとすると、sum_{j>=J, k>=K, l>=L} dp[N][j][k][l] が解となる
// しかし、K, Lは最悪100, Jは最悪200まであり得るため、j>=J以降のノードはJと同一視する（他も同様）

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
 
// template<typename T>
// vector<T> vectab(int n, T v) { return vector<T>(n, v); }
 
// template <class... Args>
// auto vectab(int n, Args... args) {
//   auto val = vectab(args...);
//   return vector<decltype(val)>(n, move(val));
// }
 
double dp[101][65][40][30];
int main() {
    int N; 
    ull D;
    cin >> N >> D;
    int f[3] = {2, 3, 5};
    int cnt[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++) {
        while(D % f[i] == 0) {
            D /= f[i];
            cnt[i]++;
        }
    }
    if (D != 1ULL) {
        cout << "0" << endl;
        return 0;
    }
    dp[0][0][0][0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= cnt[0]; j++) {
            for(int k = 0; k <= cnt[1]; k++) {
                for(int l = 0; l <= cnt[2]; l++) {
                    double a = dp[i][j][k][l] / 6.0;
                    dp[i + 1][j][k][l] += a;
                    dp[i + 1][min(cnt[0], j + 1)][k][l] += a;
                    dp[i + 1][j][min(cnt[1], k + 1)][l] += a;
                    dp[i + 1][min(cnt[0], j + 2)][k][l] += a;
                    dp[i + 1][j][k][min(cnt[2], l + 1)] += a;
                    dp[i + 1][min(cnt[0], j + 1)][min(cnt[1], k + 1)][l] += a;
                }
            }
        }
    }
    printf("%.9f\n", dp[N][cnt[0]][cnt[1]][cnt[2]]);
    return 0;
}