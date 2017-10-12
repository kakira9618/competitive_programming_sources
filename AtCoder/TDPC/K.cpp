// K - ターゲット: http://tdpc.contest.atcoder.jp/tasks/tdpc_target
// 円の左端の降順にソートする。この状態において、右端の座標のLIS (Longest Increasing Subsequence)が答えとなる。
// （円aが他の円bに含まれる <=> bの左端 < aの左端 かつ aの右端 < bの右端 で、左端順にソートしているのでbの左端 < aの左端の条件は常に満たす）
// LISはO(NlogN)の実装でなければならない。

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
 
struct circle {
    ll l, r;
};
 
int lis(vector<ll> &A) {
    vector<ll> dp;
    for(int i = 0; i < A.size(); i++) {
        int k = lower_bound(all(dp), A[i]) - dp.begin();
        if (k == dp.size()) {
            dp.push_back(A[i]);
        } else {
            dp[k] = A[i];
        }
    }
    return dp.size();
}
 
int main() {
    int N;
    cin >> N;
    vector<circle> C;
    for (int i = 0; i < N; i++) {
        ll x, r;
        cin >> x >> r;
        C.push_back((circle){x - r, x + r});
    }
 
    sort(all(C), [](circle a, circle b){
        if (a.l != b.l) return a.l > b.l;
        else return a.r > b.r;
    });
    vector<ll> A;
    for (int i = 0; i < N; i++) {
        A.push_back(C[i].r);
    }
    cout << lis(A) << endl;
 
    return 0;
}