#include <bits/stdc++.h>
using namespace std;


#define forall(i,a,b)                for(int i=a;i<b;i++)
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define ll long long int
#define llu long long unsigned
#define mod 1000000007

int main()
{

//#ifndef ONLINE_JUDGE
//	freopen("MFREQ_in.txt","r",stdin);
//#endif

        int n,k;
        cin>>n>>k;
        int cnt=0;
        forall(i,0,n)
        {
            int t;
            cin>>t;
            if(t<=(5-k))
                cnt++;
        }
        cout<<cnt/3;

        return 0;
}
