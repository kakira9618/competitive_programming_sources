// Div1 Easy - Remember Words
// O(1)解。d1日終了時に覚える単語の数の最小をmi, 最大をmaとしたとき、mi, maを求める。
// 覚える単語の数は負にならない点に注意する。

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
typedef    pair<int, int>      pii;

const int INF = 1 << 29;
const double EPS = 1e-9;

const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, -1, 0, 1 };

class RememberWords {
public:
	string isPossible(int d1, int d2, int w1, int w2) {
		double ma;
		if (sqrt((double)w1 * 2 + 1.0 / 4) - 1.0 / 2 <= d1) {
			// 0からカウントアップしていく場合 [1+2+...+nがw1を超えない最大のnを求めている]
			ma = (int)(sqrt((double)w1 * 2 + 1.0 / 4) - 1.0 / 2);
		}
		else {
			// 0からカウントアップしない場合 [a+(a+1)+...+(a+d1-1)=w1となるときのa+d1-1を求めている]
			ma = (int)(((double)w1 * 2 / d1) + 1 - d1) / 2 + d1 - 1;
		}

		double mi = max(0.0, ceil((((double)w1 * 2 / d1) - 1 + d1) / 2 - d1 + 1));
		if (mi <= d2 && max(0.0, (mi - 1)) * max(0.0, (mi - 1)) / 2 - EPS > w2) {
			// 1ずつカウントダウンするとd2日以前に0以下になる場合 [(mi-1)+(mi-2)+...+1>w2の場合Impossible]
			return "Impossible";
		}
		// maから+1し続ける場合と-1し続ける場合で、範囲に入っていればOK。
		bool ok = w2 <= (2 * ma + 2 + d2 - 1) * d2 / 2 + EPS && w2 >= (2 * mi - 2 - (d2 - 1)) * d2 / 2 - EPS;
		if (ok) {
			return "Possible";
		}
		else {
			return "Impossible";
		}
	}
};