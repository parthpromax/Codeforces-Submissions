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

ll levels;
ll a[223456];
ll st[823456];

void build(ll x,ll s,ll e)
{
    // cout<<x<<" "<<s<<" "<<e<<endl;
    if(s==e){
        st[x]=a[s-1];
        // cout<<x<<" "<<st[x]<<endl;

    }
    else{
        ll mid=(s+e)>>1;
        build(x<<1,s,mid);
        build((x<<1)+1,mid+1,e);
        if((levels-(ll)log2(x))%2)
            st[x]=st[x<<1]|st[(x<<1)+1];
        else
            st[x]=st[x<<1]^st[(x<<1)+1];
    }
}

void update(ll x,ll s,ll e,ll idx,ll y)
{
    if(s==e){
        // cout<<x<<"d"<<endl;
        st[x]=y;
    }
    else{
        ll mid=(s+e)>>1;
        if(s<=idx && idx<=mid)
            update(x<<1,s,mid,idx,y);
        else
            update((x<<1)+1,mid+1,e,idx,y);
        if((levels-(ll)log2(x))%2)
            st[x]=st[x<<1]|st[(x<<1)+1];
        else
            st[x]=st[x<<1]^st[(x<<1)+1];
    }
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef PARTH_LATHIYA_HOME

        freopen("339_D_in.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

    s(n);
    s(m);
    levels=n;
    ll till=1<<n;
    re(i,till)
        cin>>a[i];
    build(1,1,till);
    ll p,b;
    re(i,m)
    {
        cin>>p>>b;
        update(1,1,till,p,b);
        cout<<st[1]<<endl;
    }


//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;

    
}