#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)                for(ll i=a;i<b;i++)
#define repr(i,n)                for(ll i=n-1;i>=0;i--)
#define ll long long int
#define ld long double
#define llu long long unsigned
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
	freopen("A_in.txt","r",stdin);
#endif

//  --------------------------------------------------------------------------------------

    ll n;
    cin>>n;
    ll a[n];
    rep(i,0,n)
    {
    cin>>a[i];
    }
    sort(a,a+n);
    ll minn=a[1]-a[0];
    rep(i,2,n)
    {
    minn=min(minn,a[i]-a[i-1]);
    }
    ll ans=0;
//    cout<<minn;
    rep(i,1,n)
    {
    if((a[i]-a[i-1])==minn)ans++;
    }


    cout<<minn<<" "<<ans;

//  --------------------------------------------------------------------------------------

return 0;
}
