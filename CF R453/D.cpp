#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)                for(ll i=a;i<b;i++)
#define re(i,b)                for(ll i=0;i<b;i++)
#define repr(i,n)                for(ll i=n-1;i>=0;i--)
#define ll long long
#define ld long double
#define pll std::pair<ll, ll> 
#define ppll std::pair<ll, pll>
#define vll std::vector<ll> 
#define vpll std::vector<pll> 
#define vppll std::vector<ppll> 
#define mll std::unordered_map<ll, ll> 
#define mpll std::unordered_map<pll, ll>
#define mppll std::unordered_map<ppll, ll>
#define sll std::set<ll>
#define ff first
#define ss second
#define msll std::multiset<ll>
#define all(c) c.begin(), c.end()
#define allr(c) c.rbegin(), c.rend()
#define srt(x) sort(all(x))
#define rsrt(x) sort(allr(x))
#define eb emplace_back
#define pb push_back
#define s(yy) ll yy;cin>>yy
#define len length()
#define sz size()
const ll mod = 1e9 + 7;
const ll INF = 0x7FFFFFFFFFFFFFFF>>1;

/*#################################################### 
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#      https://www.cse.iitb.ac.in/~parthiitb/        #
#                                                    #
####################################################*/

// ll ncr(ll n, ll r)
// {
// 	ld temp=1.0;
// 	re(i,r)
// 		temp*= (n-i)*1.0/(i+1);
// 	return temp;
// }

map<pll,ll> m;

ll po(ll a,ll b)
{
	if(b==0)
		return 1;
	ll temp=po(a,b>>1);
	if(b&1)
		return (((temp*temp)%mod)*a)%mod;
	return (temp*temp)%mod;
}

ll ncr(ll n, ll r)
{
	if(m[{n,r}])
		return m[{n,r}];
	if(r==0 || r==n)
		return 1;
	return m[{n,r}]=(ncr(n-1,r)+ncr(n-1,r-1))%mod;
}


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifdef PARTH_LATHIYA_HOME

		freopen("D_in.txt","r",stdin);
	
		ll ttt,bkkk;
		cin>>ttt;
		bkkk=ttt;
		while(ttt--) {
			cout<<"Testcase - "<<bkkk-ttt<<"\n";
	#endif

//--------------------------------------------------------------------------------------

	s(a);
	s(b);
	ll aa=min(a,b);
	ll bb=max(a,b);
	if(aa<=23 && bb==25)
		cout<<ncr(aa+bb-1,aa);
	else if  (aa>=24 && bb-aa==2) 
		cout<<(603457371*po(2,aa-24))%mod;
	else
		cout<<0;


//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}