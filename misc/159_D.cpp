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

ll st[2001];
int ispal[2001][2001];

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

// aa
// aaa
// abacaba

	string s;
	cin>>s;
	ll n=s.length();
	ll l,r;
	rep(i,0,n)
	{
		l=i;r=i;
		while(l>=0 && r<=n-1 && s[l]==s[r])
		{
			st[l]++;
			ispal[l][r]=1;
			l--;
			r++;
		}
		if(i!=n-1)
		{	
			l=i;r=i+1;
			while(l>=0 && r<=n-1 && s[l]==s[r])
			{
				st[l]++;
				ispal[l][r]=1;
				l--;
				r++;
			}
		}
	}

	repr(i,n-1)
		st[i]+=st[i+1];
	ll ans=0;
	rep(i,0,n)
		rep(j,i,n)
			if(ispal[i][j])
				ans+=st[j+1];
	cout<<ans;

//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}