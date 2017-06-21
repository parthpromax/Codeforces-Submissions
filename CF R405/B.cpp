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
	cin>>n>>m;
    int a[n][n];
    forall(i,0,n)
        forall(j,0,n)
            a[i][j]=0;   
    forall(i,0,m)
    {
        ll p, q;
        cin>>p>>q;
        a[p-1][q-1]=1;
    }
    int c[n][n];
        forall(i,0,n)
        {
            forall(j,0,n)
            {
                c[i][j]=0;
                forall(k,0,n){
                    c[i][j]=c[i][j]+(a[i][k]*a[k][j]);
                    if(c[i][j]>0)
                        break;
                }
            }
        }
    int ans=1;
int i,j;

// for(i=0;i<n;++i)
//         {
//             for(j=0;j<n;++j)
//             {
//                 cout<<a[i][j]<<" ";
//         }
//             cout<<"\n";
//         }

//         for(i=0;i<n;++i)
//         {
//             for(j=0;j<n;++j)
//             {
//                 cout<<c[i][j]<<" ";
//         }
//             cout<<"\n";
//         }


    forall(i,0,n)
        {
            forall(j,0,n)
            {
                if(c[i][j]>0 && a[i][j]!=1)
                {
                    ans=0;
                    break;
                }
            }
            if(!ans)break;
        }
    if(ans)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
