// D - Decrease (Contestant ver.): https://beta.atcoder.jp/contests/arc079/tasks/arc079_b
// K <= 50以下の場合は自明。N回操作すると全体を-1ずつ下げられる。50以上のときは、K%50個のp+1、50-K%50個のp-K%50、ただしp=(K+50*(50-1))/50とすると良い。
// p=(K+50*(50-1))/50 → N=50個全てp'のときを考える。すべて49にするのにかかる操作回数は(p'-49)*50回。(p'-49)*50がKを超えないときの最大のp'をpとする。

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
    long long int K;
    cin >> K;
 
    if (K == 0) {
        cout << "4" << endl;
        cout << "3 3 3 3" << endl;
        return 0;
    }
    if (K == 1) {
        cout << "2" << endl;
        cout << "0 2" << endl;
        return 0;
    }
 
    if (2 <= K && K <= 50) {
        cout << K << endl;
        for (int i = 0; i < K; i++) {
            cout << K << " ";
        }
        cout << endl;
        return 0;
    }
 
    long long int p = (K + 50 * (50 - 1)) / 50;
    long long int k = K % 50;
    cout << 50 << endl;
    for (int i = 0; i < 50; i++) {
        if (i < k) {
            cout << p + 1 << " ";
        } else {
            cout << p - k << " ";
        }
    }
    cout << endl;
 
    return 0;
}