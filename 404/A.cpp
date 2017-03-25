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
	freopen("A_in.txt","r",stdin);
#endif

	int n;
	cin>>n;
    ll ans=0;
	string t;
    forall(i,0,n)
    {cin>>t;
    if(t=="Tetrahedron")ans+=4;
    else if(t=="Cube")ans+=6;
    else if(t=="Octahedron")ans+=8;
    else if(t=="Dodecahedron")ans+=12;
    else if(t=="Icosahedron")ans+=20;
    }
    cout<<ans;

    return 0;
}
