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
#define mod 1e9+7
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

ll id[312345];
ll dia[312345];
vll g[312345];
ll doneat[312345];
ll doneat2[312345];
// ll g[312345]
// ll size[312345];


findid(ll x)
{
	return (x==id[x])?x:id[x]=findid(id[x]);
}

void unionn(ll a,ll b)
{
	// a=findid(a);
	// b=findid(b);
	// if(a!=b){
	// 	if(size[a]>size[b])
	// 		swap(a,b);
	// 	id[a]=b;
	// 	size[b]+=size[a];
	// }
	id[findid(a)]=findid(b);
}

ll ma=-1;
ll farnode;
void dfs2(ll x,ll l)
{
	if(doneat2[x])
		return;
	if(l>ma){
		ma=l;
		farnode=x;
	}
	doneat2[x]=1;

	for(auto a:g[x])
		if(!doneat2[a])
			dfs2(a,l+1);
}

void dfs1(ll x,ll l)
{
	if(doneat[x])
		return;
	if(l>ma){
		ma=l;
		farnode=x;
	}
	doneat[x]=1;

	for(auto a:g[x])
		if(!doneat[a])
			dfs1(a,l+1);
}


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifdef PARTH_LATHIYA_HOME

		freopen("455_C_in.txt","r",stdin);
	
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

	// s(n);
	ll n,m,q,a,b,u,v,x,type;

	cin>>n>>m>>q;

	re(i,n)
		id[i+1]=i+1;
	// re(i,n)
	// 	size[i+1]=1;
	re(i,m){
		cin>>a>>b;
		g[a].eb(b);
		g[b].eb(a);
		unionn(a,b);
	}

	re(i,n)
		if(!doneat[i+1]){
			ma=-1;
			dfs1(i+1,0);
	
			// re(i,n)
			// 	doneat2[i+1]=0;
			ma=-1;
			dfs2(farnode,0);
			dia[findid(i+1)]=ma;
		}


	re(i,q){
		cin>>type;
		if(type==1){
			cin>>x;
			cout<<dia[findid(x)]<<"\n";
		}


		else{
			cin>>u>>v;
			if(findid(u)==findid(v))
				continue;
			ll temp=max(max(dia[findid(u)],dia[findid(v)]),(ll)(ceil(dia[findid(u)]/2.0)+ceil(dia[findid(v)]/2.0)+1));
			// findid(v)
			unionn(u,v);
			dia[findid(v)]=temp;	
		}

	}



//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}