#include <bits/stdc++.h>
using namespace std;


#define forall(i,a,b)                for(int i=a;i<b;i++)
#define forallr(i,a,b)                for(int i=a-1;i>=b;i--)
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define ll long long int
#define llu long long unsigned
#define mod 1000000007


struct frele
{
ll l;
ll r;
ll ele;
};

int main()
{

#ifndef ONLINE_JUDGE
	freopen("A_in.txt","r",stdin);
#endif

        ll n;
        cin>>n;
        ll a[n];
        forall(i,0,n)
            cin>>a[i];
        ll ans=0;
        sort(a,a+n);
        int i;
        for(i=1;i<n&&a[i]==a[i-1];i++);

        if(i==n)
            ans=0;
        else
        {
            ans=n-i;
            int i;
            for(i=n-1;a[i]==a[i-1];i--);
            ans-=n-i;
        }
        cout << ans << endl;

        return 0;
}
