#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)                for(ll i=a;i<b;i++)
#define re(i,b)                for(ll i=0;i<b;i++)
#define repr(i,n)                for(ll i=n-1;i>=0;i--)
#define ll long long
#define ld long double
#define llu long long unsigned
#define vll std::vector<ll>
#define mll std::map<ll, ll>
#define pll std::pair<ll, ll>
#define mpll std::map<pair<ll,ll>, ll>
#define sll std::set<ll>
#define fi first
#define se second
#define msll std::multiset<ll>
#define all(c) c.begin(), c.end()
#define allr(c) c.rbegin(), c.rend()
#define srt(x) sort(all(x))
#define rsrt(x) sort(allr(x))
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define s(yy) ll yy;cin>>yy
#define mod 1e9+7
#define maxlong 1e18+5
//4611686018427388000


/*
###################################################### 
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#      https://www.cse.iitb.ac.in/~parthiitb/        #
#                                                    #
###################################################### 
*/

// vll primes;
// vll primefac[10000001];

// void sieve(ll n)
// {
// 	rep(i,2,n+1)
// 	{
// 		if(primefac[i].empty())
// 		{	
// 			primes.pb(i);
// 			for(ll j=i;j<=n;j+=i)
// 				primefac[j].pb(i);
// 		}
// 	}
// }


ld dist(pll x, pll y)
{
	return sqrt((x.fi-y.fi)*(x.fi-y.fi) + (x.se-y.se)*(x.se-y.se));
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifdef PARTH_LATHIYA_HOME

		freopen("in.txt","r",stdin);
	
		ll ttt,bkkk;
		cin>>ttt;
		bkkk=ttt;
		while(ttt--) {
			cout<<"Testcase - "<<bkkk-ttt<<"\n";
	#endif

//--------------------------------------------------------------------------------------

// 3 1 1 2 0 0
// 3
// 1 1
// 2 1
// 2 3

	pll a,b,t;
	cin>>a.fi>>a.se>>b.fi>>b.se>>t.fi>>t.se;
	s(n);
	pll aa[n];
	ld total=0;
	ld pre[n+2],suf[n+2],btop[n+1];
	re(i,n){
		cin>>aa[i].fi>>aa[i].se;
		ld temp=dist(aa[i],a);
		ld ttop=dist(aa[i],t);
		pre[i+1]=temp-ttop;
		suf[i+1]=temp-ttop;
		btop[i+1]=dist(aa[i],b)-ttop;	
		total+=2.0*ttop;
	}

	rep(i,2,n+1)
	{
		pre[i]=min(pre[i],pre[i-1]);
		suf[n-i+1]=min(suf[n-i+1],suf[n-i+2]);
	}

	ld ans=suf[1]+total;
	pre[0]=maxlong;
	suf[n+1]=maxlong;

	rep(i,1,n+1)
	{
		ans = min(ans,total+min((ld)0.0, (ld)min(pre[i-1],suf[i+1])) + btop[i]);
	}

	cout<<fixed<<setprecision(12)<<ans;



//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}