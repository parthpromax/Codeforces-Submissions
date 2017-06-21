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
		freopen("A_in.txt","r",stdin);
	#endif


//--------------------------------------------------------------------------------------
	
	s(n);
	s(k);
	ll a[n],b[k];
	ll pos;
	re(i,n){
		cin>>a[i];
		if(a[i]==0)pos=i;
	}
	re(i,k)
		cin>>b[i];
	if(k!=1)
		cout<<"Yes";
	else
	{
		a[pos]=b[0];
		ll f=0;
		rep(i,1,n)
		{
			if(a[i]<a[i-1])
			{
				f=1;
				break;
			}
		}
		if(f==0)
			cout<<"No";
		else
			cout<<"Yes";
	}
	

//--------------------------------------------------------------------------------------

	return 0;
}
