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

	string s[10];

	re(i,10)
		cin>>s[i];
	int x=0;int dot=0;
	re(i,10)
	{
		re(j,10)
		{
			//vert
			x=0;dot=0;
			rep(k,j,j+5)
			{
				if(i>=0 && i<10 && k>=0 && k<10)
				{
					if(s[i][k]=='X')x++;
					else if(s[i][k]=='.')dot++;
				}
			}
			if(x==4 && dot==1){
				cout<<"YES";
				return 0;
			}
			//hori
			x=0;dot=0;
			rep(k,i,i+5)
			{
				if(k>=0 && k<10 && j>=0 && j<10)
				{
					if(s[k][j]=='X')x++;
					else if(s[k][j]=='.')dot++;
				}
			}
			if(x==4 && dot==1){
				cout<<"YES";
				return 0;
			}
			//dia1
			x=0;dot=0;
			rep(k,0,5)
			{
				if(i+k>=0 && i+k<10 && j+k>=0 && j+k<10)
				{
					if(s[i+k][j+k]=='X')x++;
					else if(s[i+k][j+k]=='.')dot++;
				}
			}
			if(x==4 && dot==1){
				cout<<"YES";
				return 0;
			}
			//dia2
			x=0;dot=0;
			rep(k,0,5)
			{
				if(i+k>=0 && i+k<10 && j-k>=0 && j-k<10)
				{
					if(s[i+k][j-k]=='X')x++;
					else if(s[i+k][j-k]=='.')dot++;
				}
			}
			if(x==4 && dot==1){
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";

//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}