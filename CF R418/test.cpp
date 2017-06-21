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
#define mpll std::map<pair<ll,ll>, ll>
#define sll std::set<ll>
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


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifdef PARTH_LATHIYA_HOME
		freopen("C_in.txt","r",stdin);
	#endif


//--------------------------------------------------------------------------------------
	
	ll n;
	cin>>n;
	string s;
	cin>>s;
	s(q);
	ll m;
	char c;
	// vll v;
	re(i,q)
	{
		cin>>m>>c;
		ll cnt=0;
		ll ma=0;
		for(ll l=0,r=0;r<n;r++)
		{
			if(s[r]!=c){
				cnt++;
				while(cnt>m){
					if(s[l]!=c)cnt--;
					l++;
				}
			}
			ma=max(ma,r-l+1);
		}
		cout<<ma<<"\n";
	}	

	// cout<<ans<<"\n";

//--------------------------------------------------------------------------------------

	return 0;
}
