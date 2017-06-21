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
		freopen("B_in.txt","r",stdin);
	#endif


//--------------------------------------------------------------------------------------

	s(n);
	s(m);
	char a[n][m+3];
	int first[n],last[n];
	rep(i,0,n)
	{
		first[i]=-1;
		last[i]=-1;
	}
	rep(i,0,n){
		cin>>a[n-1-i];
	}
	ll f;
	ll ff=0;
	rep(i,0,n){
		f=0;
		rep(j,0,m+2){
			if(a[i][j]=='1')
			{
				ff=i+1;
				if(f==0){first[i]=j;
				f=1;}
				last[i]=j;
			}
			// if(a[i])
		}
	}
	if(ff==0)
	{
		cout<<0;return 0;
	}

	int l=1;
	int pr=1;
	ll ans=0;
	ll fr;ll i;
	for(i=0;i<n-1;i++){
		if(l)
		{
			if(first[i]==-1)
			{ans++;}
			else{if(last[i]< (m/2+1))
							{
								ans+=2*last[i]+1;
							}
							else
							{
								ans+=m+2;
								pr=1;
								l=0;
							}}	
		}
		else
		{
			if(first[i]==-1)
			{ans++;}
			else{if(first[i]< (m/2+1))
				{
				ans+=m+2;
				pr=0;
				l=1;
			}
			else
			{
				ans+=(2*(m+1-first[i])+1);
			}}	
		}
		fr=i;
		if(i==ff-1)break;
// cout<<ans<<endl;
		}
		if(i!=n-1)
			i++;
		if(l)
		{
			if(first[i]==-1)
			{
				if(pr)
					ans-=(last[i-1]+1);
				else
					ans-=(first[i-1]+1);
			}
			else{ans+=last[i];}
		}
		else{
			if(first[i]==-1)
			{
				if(pr)
				
				ans-= (m +2-last[i-1]);
			else
				ans-= (m +2-first[i-1]);
			}
			else{ans+= (m +1-first[i]);}	
		}


		
	cout<<ans;
//--------------------------------------------------------------------------------------

	return 0;
}
