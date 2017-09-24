// C - Palindromic Matrix: http://code-festival-2017-quala.contest.atcoder.jp/tasks/code_festival_2017_quala_c
// (H, W)ともに偶数の場合は、全ての文字が4の倍数個である必要がある。
// Hだけが偶数の場合は、W/2種類までの文字が2の倍数個で許される。 Wだけが偶数の場合はH/2種類まで。
// (H, W)ともに奇数の場合は、(H+W-2)/2種類までの文字が2の倍数個で許され、1種類まで単独の文字が許される。
 
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
 
bool ok(int *cnt, int H, int W) {
    int ok2 = 0, ok1 = 0;
    if (H % 2 == 1 && W % 2 == 1) {
        ok2 = (H + W - 2) / 2;
        ok1 = 1;
    } else if (H % 2 == 1) {
        ok2 = W / 2;
    } else if (W % 2 == 1) {
        ok2 = H / 2;
    }
    int cnt1 = 0, cnt2 = 0, cnt4 = 0;
    for (int i = 0; i < 256; ++i) {
        if (cnt[i] % 4 == 0) cnt4++;
        else if (cnt[i] % 2 == 0) cnt2++;
        else cnt1++;
    }
    if (cnt2 <= ok2 && cnt1 <= ok1) {
        return true;
    }
    return false;
}
 
int main(int argc, char const *argv[]) {
    int H, W;
    cin >> H >> W;
    vector<string> A;
    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        A.push_back(s);
    }
 
    int cnt[256] = {0};
    for(int i = 0; i < H; i++) {
        for (int j = 0; j < W; ++j) {
            cnt[A[i][j]]++;
        }
    }
    if (ok(cnt, H, W)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
 
    return 0;
}