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
    freopen("B_in.txt","r",stdin);
#endif

//  --------------------------------------------------------------------------------------

ll n,f;
cin>>n>>f;

ll ans[n];
ll k,l;
ll sum=0;
rep(i,0,n)
{
    cin>>k>>l;
    ans[i]=min(2*k,l)-min(k,l);
    sum+=min(k,l);
    // sum+=tt;
}
// cout<<sum;
sort(ans,ans+n);
reverse(ans,ans+n);
rep(i,0,f)
sum+=ans[i];
cout<<sum<<endl;
//  --------------------------------------------------------------------------------------

return 0;
}
