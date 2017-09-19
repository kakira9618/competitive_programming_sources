// B - Mahmoud and Ehab and the bipartiteness: http://codeforces.com/contest/862/problem/B
// 木を白・黒で塗り分けて、各頂点について、相手の色の数-次数 を足し込む。long longでないとダメ。

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

vector<vector<int> > E;
int color[100000];

void dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < E[v].size(); ++i) {
        if (color[E[v][i]] == -1) {
            dfs(E[v][i], 1 - c);
        }
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        E.push_back(vector<int>());
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
/*
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int j = 0; j < E[i].size(); ++j) {
            cout << E[i][j] << " "; 
        }
        cout << endl;
    }
*/
    for (int i = 0; i < 100000; ++i) {
        color[i] = -1;
    }

    dfs(0, 0);
    long long int groupA = 0, groupB = 0;
    for (int i = 0; i < n; ++i) {
        if (color[i]) groupA++;
        if (!color[i]) groupB++;
    }

    long long int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (color[i]) {
            ans += groupB - E[i].size();
        } else {
            ans += groupA - E[i].size();
        }
    }
    cout << ans / 2 << endl;


    return 0;
}
