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

int dpp[102][901];
int ans[102];
ll mm,ss;

bool dp1(int m,int s)
{

	if(s<0)
		return dpp[m][s]=false;
	if(dpp[m][s]!=-1)
		return dpp[m][s];
	if(m==0)
		if(s==0)
			return dpp[m][s]=true;
		else
			return dpp[m][s]=false;

	rep(i,0,10){
		if(i==0 && m==mm)
			continue;
		if(dp1(m-1,s-i)){
			ans[mm-m]=i;
			return dpp[m][s]=true;
		}
	}
	return dpp[m][s]=false;
}

bool dp2(int m,int s)
{

	if(s<0)
		return dpp[m][s]=false;
	if(dpp[m][s]!=-1)
		return dpp[m][s];
	if(m==0)
		if(s==0)
			return dpp[m][s]=true;
		else
			return dpp[m][s]=false;

	repr(i,10){
		if(i==0 && m==mm)
			continue;
		if(dp2(m-1,s-i)){
			ans[mm-m]=i;
			return dpp[m][s]=true;
		}
	}
	return dpp[m][s]=false;
}

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

	cin>>mm>>ss;

	if(mm==1 && ss==0){
		cout<<"0 0";
		return 0;
	}
	rep(i,0,mm+1)
		rep(j,0,ss+1)
			dpp[i][j]=-1;

	if(dp1(mm,ss)){
		re(i,mm)
			cout<<ans[i];
		cout<<" ";
		rep(i,0,mm+1)
			rep(j,0,ss+1)
				dpp[i][j]=-1;
		dp2(mm,ss);
		re(i,mm)
			cout<<ans[i];
	}
	else
		cout<<-1<<" "<<-1;


//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}