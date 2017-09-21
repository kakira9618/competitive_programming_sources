// C - From Y to Y: http://codeforces.com/contest/849/problem/C
// ある文字がi個あると、costはi*(i-1)/2だけ上がるということに気づくと解けるが、証明はしていない。

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
    int K;
    cin >> K;

    if (K == 0) {
        cout << "a" << endl;
        return 0;
    }
    
    vector<long long> table(100001, 0);
    for(int i = 0; i <= 100000; i++) {
        table[i] = i * (i - 1) / 2;
    }
        
    string ans = "";
    for(int c = 'a'; c <= 'z'; c++) {
        for(int i = 0; i <= 100000; i++) {
            if (K < table[i]) {
                K -= table[i - 1];
                if (i > 1) {
                    ans += string(i - 1, c);
                }
                break;
            }
            if (K == 0) break;
        }
    }
    cout << ans << endl;
    
    return 0;
}