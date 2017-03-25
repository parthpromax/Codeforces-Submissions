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
	freopen("C_in.txt","r",stdin);
#endif

	long double n,m;
	cin>>n>>m;
    if(m>n)m=n;
    cout<<(llu)(maX(ceil(((2*m)-1 + sqrt(1-(8*m)+(8*n)))/2),ceil(((2*m)-1 - sqrt(1-(8*m)+(8*n)))/2)));
    return 0;
}
