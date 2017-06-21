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
                    ** author **
                ** Parth Lathiya **
    ** https://www.cse.iitb.ac.in/~parthiitb/ **
*/


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("A_in.txt","r",stdin);
	#endif


//--------------------------------------------------------------------------------------
	
	ll l[4],s[4],r[4],p[4];
	cin>>l[0]>>s[0]>>r[0]>>p[0];
	cin>>l[1]>>s[1]>>r[1]>>p[1];
	cin>>l[2]>>s[2]>>r[2]>>p[2];
	cin>>l[3]>>s[3]>>r[3]>>p[3];
	if ((p[0] && (l[0] || s[0] || r[0])) ||
	(l[0] && p[3]) ||
	(s[0] && p[2]) ||
	(r[0] && p[1]) ||
	(l[1] && p[0]) ||
	(s[1] && p[3]) ||
	(r[1] && p[2]) ||
	(l[2] && p[1]) ||
	(s[2] && p[0]) ||
	(r[2] && p[3]) ||
	(l[3] && p[2]) ||
	(s[3] && p[1] ) ||
	(r[3] && p[0]) ||
	(p[1] && (l[1] || s[1] || r[1])) ||
	(p[2] && (l[2] || s[2] || r[2])) ||
	(p[3] && (l[3] || s[3] || r[3])) )
		cout<<"YES";
		else
		cout<<"NO";
			

//--------------------------------------------------------------------------------------

	return 0;
}
