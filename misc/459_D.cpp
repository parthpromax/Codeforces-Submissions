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

ll st[4123456];


void update(ll x,ll s,ll e,ll idx,ll y)
{
    if(s==e)
        st[x]+=y;
    else
    {
        ll mid=(s+e)>>1;
        if(s<=idx && idx<=mid)            
            update(x<<1,s,mid,idx,y);
        else
            update((x<<1)+1,mid+1,e,idx,y);
        st[x]=st[x<<1]+st[(x<<1)+1];
    }
}


ll query(ll x,ll s,ll e,ll l,ll r)
{
    if(e<l || r<s)
        return 0;
    if(l<=s && e<=r)
        return st[x];
    return query(x<<1,s,(s+e)>>1,l,r)+query((x<<1)+1,((s+e)>>1)+1,e,l,r);
}



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef PARTH_LATHIYA_HOME

        freopen("459_D_in.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

    s(n);
    ll a[n];
    re(i,n)
        cin>>a[i];
    ll l[n];
    ll r[n];
    mll m;
    re(i,n){
        m[a[i]]++;
        l[i]=m[a[i]];
    }
    m.clear();
    repr(i,n){
        m[a[i]]++;
        r[i]=m[a[i]];
    }
    // set<ll> s;
    // build(1,1,1000000);
    // re(i,n)
    //     cout<<r[i]<<" ";
    ll ans=0;
    repr(i,n){
        // cout<<query(1,1,1000000,1,l[i]-1)<<endl;
        ans+=query(1,1,1000000,1,l[i]-1);
        update(1,1,1000000,r[i],1);
        // cout<<st[1048576]<<"ss"<<endl;
    }
    cout<<ans<<endl;

//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}