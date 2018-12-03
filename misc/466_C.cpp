#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)                for(ll i=a;i<b;i++)
#define re(i,b)                for(ll i=0;i<b;i++)
#define repr(i,n)                for(ll i=n-1;i>=0;i--)
#define ll long long
#define ld long double
#define llu long long unsigned
#define pll std::pair<ll, ll> 
#define ppll std::pair<ll, pll>
#define vll std::vector<ll> 
#define vpll std::vector<pll> 
#define vppll std::vector<ppll> 
#define mll std::unordered_map<ll, ll> 
#define mpll std::unordered_map<pll, ll>
#define mppll std::unordered_map<ppll, ll>
#define sll std::set<ll>
#define ff first
#define ss second
#define msll std::multiset<ll>
#define all(c) c.begin(), c.end()
#define allr(c) c.rbegin(), c.rend()
#define srt(x) sort(all(x))
#define rsrt(x) sort(allr(x))
#define eb emplace_back
#define pb push_back
#define s(yy) ll yy;cin>>yy
#define mod 1000000007
#define maxlong 1e18+5


/*#################################################### 
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#      https://www.cse.iitb.ac.in/~parthiitb/        #
#                                                    #
####################################################*/


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef PARTH_LATHIYA_HOME

        freopen("466_C.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

    s(n);
    ll a[n];
    ll s=0;
    re(i,n){
        cin>>a[i];
        s+=a[i];
    }
    ll pr[n],sf[n];
    pr[0]=a[0];
    rep(i,1,n)
        pr[i]=pr[i-1]+a[i];
    sf[n-1]=a[n-1];
    // rep(i,1,n)
    for(ll i=n-2;i>=0;i--)
        sf[i]=sf[i+1]+a[i];    
    if(s%3!=0){
        cout<<0;
        return 0;
    }

    vll v1,v2,v3;
    re(i,n){
        if(pr[i]==s/3)v1.eb(i);
        if(sf[i]==s/3)v2.eb(i);
    }
    // for(ll i=n-1;i>=0;i--)
    //     if(sf[i])
    // for(auto aa:v2)v3.eb(aa);
    ll ans=0;
    // cout<<v1.size()<<v2.size()<<endl;
    // for(auto aa:v2)
    //     cout<<aa<<" ";
    for(auto aa:v1)
    {
        ll pos=lower_bound(v2.begin(),v2.end(),aa+2)-v2.begin();
        // if(v3[pos]!=aa+1)
        // cout<<v2[pos]<<aa<<endl;
        ans+=v2.size()-pos;
    }
    cout<<ans<<endl;


//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}