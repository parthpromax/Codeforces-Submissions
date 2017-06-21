#include <bits/stdc++.h>
using namespace std;

#define forall(i,a,b)                for(int i=a;i<b;i++)
#define ll long long int
#define llu long long unsigned
#define vll vector<ll>
#define vllu vector<llu>
#define sll set<ll>
#define sllu set<llu>
#define pb push_back
#define mll map<ll,ll>
#define mllu map<llu,llu>
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define mod 1000000007


int main()
{

#ifndef ONLINE_JUDGE
	freopen("B_in.txt","r",stdin);
#endif

	int n,m;
	cin>>n;
    ll min1=1000000001,min2=1000000001,max1=0,max2=0;
    ll p,q;
    forall(i,0,n)
    {
        cin>>p>>q;
        min1=miN(min1,q);
        max1=maX(max1,p);
    }
    cin>>m;
    forall(i,0,m)
    {
        cin>>p>>q;
        min2=miN(min2,q);
        max2=maX(max2,p);
    }

    ll ans=maX((max2-min1),(max1-min2));
    if(ans<0)
        cout<<"0";
    else
        cout<<ans;
    return 0;
}
