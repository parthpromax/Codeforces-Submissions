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

ll dp[1001];


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

// 6
// 2 1 4 6 2 2
// 7
// 3 3 3 1 3 3 3

	s(n);
	ll h[n];
	re(i,n)
		cin>>h[i];

	ll ans[n+2];
	ll finalans=-1;
	ans[0]=0;ans[n+1]=0;
	rep(i,1,n+1)
		ans[i]=min(ans[i-1]+1,h[i-1]);
	for(ll i=n;i>0;i--){
		ans[i]=min(ans[i],ans[i+1]+1);
		finalans=max(finalans,ans[i]);
	}

	cout<<finalans;

//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}