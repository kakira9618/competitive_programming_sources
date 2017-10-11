// G - 辞書順: http://tdpc.contest.atcoder.jp/tasks/tdpc_lexicographical
// dp[i] := i文字目を使ってできる、i文字以降の部分列の数　とする。
// dp[i] = \sum_{j \in 'a' to 'z'} dp[next[i][j]] となる。ここで、next[i][j] := i文字目以降で初めて文字jが出て来るインデックス
// iの降順にこのdpを計算することができる。
// 計算後、文字を復元する。i文字目以降の文字列から復元するとすると、jの昇順で見たとき、
// K > dp[next[i][j]]　のとき、 K -= dp[next[i][j]] とする（jが復元する文字にはならないのでスキップ）
// K <= dp[next[i][j]] のとき、jを復元文字列の最後に追加し、iをnext[i][j]+1とする。そしてj='a'からやり直す。この時、j単体からなる文字列をKから引く（K--;)のに注意
// jのチェックが最後になってもKを0にすることができなかった場合、Eelを出力する。

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
    string s; 
    ll K;
    cin >> s >> K;
    vector<ll> dp(s.size() + 1, 0);
    vector<vector<int> > next(s.size() + 1, vector<int>(26, s.size()));

    for(int i = s.size() - 1; i >= 0; i--) {
        ll sum = 0;
        for(int j = 0; j < 26; j++) {
            next[i][j] = next[i + 1][j];
            sum += dp[next[i][j]];
            sum = min(sum, K);
        }
        dp[i] = sum + 1;
        next[i][s[i] - 'a'] = i;
    }

    string ans;
    for(int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            if (K <= dp[next[i][j]]) {
                ans += ('a' + j);
                K--;
                i = next[i][j];
                break;
            } else {
                K -= dp[next[i][j]];
            }
            if (K <= 0) break;
            if (j == 25) {
                cout << "Eel" << endl;
                return 0;
            }
        }
        if (K <= 0) break;
    }
    cout << ans << endl;
    return 0;
}