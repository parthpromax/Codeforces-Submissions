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

ll ans[200001];

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


// 10
// 1 2 3 4 5 4 3 2 1 6
// 0 1 2 3 4 5 6 7 8 9
// 10 8 7 6 5 6 7 10 10
	s(n);
	ll a[n];
	re(i,n)
		cin>>a[i];

	ll l[n],r[n];

	re(i,n)
	{
		l[i]=-1;
		r[i]=n;
	}
	
	stack<ll> s;
	
	re(i,n){
		while(!s.empty() && a[s.top()]>=a[i])s.pop();	
		if(!s.empty())l[i]=s.top();
		s.push(i);
	}

	while(!s.empty())s.pop();
	
	re(i,n){
		while(!s.empty() && a[s.top()]>a[i]){r[s.top()]=i;s.pop();}	
		s.push(i);
	}

	// re(i,n)
	// 	cout<<l[i]<<" "<<r[i]<<endl;
	re(i,n)
		ans[r[i]-l[i]-1]=max(ans[r[i]-l[i]-1],a[i]);

	// rep(i,1,n+1)
	// 	cout<<ans[i]<<endl;

	// re(i,n)
	// 	cout<<ans[i]<<" ";

	for(ll i=n-1;i>0;i--)
		ans[i]=max(ans[i+1],ans[i]);

	rep(i,1,n+1)
		cout<<ans[i]<<" ";


//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}