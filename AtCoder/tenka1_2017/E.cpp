// E - CARtesian Coodinate: http://tenka1-2017.contest.atcoder.jp/tasks/tenka1_2017_e
// x,y座標は独立に考えて良い。答えは、N(N-1)/2箇所の交点の中で、floor(N(N-1)/4)番目の交点。
//   -> \sum_i |s - X[i]| は、sが+dxだけ動いた時、sより大きいX[i]に1個あたりdxだけ減り、sより小さいX[i]1個あたりdxだけ増える
// x座標を求めることを考える。y軸に平行な直線Qを考えると、x=(十分に小さい値) と、与えられる直線との交点は、与えられる直線の傾きが小さいほどy座標が大きい。
// 一方、x=s と、与えられる直線の交点の座標を求めることができる。これらの頂点の座標の大きさの順番が変わった数だけ、交点が存在する。
// これは転倒数に他ならないから、BITを使うことで、O(NlogN)で計算できる。
// y=sについて二分探索して、転倒数がfloor(N(N-1)/4)以上となるような範囲を求める。

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
 
struct Line {
    double a, b, c;
};
 
struct BIT {
    int N;
    vector<int> bit;
    BIT(int n) : N(n), bit(N + 1){}
    void add(int a, int w) {
        for(int x = a; x < N; x |= x + 1) {
            bit[x] += w;
        }
    }
    int sum(int a) {
        int ret = 0;
        for(int x = a - 1; x >= 0; x = (x & (x + 1)) - 1) {
            ret += bit[x];
        }
        return ret;
    }
};
 
ll getTransNum(vector<int> &r) {
    BIT bit(r.size());
    ll ret = 0;
    for(int i = 0; i < r.size(); i++) {
        ret += i - bit.sum(r[i]);
        bit.add(r[i], 1);
    }
    return ret;
}
 
bool ok(vector<Line> &L, double c, bool vertical) {
    vector<pair<double, int>> L_c;
    if (vertical) {
        for (int i = 0; i < L.size(); i++) {
            // Ax+By=C
            // By=C-Ax
            // y=(C-Ax)/B
            double y = (L[i].c - L[i].a * c) / L[i].b;
            L_c.push_back(mp(y, i));
        }
    } else {
        for (int i = 0; i < L.size(); i++) {
            // Ax+By=C
            // Ax=C-By
            // x=(C-By)/A
            double x = (L[i].c - L[i].b * c) / L[i].a;
            L_c.push_back(mp(x, i));
        }
    }
 
    sort(L_c.begin(), L_c.end());
    vector<int> r;
    for (int i = 0; i < L_c.size(); i++) {
        r.push_back(L_c[i].second);
    }
 
    ll n = getTransNum(r);
    int minn = L.size() * (L.size() - 1) / 2;
    if (minn % 2 == 0) {
        minn = minn / 2;
    } else {
        minn = minn / 2 + 1;
    }
    return n >= minn;
}
 
int main() {
    int N;
    cin >> N;
    vector<Line> L;
    for (int i = 0; i < N; i++) {
        double a, b, c;
        cin >> a >> b >> c;
        L.push_back((Line){a, b, c});
    }
    vector<Line> L_x = L;
    vector<Line> L_y = L;
    sort(L_x.begin(), L_x.end(), [](Line &lhs, Line &rhs){return lhs.a / lhs.b < rhs.a / rhs.b;});
    sort(L_y.begin(), L_y.end(), [](Line &lhs, Line &rhs){return lhs.b / lhs.a < rhs.b / rhs.a;});
 
    double ans_x, ans_y;
    double a = -1e30;
    double b = 1e30;
    for (int i = 0; i < 200; i++) {
        double c = (a + b) / 2;
        if (ok(L_x, c, true)) {
            b = c;
        } else {
            a = c;
        }
    }
    ans_x = b;
    
    a = -1e30, b = 1e30;
    for (int i = 0; i < 200; i++) {
        double c = (a + b) / 2;
        if (ok(L_y, c, false)) {
            b = c;
        } else {
            a = c;
        }
    }
    ans_y = b;
 
    printf("%.15f %.15f\n", ans_x, ans_y);
    return 0;
}