#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)                for(ll i=a;i<b;i++)
#define re(i,b)                for(ll i=0;i<b;i++)
#define repr(i,n)                for(ll i=n-1;i>=0;i--)
#define ll long long
#define ld long double
#define llu long long unsigned
#define pll std::pair<ll, ll> 
#define ppll std::pair<ll, pll>
#define vll std::vector<ll> 
#define vpll std::vector<pll> 
#define vppll std::vector<ppll> 
#define mll std::map<ll, ll> 
#define mpll std::map<pll, ll>
#define mppll std::map<ppll, ll>
#define sll std::set<ll>
#define ff first
#define ss second
#define msll std::multiset<ll>
#define all(c) c.begin(), c.end()
#define allr(c) c.rbegin(), c.rend()
#define srt(x) sort(all(x))
#define rsrt(x) sort(allr(x))
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define s(yy) ll yy;cin>>yy
#define mod 1e9+7
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


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifdef PARTH_LATHIYA_HOME

		freopen("B_in.txt","r",stdin);
	
		ll ttt,bkkk;
		cin>>ttt;
		bkkk=ttt;
		while(ttt--) {
			cout<<"Testcase - "<<bkkk-ttt<<"\n";
	#endif

//--------------------------------------------------------------------------------------

	// std::vector<int> v[100];
	// std::vector<int> temp(100,4);
	// rep(i,0,100)
	// 	v[i] = temp;

	s(n);
	s(a);
	ll pr[n];
	rep(i,3,n+1)
		pr[i]=(i-2)*180;

	ll myangle=(n-2)*180/n;

	// rep(i,3,n){
	// 		(pr[i]-myangle*(i-2))/2;
		
	// }

	// ll fun(ll x)
	// {
	// 	return x;
	// }

	ll l,r,mid,temp;

	//start of range
	l=3;
	//ll a[n] so (end of range) + 1 = n
	r=n;
	// cout<<a<<endl;
	while(l<r)
	{
	// cout<<l<<r<<endl;
	    
	    mid=(l+r)>>1;
		//calc value which you want to compare with key and store in temp;
	    temp=(pr[mid]-myangle*(mid-2))/2;
	    // cout<<temp<<"\n";
	    if(a<=temp)
	        r=mid;
	    else
	        l=mid+1;
	}

	// return l;
	// both l and r value will be same
	// return r;
	// r+1 r-1
	ll ans=r;
	ll anss=(pr[r]-myangle*(r-2))/2;
	// cout<<pr[r]<<"s"<<a<<endl;

	if(r+1<=n && abs(anss-a)>abs(a-(pr[r+1]-myangle*(r+1-2))/2))
	{
		ans=r+1;
		anss=(pr[r+1]-myangle*(r+1-2))/2;
	}
	if(r-1>=3 && abs(anss-a)>abs(a-(pr[r-1]-myangle*(r-1-2))/2))
	{
		ans=r-1;
		anss=(pr[r-1]-myangle*(r-1-2))/2;;
	}
	// cout<<anss;
	// (pr[r-1]-myangle*(r-1-2))/2;




	cout<<"2 1 "<<ans<<"\n";
//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}