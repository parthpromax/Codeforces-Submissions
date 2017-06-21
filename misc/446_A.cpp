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

		freopen("in.txt","r",stdin);
	
		ll ttt,bkkk;
		cin>>ttt;
		bkkk=ttt;
		while(ttt--) {
			cout<<"Testcase - "<<bkkk-ttt<<"\n";
	#endif

//--------------------------------------------------------------------------------------

	s(n);
	ll a[n];
	re(i,n)
		cin>>a[i];
	
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	ll l[n];
	l[0]=1;
	rep(i,1,n)
		l[i]= (a[i-1]<a[i]) ? l[i-1]+1:1;
	ll r[n];
	r[n-1]=1;
	for(ll i=n-2;i>=0;i--)
		r[i]=(a[i]<a[i+1])?r[i+1]+1:1;

	// rep(i,0,n)
	// 	cout<<l[i]<<" "<<r[i]<<endl;
	ll ma=max(r[0],r[1]+1);
	rep(i,1,n-1)
	{
		if(a[i-1]+1<a[i+1])
			ma=max(ma,r[i+1]+l[i-1]+1);
		else
			ma=max(ma,max(r[i+1],l[i-1])+1);
	}
	ma=max(ma,l[n-2]+1);

	cout<<ma;

//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}