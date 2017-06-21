#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)                for(ll i=a;i<b;i++)
#define re(i,b)                for(ll i=0;i<b;i++)
#define repr(i,n)                for(ll i=n-1;i>=0;i--)
#define ll long long
#define ld long double
#define llu long long unsigned
#define vll std::vector<ll>
#define mll std::map<ll, ll>
#define pll std::pair<ll, ll>
#define mpll std::map<pair<ll,ll>, ll>
#define sll std::set<ll>
#define ff first
#define ss second
#define msll std::multiset<ll>
#define all(c) c.begin(), c.end()
#define allr(c) c.rbegin(), c.rend()
#define srt(x) sort(all(x))
#define rsrt(x) sort(allr(x))
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define s(yy) ll yy;cin>>yy
#define mod 1e9+7
#define maxlong 1e18+5


/*
###################################################### 
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#      https://www.cse.iitb.ac.in/~parthiitb/        #
#                                                    #
###################################################### 
*/


//global var default value 0,;local var inside fun max size 10^6, but if declare globbally size 10^7


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef PARTH_LATHIYA_HOME

        freopen("B_in.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

// 3 1 1 2 0 0
// 3
// 1 1
// 2 1
// 2 3
    s(n);
    ll a[n];
    re(i,n)
        cin>>a[i];

    sort(a,a+n);

    ll ans=1,cnt;
    if(a[0]==a[1] && a[1]==a[2])
    {cnt=0;
        re(i,n)
            if(a[i]==a[0])cnt++;
    ans=cnt*(cnt-1)*(cnt-2)/6;

    }
    else if(a[0]==a[1])
    {cnt=0;
re(i,n)
            if(a[i]==a[0])cnt++;
ans=cnt*(cnt-1)/2;cnt=0;
re(i,n)
            if(a[i]==a[2])cnt++;
ans*=cnt;
    }
    else if(a[1]==a[2])
    {cnt=0;
re(i,n)
            if(a[i]==a[0])cnt++;
ans=cnt;cnt=0;
re(i,n)
            if(a[i]==a[1])cnt++;
ans*=cnt*(cnt-1)/2;

    }
    else
    {cnt=0;
re(i,n)
            if(a[i]==a[0])cnt++;
ans=cnt;cnt=0;
re(i,n)
            if(a[i]==a[1])cnt++;
ans*=cnt;cnt=0;
re(i,n)
            if(a[i]==a[2])cnt++;
ans*=cnt;
    }
cout<<ans;

//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}