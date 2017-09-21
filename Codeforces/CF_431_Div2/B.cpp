// B - Tell Your World: http://codeforces.com/contest/849/problem/B
// 難問だと思う。考える直線は(1,2)番目を結ぶ直線、(1,3)番目を結ぶ直線、(2,3)番目を結ぶ直線で十分
//  1が単独ならばもう一つの直線は2番目と3番目は必ず通る必要がある。1番目が単独でないならば、1番目と"2番目か3番目のどちらか"を必ず通る
// 直線に乗っている点集合を返す関数を作ると楽。導出は直線の式を変形して、分母を消す（doubleは避けたい）
// さらに、int型だとオーバーフローするので注意

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
  
const long long int INF= (long long int)1e15 + 1;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

/*
y=ax+b
y_1=ax_1+b
y_2=ax_2+b\
a=(y_1-y_2)/(x_1-x_2)
b=(-y_1x_2+x_1y_2)/(x_1-x_2)
y=x(y_1-y_2)/(x_1-x_2)+(-y_1x_2+x_1y_2)/(x_1-x_2)
(x_1-x_2)y=x(y_1-y_2)+(-y_1x_2+x_1y_2)
*/
vector<int> retidxs(vector<int> &Y, int ind1, int ind2) {
    ll x1 = ind1;
    ll x2 = ind2;
    ll y1 = Y[ind1];
    ll y2 = Y[ind2];
    vector<int> ret(Y.size());
    for (int i = 0; i < Y.size(); i++) {
        ll x = i;
        ll y = Y[i];
        if (y * (x1 - x2) == x * (y1 - y2) + (-y1 * x2 + x1 * y2)) ret[i] = 1;
    }
    return ret;
}
bool ok(vector<int> &Y, int ind1, int ind2) {
    vector<int> idxs1 = retidxs(Y, ind1, ind2);
    int ind3 = -1, ind4 = -1;
    for (int i = 0; i < Y.size(); i++) {
        if (!idxs1[i]) {
            if (ind3 == -1) {
                ind3 = i;
            } else {
                ind4 = i;
                break;
            }
        }
    }
    //cout << ind3 << ", " << ind4 << endl;
    if (ind3 == -1 && ind4 == -1) return false;
    if (ind3 != -1 && ind4 == -1) return true;
    vector<int> idxs2 = retidxs(Y, ind3, ind4);
    for (int i = 0; i < Y.size(); i++) {
        if (idxs1[i] == 0 && idxs2[i] == 0) {
            return false;
        }
    }
    //dx1:dy1=dx2:dy2
    //dy1*dx2=dx1*dy2
    ll dx1 = ind2 - ind1;
    ll dx2 = ind4 - ind3;
    ll dy1 = Y[ind2] - Y[ind1];
    ll dy2 = Y[ind4] - Y[ind3];
    if (dy1 * dx2 == dx1 * dy2) {
        return true;
    } 
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<int> Y(N);
    for (int i = 0; i < N; i++) {
        cin >> Y[i];
    }
    if (ok(Y, 0, 1) || ok(Y, 0, 2) || ok(Y, 1, 2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}