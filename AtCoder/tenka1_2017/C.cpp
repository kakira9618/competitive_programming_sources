// C - 4/N: http://tenka1-2017.contest.atcoder.jp/tasks/tenka1_2017_c
// doubleを使った解。
// h, n, w <= 3500なので、h, nを全探索する。EPSが小さすぎると通らない。

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
const double EPS=1e-5;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
 
int main(int argc, char const *argv[]) {
    double N;
    cin >> N;
 
    for (double h = 1; h <= 3500; ++h) {
        for (double n = 1; n <= 3500; ++n) {
            // 4/N = 1/h + 1/n + 1/w
            // 4 = N/h + N/n + N/w
            // 4 - N/h - N/n = N/w
            // 1 / (4 - N/h - N/n) = w/N
            // N / (4 - N/h - N/n) = w
            if (fabs(4.0 - N/h - N/n) <= EPS) continue;
            double k = N / (4.0 - N/h - N/n);
            int w = (int)(k + EPS);
            if (fabs(k - w) <= EPS) {
                cout << h << " " << n << " " << w << endl;
                return 0;
            }
        }
    }
 
    return 0;
}