// B - Splatter Painting: https://beta.atcoder.jp/contests/agc012/tasks/agc012_b
// まず、塗りつぶし系の問題であるから、クエリを逆順に見る。逆順に見たとき、最初に塗られた色が最終的な色となる。
// dp[v][d]:= 残り幅dのクエリがvを最初に塗りつぶしたときの色としてDPすると答えが出る。
// dを加えることで、狭いクエリ(d=2)の後に広いクエリ(d=10)があったときに、すでに塗られたノードによって塗られる範囲が限定されてしまう、ような現象が起こらないようになっている。

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
 
int color[100000];
int memo[100000][11];
vector<vector<int> > G;
 
int dfs(int v, int d, int c) {
    if (memo[v][d]) return memo[v][d];
    if (d == 0) {
        return memo[v][d] = color[v] = c;
    }
    for (int i = 0; i < G[v].size(); i++) {
        dfs(G[v][i], d - 1, c);
    }
    return memo[v][d] = dfs(v, d - 1, c);
}
 
int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        G.push_back(vector<int>());
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int Q;
    cin >> Q;
    vector<int> V, D, C;
    for (int i = 0; i < Q; i++) {
        int v, d, c;
        cin >> v >> d >> c;
        v--;
        V.push_back(v);
        D.push_back(d);
        C.push_back(c);
    }
 
    for (int i = Q - 1; i >= 0; i--) {
        dfs(V[i], D[i], C[i]);
    }
 
    for (int i = 0; i < N; i++) {
        cout << color[i] << endl;
    }
 
    return 0;
}