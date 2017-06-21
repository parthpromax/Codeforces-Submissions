#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)                for(ll i=a;i<b;i++)
#define repr(i,n)                for(ll i=n-1;i>=0;i--)
#define ll long long int
#define ld long double
#define llu long long unsigned
#define vll std::vector<ll>
#define mll std::map<ll, ll>
#define sll std::set<ll>
#define msll std::multiset<ll>
#define all(c) c.begin(), c.end()
#define allr(c) c.rbegin(), c.rend()
#define srt(x) sort(all(x))
#define rsrt(x) sort(allr(x))
#define mp make_pair
#define pb push_back
#define mod 1000000007

/*
                    ** author **
                ** Parth Lathiya **
    ** https://www.cse.iitb.ac.in/~parthiitb/ **
*/

int main()
{

ios::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("C_in.txt","r",stdin);
#endif

//  --------------------------------------------------------------------------------------
    
ll n;
cin>>n;

ll a[n],dp[n];

rep(i,0,n)
    cin>>a[i];

sort(a,a+n);

ll s=0;
dp[0]=1;

ll temp=1;

rep(i,1,n-1)
{
	temp=(temp*2)%mod;
	dp[i]=(dp[i-1]+temp)%mod;
}

ll bkk=dp[n-2];

rep(i,0,n-1)
{
	s = (s + ((a[i+1]-a[i])*bkk)%mod )%mod;
	bkk = (mod+bkk-dp[i]+dp[n-3-i])%mod;
}
cout<<s<<endl;
    
//  --------------------------------------------------------------------------------------

return 0;
}
