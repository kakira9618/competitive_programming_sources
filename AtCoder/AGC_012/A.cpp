// A - AtCoder Group Contest: https://beta.atcoder.jp/contests/agc012/tasks/agc012_a
// 考察する。強さを弱い順にソートすると、1人目～N人目までは各チームの一番弱い人にできる。N+1人目をあるチームに所属させると、N+1人目はそのチームに所属させるのが良い（出来る限り他のチームのメディアンを上げるため）。
// よって、弱い順ソートにおいて、N+1, N+3, …, 3N-1人目の強さを足せば良い。強い人順ならば2番目, 4番目, ..., 2N番目を足せば良い。

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
    int N;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < 3 * N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(all(A), [](int a, int b){return a > b;});
    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i * 2 + 1];
    }
    cout << sum << endl;
    return 0;
}