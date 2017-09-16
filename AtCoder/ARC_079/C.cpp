// C - Cat Snuke and a Voyage: https://beta.atcoder.jp/contests/arc079/tasks/arc079_a
// 始点から1便で行ける島と終点から1便で行ける島のリストを作り、共通部分があるかどうかを調べる

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
    int N, M;
    cin >> N >> M;
    vector<int> flag1(N + 1, 0);
    vector<int> flag2(N + 1, 0);
    flag1[1] = true;
    flag2[N] = true;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (a == 1) {
            flag1[b] = 1;
        }
        if (b == N) {
            flag2[a] = 1;
        }
    }
    bool flag = false;
    for (int i = 1; i <= N; i++) {
        if (flag1[i] && flag2[i]) {
            flag = true;
        }
    }
    if (flag) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}