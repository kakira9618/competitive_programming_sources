// D - IntegerotS: http://tenka1-2017.contest.atcoder.jp/tasks/tenka1_2017_d
// K以下の整数 <=> Kと同じまたは、Kのkビット目が1の時、k+1ビット以上はKと同じかつkビット目が0かつk-1ビット以下が任意であるような整数
// bitwise-orを取ってK以下の整数になるような組み合わせは、K以下の整数の候補に対して、貪欲に整数を選択したときを調べれば良い。

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
 
bool ok(ll K, ll a) {
    bool flag = true;
    for(int j = 0; j <= 30; j++) {
        if ((!((K >> j) & 1)) && ((a >> j) & 1)) {
            flag = false;
            break;
        } 
    }
    return flag;
}
 
int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
 
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (ok(K, A[i])) {
            ans += B[i];
        }
    }
    for (int k = 0; k <= 30; k++) {
        if (K >> k & 1) {
            ll sum = 0;
            ll newK = (K & ~(1 << k));
            if (k > 0) newK |= ((1 << k) - 1);
            for (int i = 0; i < N; i++) {
                if (ok(newK, A[i])) {
                    sum += B[i];
                }
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}