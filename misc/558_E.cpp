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

// ll a[212345];

string a;
ll st[26][412345];


void build(ll x,ll s,ll e,ll segtno)
{
    // cout<<x<<" "<<s<<" "<<e<<endl;
    if(s==e){
        if(a[s-1]=='a'+segtno)
           st[segtno][x]=1;
    }
    else{
        ll mid=(s+e)>>1;
        build(x<<1,s,mid,segtno);
        build((x<<1)+1,mid+1,e,segtno);
        st[segtno][x]=st[segtno][x<<1]+st[segtno][(x<<1)+1];
    }
}

ll query(ll x,ll s,ll e,ll l,ll r,ll segtno)
{
    if(e<l || r<s)
        return 0;
    
    if(l<=s && e<=r)
        return st[segtno][x];

    ll mid=(s+e)>>1;
    return query(x<<1,s,mid,l,r,segtno)+query((x<<1)+1,mid+1,e,l,r,segtno);
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef PARTH_LATHIYA_HOME

        freopen("558_E_in.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

    s(n);
    s(q);
    cin>>a;

    re(i,26)
        build(1,1,n,i);
    string ans;

    re(i,n)
        ans[i]='X';
    ll p,qq,r;
    re(i,q){

        cin>>p>>qq>>r;
        if(r==0)
        {
            ll swi=0;
            re(k,26)
            {
                ll temp=query(1,1,n,p,qq,25-k);
                // cout<<temp<<endl;
                re(l,temp){
                    // cout<<(char)('a'+25-k)<<swi+p<<endl;
                    ans[swi+p-1]=(char)('a'+25-k);
                }
                swi+=temp;
            }
        }
        else
        {
            ll swi=0;
            re(k,26)
            {
                ll temp=query(1,1,n,p,qq,k);
                re(l,temp)
                    ans[swi+p-1]='a'+k;
                swi+=temp;
            }   
        }
    }

    re(i,n)
        if(ans[i]=='X')
            cout<<a[i];
        else
            cout<<ans[i];



//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;

    
}