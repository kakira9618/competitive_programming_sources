// N - 木: http://tdpc.contest.atcoder.jp/tasks/tdpc_tree
// 木を根をiとする根付き木として見る。
// dp[j] := 頂点jを親とする木の作り方
// とすると、dp[j] = (\prod_k dp[k]) ((\sum_k size(k))! / \prod_k (size(k)!))
// となる。ここで、kはjの子、size(k)はkを親とする木のサイズである。
// [導出]
// 　jの子は、jの後であればどのような順番で選択しても良い。jの子をk、kを親とする木のサイズをsize(k)とすると、
// 　(\prod_k dp[k])　はそれぞれの子がつくる木の中での選び方
// 　((\sum_k size(k))! / \prod_k (size(k)!)) はそれらをどのような順番で置くか（色iのボールがs_i個ある場合のボールの並べ方に等しい）
// 答えは、根を変えてdp配列を再計算し、dp[根]の値を足すと計算できる。
// 「割り算」はdp配列を計算するときにも出て来るが、もちろん逆元を使った方法でないと不可であることに注意。
// さらに、3->4に向かって線を引く場合と4->3に向かって線を引く場合は区別しないため、答えを2で割る必要がある（この時も忘れずに逆元を掛けること）。

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

void calcchild(const int v, const vector<vector<int>> &E, vector<int> &visit, vector<vector<int>> &child) {
    visit[v] = 1;
    for(int i = 0; i < E[v].size(); i++) {
        if (!visit[E[v][i]]) {
            child[v].push_back(E[v][i]);
            calcchild(E[v][i], E, visit, child);
        }
    }
}

int calcsize(const int v, const vector<vector<int>> &child, vector<int> &size) {
    if (child[v].size() == 0) return size[v] = 1;
    if (size[v] != 0) return size[v];
    int ret = 1;
    for (int i = 0; i < child[v].size(); i++) {
        ret += calcsize(child[v][i], child, size);
    }
    return size[v] = ret;
}

int modpow(int a, int p, int mod) {
    int ret = 1;
    while(p > 0) {
        if (p & 1) {
            ret = ((ll)ret * a) % mod;
        }
        a = ((ll)a * a) % mod;
        p >>= 1;
    }
    return ret;
}

int calcperm(const int n, vector<int> &p, const int mod) {
    p[0] = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = (((ll)p[i - 1]) * i) % mod;
    }
}

int dfs(const int v, vector<int> &dp, const vector<vector<int>> &child, const vector<int> &size, const vector<int> &p, const int mod) {
    if (size[v] == 1) return dp[v] = 1;
    ll ret = 1;
    int n = 0, d = 1;
    for(int i = 0; i < child[v].size(); i++) {
        const int u = child[v][i];
        ret = ret * dfs(u, dp, child, size, p, mod) % mod;
        n += size[u];
        d = ((ll)d * p[size[u]]) % mod;
    }
    return dp[v] = ((ret * p[n]) % mod * modpow(d, mod - 2, mod)) % mod;
}

int main() {
    int N;
    cin >> N;
    
    const int mod = 1000000007;
    vector<int> p(N + 1, 0);
    calcperm(N, p, mod);

    vector<vector<int>> E(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) { // 親: i
        vector<vector<int>> child(N, vector<int>());
        vector<int> visit(N, 0);
        calcchild(i, E, visit, child);

        vector<int> size(N, 0);
        calcsize(i, child, size);

        vector<int> dp(N, 0);
        dfs(i, dp, child, size, p, mod);

        ans += dp[i];
        ans %= mod;
    }
    cout << ((ll)ans * modpow(2, mod - 2, mod)) % mod << endl;

    return 0;
}