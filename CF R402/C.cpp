#include <bits/stdc++.h>
using namespace std;


#define forall(i,a,b)                for(int i=a;i<b;i++)
#define forallr(i,a,b)                for(int i=a-1;i>=b;i--)
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define ll long long int
#define llu long long unsigned
#define mod 1000000007

struct ff
{
int a;
int b;
};
bool mf(ff aa, ff bb){return aa.b-aa.a>bb.b-bb.a;}



int main()
{

#ifndef ONLINE_JUDGE
	freopen("C_in.txt","r",stdin);
#endif

        ll n,k;
        cin>>n>>k;
        ff tt[n];
        forall(i,0,n)
            cin>>tt[i].a;
        forall(i,0,n)
            cin>>tt[i].b;
        sort(tt,tt+n,mf);

        ll ans=0;
        int i;
        for(i=0;i<k;i++)
            ans+=tt[i].a;

        while(tt[i].a<=tt[i].b){
            ans+=tt[i].a;
            i++;
        }
        forall(j,i,n)
            ans+=tt[j].b;

        cout<<ans<<endl;

        return 0;
}
