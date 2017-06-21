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
	freopen("B_in.txt","r",stdin);
#endif

//  --------------------------------------------------------------------------------------

    int n,m;
    cin>>n>>m;
int flag,ans=1;
rep(i,0,m)
{
    int k;

cin>>k;
set<int> t;
flag=1;
rep(j,0,k)
{
 int tt;   cin>>tt;
    if(tt<0)
    {    if(t.find(-tt)!=t.end())
    {flag=0;}
    t.insert(tt);}
    else
     {   if(t.find(-tt)!=t.end())
    {flag=0;}
    t.insert(tt);}
// cout<<flag;
}
if(flag==1)
    ans=0;
}   
if(!ans)
    cout<<"YES"<<endl;
else
    cout<<"NO"<<endl;

//  --------------------------------------------------------------------------------------

return 0;
}
