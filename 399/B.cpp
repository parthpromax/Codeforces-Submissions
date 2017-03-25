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
	freopen("B_in.txt","r",stdin);
#endif

        llu n;
        cin>>n;
//        n=pow(2,50)-1;
        llu l,r;
        cin >> l>>r;
//        l=1;
//        n=pow(2,50)-3;
//        if(n==0)
// {
//    cout << "0"<< endl;
//        return 0;
//}
        int d[50]={0};
        int i=49;
        while(n>=1)
        {
            d[i--]=n%2;
            n/=2;
        }

        int dc=50-i-1;

        llu ans=0;
        forall(j,0,dc)
        {
            llu temp=ceil(l/(llu)pow(2,j));
            temp=temp%2?temp:temp+1;
            llu temp1=floor(r/(llu)pow(2,j));
            temp1=temp1%2?temp1:temp1-1;
            if(d[49-dc+1+j])
                ans+=(temp1-temp)/2 + 1;
        }
        cout << ans << endl;
        return 0;
}
