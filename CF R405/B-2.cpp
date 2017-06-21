#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii; 
typedef set<ll> si;
typedef map<ll,ll> mii;
typedef priority_queue<ll> pqi;
#define fir first
#define sec second
#define pb push_back
#define mp make_pair
#define sz(x) x.size()
#define rep(i,n) for(ll i=0;i<n;i++)
#define fr(i,a,b) for(ll i=a;i<=b;i++)
#define fd(i,a,b) for(ll i=a;i>=b;i--) 
#define tr(it,x) for(it=x.begin();it!=x.end();it++)
#define rtr(it,x) for(it=x.rbegin();it!=x.rend();it++)
#define fast_io ios_base::sync_with_stdio(0);
#define accuracy  ll precision = numeric_limits<double>::digits10;
#define N 200005

ll n,m;
vector<ll> edg[N];
bool vis[N];
ll col[N];
map<ll,ll> cou;

ll curr = 1;

void dfs(ll i) {
	vis[i] = true;
	rep(j,sz(edg[i])) {
		if(!vis[edg[i][j]]) {
			col[edg[i][j]] = curr;
			cou[curr] += 1;
			dfs(edg[i][j]);
		}
	}
}

int main() {
	// freopen("my.in", "r", stdin);
	// freopen("my.out", "w", stdout);
    fast_io;
    accuracy;

    cin >> n >> m;
    rep(i,m) {
    	ll u,v; cin >> u >> v;
    	edg[u].pb(v); edg[v].pb(u);
    }
    fr(i,1,n) {
    	if(!vis[i]) {
    		cou[curr] += 1;
    		col[i] = curr;
    		dfs(i);
    		curr++;
    	} 
    }
    vector<ll> cnt(curr,0);

    bool pos = true;
    fr(i,1,n) {
    	rep(j,sz(edg[i])) {
    		ll u=i,v = edg[i][j];
    		cnt[col[u]] += 1;
    	}
    }
    fr(i,1,curr-1) {
    	if(cnt[i] != cou[i]*(cou[i]-1)) {
    		pos = false; break;
    	}
    }
    if(pos) cout << "YES" << endl;
    else cout << "NO" << endl;
}




orr



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <fstream>
#include <queue>
#include <stack>
#include <iomanip>
#include <hash_set>
#include <cstdio>
#include <map>
#include <string>   
#include <set>
#define LL long long
#define LD long double

const int MAXN = 100000;
const LD PI = 3.14159265359;        
const LD EPS = 1e-6;
const int MOD = 1000000007;
const LL LINF = 100000000000000;
const int INF = 1000000000;

using namespace std;

LL ed, ver;
vector < int > gr[150000];
bool used[150000] = {};

void dfs(int v){
    used[v] = true;
    ver++;
    for (int i = 0; i < int(gr[v].size()); i++){
        int to = gr[v][i];
        ed++;
        if (!used[to])
            dfs(to);
    }
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("loganqueries.in", "r", stdin);
    //freopen("loganqueries.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        from--; to--;
        gr[from].push_back(to);
        gr[to].push_back(from);
    }
    for (int i = 0; i < n; i++)
        if (!used[i]){
            ed = ver = 0;
            dfs(i);
            ed /= 2;
            if (ver * (ver - 1) / 2 != ed){
                cout << "NO";
                return 0;
            }
        }
    cout << "YES";
}