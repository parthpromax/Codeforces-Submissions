#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)                for(ll i=a;i<b;i++)
#define re(i,b)                for(ll i=0;i<b;i++)
#define repr(i,n)                for(ll i=n-1;i>=0;i--)
#define ll long long
#define ld long double
#define llu long long unsigned
#define vll std::vector<ll>
#define FILL(a,b) memset((a),b,sizeof(a))
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
#define mod 1000000007
#define maxlong 9223372036854775808


/*
###################################################### 
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#      https://www.cse.iitb.ac.in/~parthiitb/        #
#                                                    #
###################################################### 
*/

vll primes;
vll primefac[10000001];

void sieve(ll n)
{
	rep(i,2,n+1)
	{
		if(primefac[i].empty())
		{	
			primes.pb(i);
			for(ll j=i;j<=n;j+=i)
				primefac[j].pb(i);
		}
	}
}

ll dp[100001];

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

// 2
// 5
// 2 3 4 6 9
// 9
// 1 2 3 5 6 7 8 9 10

	s(n);
	ll a[n];
	ll ma=-1;
	re(i,n){
		cin>>a[i];
		ma=max(ma,a[i]);
	}

	if(n==1)
	{cout<<1;return 0;}
	sieve(ma);
	ll ans=-1;
	rep(i,0,n){
		ma=-1;
		for(auto ab:primefac[a[i]])
			ma=max(ma,dp[ab]);
		for(auto ab:primefac[a[i]])
			dp[ab]=ma+1;
		dp[a[i]]=ma+1;
		ans=max(ans,dp[a[i]]);
	}
	
	cout<<ans;

//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}