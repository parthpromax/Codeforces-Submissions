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

ll ncr[1001][1001];

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

// 3
// 2
// 2
// 1

	s(k);
	ll c;

	// FILL(ncr,0);

	rep(i,0,1001)
		rep(j,0,i+1){
			if(i==1 || j==0 || i==0){ncr[i][j]=1;continue;}
			if(j==1){ncr[i][j]=i;continue;}
			ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
		// cout<<ncr[i][i];
	}
	// rep(i,1,10){
	// 	rep(j,1,i+1)
	// 		cout<<ncr[i][j]<<" ";
	// 	cout<<endl;
	// }

	ll total=0,ans=1;
	re(i,k){
		cin>>c;
		total+=c;
		// if(i==0)continue;
		// cout<<ncr[total-1][c-1]<<" ";
		ans=(ans*ncr[total-1][c-1])%mod;
	}

	cout<<ans;

//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}