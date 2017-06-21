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
		freopen("B_in.txt","r",stdin);
	#endif


//--------------------------------------------------------------------------------------
	
	ll n;
	cin>>n;
	ll a[n],b[n],c[n];
	re(i,n)
		cin>>a[i];	
	re(i,n)
		cin>>b[i];	
	mll m;
	vll pos;
	re(i,n){
		if(a[i]==b[i]){
			c[i]=a[i];
			m[a[i]]=1;
		}
		else
			pos.pb(i);
	}	
	vll v;
	rep(i,1,n+1)
	{
		if(m[i]!=1)
			v.pb(i);
	}
	if(v.size()==1)
	{
		c[pos.back()]=v.back();
	}	
	else
	{
		ll p=pos[0];
		ll q=pos[1];
		if(a[p]==v[0] && b[q]==v[1]){
			c[p]=v[0];
			c[q]=v[1];
		}
		else if(a[p]==v[1] && b[q]==v[0]){
			c[p]=v[1];
			c[q]=v[0];
		}
		else if(a[q]==v[0] && b[p]==v[1]){
			c[p]=v[1];
			c[q]=v[0];
		}
		else if(a[q]==v[1] && b[p]==v[0]){
			c[p]=v[0];
			c[q]=v[1];
		}
	}
	re(i,n)
		cout<<c[i]<<" ";


//--------------------------------------------------------------------------------------

	return 0;
}
