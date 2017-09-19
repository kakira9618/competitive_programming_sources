// C - Mahmoud and Ehab and the xor: http://codeforces.com/contest/862/problem/C
// 10^5より大きい数で、全てのビットを1にしても10^6を超えない数をpとする。(p=524287)
// pを解に入れ、0から順番に解に入れていく。ただし、途中でそれまでのXORがp^xにならないように気をつける。
// 最後に今までのXOR ^ xを入れて終わり。

// ※pの最上位ビットは、解の最後でのみ打ち消し可能。解の最初!=解の最後さえ満たされれば条件を満たす。

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
#define _D(p) std::cout<<"L"<<__LINE__<<" : " #p " = "<<(p)<<std::endl;
#define _D2(p,q) std::cout<<"L"<<__LINE__<<" : " #p " = "<<(p) << ", " #q " = "<<(q)<<std::endl;
#define _DN(v) std::cout<<"L"<<__LINE__<<" : " #v " = ["; rep(i,(v).size()) {std::cout<<v[i]<<(i==v.size()-1?"":", ");}std::cout<<"]"<<std::endl;
#define _DNN(v) std::cout<<"L"<<__LINE__<<" : " #v " = [" << std::endl; rep(i,(v).size()) {std::cout<<"    [";rep(j,(v)[0].size()){std::cout<<v[i][j]<<(j==v[0].size()-1?"":", ");}std::cout<<"],"<<std::endl;}std::cout<<"]"<<std::endl;
 
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
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
const int mod = 1000000007;

int main(int argc, char const *argv[]) {
    int n, x;
    cin >> n >> x;

    if (n == 1) {
        cout << "YES" << endl << x << endl;
        return 0;
    }

    if (n == 2 && x == 0) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> ans;
    ans.push_back(524287);
    int cnt = 0, i = 0;
    int now = 524287;
    while(cnt != n - 2) {
        if ((now ^ i) == (524287 ^ x)) {
            i++;
            continue;
        }
        ans.push_back(i);
        now ^= i;
        i++;
        cnt++;
    }

    ans.push_back(now ^ x);

    cout << "YES" << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}