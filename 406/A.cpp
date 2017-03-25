#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)                for(ll i=a;i<b;i++)
#define repr(i,n)                for(ll i=n-1;i>=0;i--)
#define ll long long int
#define ld long double
#define llu long long unsigned
#define pb push_back
#define mod 1e9+7

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

    int a,b,c,d;
    cin>>a>>b>>c>>d;
    ll m=b;ll n=d;
    if( (b%2 && !(a%2) && !(c%2) && !(d%2)) || (!(b%2) && !(a%2) && !(c%2) && (d%2) ))

    {
        cout<<"-1"<<endl;
        return 0;
    }
    while(m!=n)
    {    
    if(m<n)
        m+=a;
    else
        n+=c;
    }
       cout<<m<<endl;

//  --------------------------------------------------------------------------------------

return 0;
}
