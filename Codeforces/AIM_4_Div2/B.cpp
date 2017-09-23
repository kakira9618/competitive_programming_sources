// B - Rectangles: http://codeforces.com/contest/844/problem/B
// 縦と横を別々に数えて足した後、重複カウント分を引く。ある色が一列にc個ある時、(1<<c)-1種類の集合が考えられる。
// オーバーフローに注意。

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

int main(int argc, char const *argv[]) {

    int N, M;
    cin >> N >> M;
    vector<vector<int> > table(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> table[i][j];
        }
    }
    long long ans = 0;
    for(int i = 0; i < N; i++) {
        int c0 = 0, c1 = 0;
        for(int j = 0; j < M; j++) {
            if (table[i][j]) {
                c1++;
            } else {
                c0++;
            }
        }
        ans += (1LL << c0) - 1;
        ans += (1LL << c1) - 1;
    }
    for(int j = 0; j < M; j++) {
        int c0 = 0, c1 = 0;
        for(int i = 0; i < N; i++) {
            if (table[i][j]) {
                c1++;
            } else {
                c0++;
            }
        }
        ans += (1LL << c0) - 1;
        ans += (1LL << c1) - 1;
    }

    cout << ans - N * M << endl;

    return 0;
}