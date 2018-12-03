#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)                for(ll i=a;i<b;i++)
#define re(i,b)                for(ll i=0;i<b;i++)
#define repr(i,n)                for(ll i=n-1;i>=0;i--)
#define ll long long
#define ld long double
#define pll std::pair<ll, ll> 
#define ppll std::pair<pll, ll>
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
#define len length()
#define sz size()
const ll mod = 1e9 + 7;
const ll INF = 0x7FFFFFFFFFFFFFFF>>1;

/*#################################################### 
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#      https://www.cse.iitb.ac.in/~parthiitb/        #
#                                                    #
####################################################*/


ll n;
// ll a[123456];
mll bt;
// /[123456];

void update(ll i)
{
    // cout<<"ori"<<i;
    for(;i<=1000000000;i+= i&-i){
        // cout<<i<<" ";
        bt[i]++;
    }
    // cout<<endl;
}

// void update1(ll i,ll old,ll neww)
// {
//     for(;i<=n;i+= i&-i)
//         bt[i]=bt[i]+(neww%2)-(old%2);
// }

ll query(ll r)
{
    ll s=0;
    for(;r;r-= r&-r){
        // cout<<bt[r]<<" ";
        s+=bt[r];
    }
    // cout<<endl;
    return s;
}





int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef PARTH_LATHIYA_HOME

        freopen("E_in.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

    // ll n;+
    bt.clear();
    cin>>n;
    ll a[n+1];
    unordered_map<ll,vll> pp;
    re(i,n){
        cin>>a[i+1];
        if(i)
        {
            if(a[i+1]>=i+1)
                pp[i].pb(i+1);
            else
                pp[a[i+1]].pb(i+1);
        }
    }
    ll ans=0;
    re(i,n) {
        update(a[i+1]);
        // cout<<"S";
        for(auto aa:pp[i+1])
        {
            ll t1=query(1000000000);
            ll t2=query(aa-1);
            // cout<<t1<<" "<<t2<<endl;
            ans+=(t1)-t2;
        }
    }
    cout<<ans;
    // s(q);
    // ll x,y,z;
    // re(i,q)
    // {
    //     cin>>x>>y>>z;
    //     if(x==0){
    //         update1(y,a[y],z);
    //         a[y]=z;
    //     }
    //     else if(x==1)
    //         cout<<(z-y+1)-(query(z)-query(y-1))<<endl;
    //     else
    //         cout<<query(z)-query(y-1)<<endl;
    // }

//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}