// E - Decrease (Judge ver.): https://beta.atcoder.jp/contests/arc079/tasks/arc079_c
// 各要素について貪欲に、N-1にするための操作回数を求める。もちろんその他の要素の操作回数分だけ各要素の値が増えるため、それを全ての要素がN-1以下になるまで繰り返す。

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
 
bool check(vector<long long int> &A) {
    int N = A.size();
    for (int i = 0; i < N; i++) {
        if (A[i] >= N) return false;
    }
    return true;
}
 
int main() {
    int N;
    cin >> N;
    vector<long long int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
 
    long long int ans = 0;
    while(!check(A)) {
 
        vector<long long int> D;
        long long int cnt = 0;
        for (int i = 0; i < N; i++) {
            long long int d = (A[i] - 1 - (N - 1)) / N + 1;
            if (A[i] < N) d = 0;
            cnt += d;
            A[i] -= d * N;
            D.push_back(d);
        }
 
        for (int i = 0; i < N; i++) {
            A[i] += cnt - D[i];
        }
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}