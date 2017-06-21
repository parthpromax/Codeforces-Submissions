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


ll dp[19]={0,10,
	9,
	90,
	900,
	9000,
	90000,
	900000,
	9000000,
	90000000,
	900000000,
	9000000000,
	90000000000,
	900000000000,
	9000000000000,
	90000000000000,
	900000000000000,
	9000000000000000,
	90000000000000000};



ll fun(ll x)
{
	if(x<10) return x+1;
	ll ans=0;
	ll tx=x;
	int fd;
	int len=0;
	while(tx){
		len++;
		fd=tx;
		tx/=10;
	}

	rep(i,1,len)
		ans+=dp[i];
	int dig=x%10;
	ll te=x % (ll)(pow(10,len-1));	
	te/=10;
	ans+= (te+1);
	ans = ans + (ll)(fd-1)*(ll)pow(10,len-2);
	
	if(fd>dig)
		ans--;
	
	return ans;    
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

// 2 47
// 47 1024

	s(l);
	s(r);
	cout<<fun(r)-fun(l-1)<<endl;

//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}