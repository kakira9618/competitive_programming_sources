// D - Four Coloring: http://code-festival-2017-quala.contest.atcoder.jp/tasks/code_festival_2017_quala_d
// マンハッタン距離を考える問題であるから、45度回転してチェビシェフ距離を考える。
// 点(i, j)と(i+j, i-j)を対応させると、対応後の座標において、チェビシェフ距離がdの点の色と異なる色で塗れば良い。
// これは、自分を中心として、チェビシェフ半径（？）dの真四角上の点が自らと違う色であれば良いから、d x dに領域を区切り、隣り合う区画を違う色で塗れば良い。

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
    int H, W, D;
    cin >> H >> W >> D;
    string dic = "RYGB";
    for(int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // x: i + j
            // y: i - j
            // +1000 * D: i - jが負にならない、かつ結果に影響を与えないように補正
            cout << dic[((i + j) / D) % 2 + (((i - j + 1000 * D) / D) % 2) * 2];
        }
        cout << endl;
    }
    return 0;
}