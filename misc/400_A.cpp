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

ll dp[100001];

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

	s(t);
	while(t--){
		string a;
		cin>>a;
		int c[6];
		rep(i,0,6)
			c[i]=0;
		c[5]=1;
		
		rep(i,0,12)
			if(a[i]=='X'){
				c[0]=1;
				break;
			}
		

		rep(i,0,6)
			if(a[i]=='X' && a[i+6]=='X'){
				c[1]=1;
				break;
			}
		
		rep(i,0,4)
			if(a[i]=='X' && a[i+4]=='X' && a[i+8]=='X'){
				c[2]=1;
				break;
			}
		rep(i,0,3)
			if(a[i]=='X' && a[i+3]=='X' && a[i+6]=='X' && a[i+9]=='X'){
				c[3]=1;
				break;
			}
		rep(i,0,2)
			if(a[i]=='X' && a[i+2]=='X' && a[i+4]=='X' && a[i+6]=='X' && a[i+8]=='X' && a[i+10]=='X'){
				c[4]=1;
				break;
			}

		rep(i,0,12)
			if(a[i]!='X'){
				c[5]=0;
				break;
			}

		int ans=0;
		rep(i,0,6)
			ans+=c[i];
		cout<<ans<<" ";
		if(c[0])
			cout<<"1x12 ";
		if(c[1])
			cout<<"2x6 ";
		if(c[2])
			cout<<"3x4 ";
		if(c[3])
			cout<<"4x3 ";
		if(c[4])
			cout<<"6x2 ";
		if(c[5])
			cout<<"12x1 ";
	cout<<"\n";
}

//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}