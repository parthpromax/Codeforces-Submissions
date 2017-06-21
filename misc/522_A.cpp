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

// ll ncr[1001][1001];

map<string,vector<string> > m;

ll dp(string s)
{
	
	if(m[s].empty())
		return 1;
	ll ma=-1;
	for(auto a:m[s])
	{
		ma=max(ma,dp(a)+1);
	}
	return ma;
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


// 5
// tourist reposted Polycarp
// Petr reposted Tourist
// WJMZBMR reposted Petr
// sdya reposted wjmzbmr
// vepifanov reposted sdya

	s(n);
	string d,tt,s;
	rep(i,0,n){
		cin>>d>>tt>>s;
		// tolower
		// ;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		transform(d.begin(), d.end(), d.begin(), ::tolower);
		m[s].pb(d);
	}

	cout<<dp("polycarp");
	m.clear();



//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}