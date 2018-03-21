#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)                for(ll i=a;i<b;i++)
#define re(i,b)                for(ll i=0;i<b;i++)
#define repr(i,n)                for(ll i=n-1;i>=0;i--)
#define ll long long
#define ld long double
#define llu long long unsigned
#define pll std::pair<ll, ll> 
#define ppll std::pair<ll, pll>
#define vll std::vector<ll> 
#define vpll std::vector<pll> 
#define vppll std::vector<ppll> 
#define mll std::map<ll, ll> 
#define mpll std::map<pll, ll>
#define mppll std::map<ppll, ll>
#define sll std::set<ll>
#define ff first
#define ss second
#define msll std::multiset<ll>
#define all(c) c.begin(), c.end()
#define allr(c) c.rbegin(), c.rend()
#define srt(x) sort(all(x))
#define rsrt(x) sort(allr(x))
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define s(yy) ll yy;cin>>yy
#define mod 1000000007
#define maxlong 1e18+5


/*
###################################################### 
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#      https://www.cse.iitb.ac.in/~parthiitb/        #
#                                                    #
###################################################### 
*/

ll doneat[123456];
ll cost[123456];
vll g[123456];
vll gg[123456];
vll v[123456];
stack<ll> s;

void dfs1(ll x)
{

	if(doneat[x])
		return;
	// v[id].eb(x);
	doneat[x]=1;
	for(auto a:g[x])
		if(!doneat[a])
			dfs1(a);
	s.push(x);
}

void dfs2(ll x,ll id)
{

	if(doneat[x])
		return;
	v[id].eb(cost[x]);
	doneat[x]=1;
	for(auto a:gg[x])
		if(!doneat[a])
			dfs2(a,id);
	// s.push(x);
}



int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifdef PARTH_LATHIYA_HOME

		freopen("427_C_in.txt","r",stdin);
	
		ll ttt,bkkk;
		cin>>ttt;
		bkkk=ttt;
		while(ttt--) {
			cout<<"Testcase - "<<bkkk-ttt<<"\n";
	#endif

//--------------------------------------------------------------------------------------

	// std::vector<int> v[100];
	// std::vector<int> temp(100,4);
	// rep(i,0,100)
	// 	v[i] = temp;

	s(n);
	re(i,n)
		cin>>cost[i+1];

	s(m);
	ll a,b;
	re(i,n){
		g[i+1].clear();
		gg[i+1].clear();
		v[i+1].clear();
		doneat[i+1]=0;
	}
	re(i,m){
		cin>>a>>b;
		g[a].eb(b);
	}

	re(i,n)
		if(!doneat[i+1])
			dfs1(i+1);

	re(i,n){
		doneat[i+1]=0;
		for(auto a:g[i+1])
			gg[a].eb(i+1);
			// dfs1(i+1);
	}

	
	ll id=0;
	while(!s.empty()){
		ll cur=s.top();
		s.pop();

		if(!doneat[cur])
			dfs2(cur,++id);
	}
	ll ans1=0,ans2=1;
	for(ll j=id;j>0;j--){
		srt(v[j]);
		// ll cnt=upper_bound(all(v[j]),v[j][0])-v[j].begin();
		ans1+=v[j][0];
		ans2*=upper_bound(all(v[j]),v[j][0])-v[j].begin();
		ans2%=mod;
	}

	cout<<ans1<<" "<<ans2;



//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}