// C - Sorting by Subsequences: http://codeforces.com/contest/844/problem/C
// ソート済みの配列との対応を取り、対応しているインデックス同士をunionfindで結合する。

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

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> A_sorted = A;
    sort(all(A_sorted));
    map<int, int> rev;
    for (int i = 0; i < N; i++) {
        rev[A_sorted[i]] = i;
    }

    UnionFind uf(N);
    for (int i = 0; i < N; i++) {
        int j = rev[A[i]];
        uf.unionSet(i, j);
    }

    map<int, vector<int> > ans;
    for (int i = 0; i < N; i++) {
        ans[uf.root(i)].push_back(i);
    }

    cout << ans.size() << endl;
    for(auto &e: ans) {
        cout << e.second.size() << " ";
        for(int i = 0; i < e.second.size(); i++) {
            cout << e.second[i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}