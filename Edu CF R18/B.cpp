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
	freopen("B_in.txt","r",stdin);
#endif

//  --------------------------------------------------------------------------------------

    ll n,k;
    cin>>n>>k;
    ll cur=1;
    vector<ll> my;
    rep(i,1,n+1)my.pb(i);
    ll t;
    rep(i,0,k)
    {
        cin>>t;
//        cout<<i;
        if(i!=k-1)
            cout<<my.at((t+cur-1)%n)<<" ";
        else
            cout<<my.at((t+cur-1)%n);
//        cout<<my.size();
//        cout<<(t+cur-1)%n;
        my.erase(my.begin()+(t+cur-1)%n);
        cur=(t+cur-1)%n+1;
        n--;
    }


//  --------------------------------------------------------------------------------------

return 0;
}
