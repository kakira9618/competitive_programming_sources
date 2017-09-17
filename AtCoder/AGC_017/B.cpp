//B - Moderate Differences: http://agc017.contest.atcoder.jp/tasks/agc017_b
//上げるor下げる幅が決まっていれば順番は関係ない。iを動かし、上げるのがi回、下げるのがN-i-1回の場合において、最小の場合と最大の場合の中にBが入っていればOK。
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
    long long N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
 
    for (int i = 0; i < N; i++) {
        long long ma = A + i * D - (N - 1 - i) * C;
        long long mi = A + i * C - (N - 1 - i) * D;
        if (B >= mi && B <= ma) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
 
    return 0;
}