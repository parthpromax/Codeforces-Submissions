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

ll st[4123456][3];
string a;

void build(ll x,ll s,ll e)
{
    if(s==e){
        if(a[s-1]=='(')
            st[x][0]=1;
        else
            st[x][1]=1;
    }
    else
    {
        ll mid=(s+e)>>1;
        build(x<<1,s,mid);
        build((x<<1)+1,mid+1,e);
        st[x][2]=st[x<<1][2]+st[(x<<1)+1][2]+min(st[x<<1][0],st[(x<<1)+1][1])*2;
        st[x][0]=st[x<<1][0]+st[(x<<1)+1][0]-min(st[x<<1][0],st[(x<<1)+1][1]);
        st[x][1]=st[x<<1][1]+st[(x<<1)+1][1]-min(st[x<<1][0],st[(x<<1)+1][1]);
    }
    // cout<<x<<" "<<s<<" "<<e<<" "<<st[x][0]<<" "<<st[x][1]<<" "<<st[x][2]<<endl;
}


ppll query(ll x,ll s,ll e,ll l,ll r)
{

    if(e<l || r<s)
        return {0,{0,0}};
    if(l<=s && e<=r)
        return {st[x][0],{st[x][1],st[x][2]}};
    ll mid=(s+e)>>1;
    ppll a=query(x<<1,s,mid,l,r);
    ppll b=query((x<<1)+1,mid+1,e,l,r);
    ppll temp;
    temp.ss.ss=a.ss.ss+b.ss.ss+min(a.ff,b.ss.ff)*2;
    temp.ff=a.ff+b.ff-min(a.ff,b.ss.ff);
    temp.ss.ff=a.ss.ff+b.ss.ff-min(a.ff,b.ss.ff);
    return temp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef PARTH_LATHIYA_HOME

        freopen("380_C_in.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

    cin>>a;
    build(1,1,a.length());
    s(n);
    ll l,r;
    re(i,n){
        cin>>l>>r;
        cout<<query(1,1,a.length(),l,r).ss.ss<<endl;
        // cout<<st[1][2]<<endl;
    }

//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}