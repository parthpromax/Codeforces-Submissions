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

ll a[212345];
ll st[823456][2];


void build(ll x,ll s,ll e)
{
    // cout<<x<<" "<<s<<" "<<e<<endl;
    if(s==e)
        st[x][0]=a[s-1];
   else{
        ll mid=(s+e)>>1;
        build(x<<1,s,mid);
        build((x<<1)+1,mid+1,e);
        st[x][0]=min(st[x<<1][0],st[(x<<1)+1][0]);
    }
}

void update(ll x,ll s,ll e,ll l,ll r,ll y)
{
    if(st[x][1]!=0){
        st[x][0]+=(e-s+1)*st[x][1];
        if(s!=e){
            st[x<<1][1]+=st[x][1];
            st[(x<<1)+1][1]+=st[x][1];
        }
        st[x][1]=0;
    }
    
    if(e<l || r<s)
        return;

    if(l<=s && e<=r){
        st[x][0]+=(e-s+1)*y;
        if(s!=e){
            st[x<<1][1]+=y;
            st[(x<<1)+1][1]+=y;
        }
        return;
    }

    ll mid=(s+e)>>1;
    update(x<<1,s,mid,l,r,y);
    update((x<<1)+1,mid+1,e,l,r,y);
    st[x][0]=min(st[x<<1][0],st[(x<<1)+1][0]);

}

ll query(ll x,ll s,ll e,ll l,ll r)
{
    // cout<<x<<s<<e<<l<<r<<endl;
    if(st[x][1]!=0){
        st[x][0]+=(e-s+1)*st[x][1];
        if(s!=e){
            st[x<<1][1]+=st[x][1];
            st[(x<<1)+1][1]+=st[x][1];
        }
        st[x][1]=0;
    }

    if(e<l || r<s)
        return maxlong;
    
    if(l<=s && e<=r)
        return st[x][0];

    ll mid=(s+e)>>1;
    return min(query(x<<1,s,mid,l,r),query((x<<1)+1,mid+1,e,l,r));
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef PARTH_LATHIYA_HOME

        freopen("52_C_in.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

    s(n);
    
    re(i,n)
        cin>>a[i];

    build(1,1,n);
    s(m);
    string aa;
    scanf("\n");
    re(p,m+1){
        getline(cin,aa);
        if(!p) continue;
        // cout<<aa<<"oero"<<endl;
        ll i=0;
        while(aa[i]!=' ')i++;
        ll l=0;
        re(j,i)
            l+=(aa[j]-'0')*pow(10,i-1-j);
        i++;
        // cout<<l<<"dddads";
        ll j=i;
        while(i<aa.length() && aa[i]!=' ')i++;
        ll r=0;
        re(k,i-j)
            r+=(aa[k+j]-'0')*pow(10,(i-1-j-k));
        ll type;
        // cout<<l<<" "<<r<<"ddkjhlk"<<endl;
        if(i==aa.length()){
            type=1;
            if(l>r)
                cout<<min(query(1,1,n,l+1,n),query(1,1,n,1,r+1))<<endl;
            else
                cout<<query(1,1,n,l+1,r+1)<<endl;
        }
        else{
            type=2;
            i++;
            int neg=0;
            if(aa[i]=='-'){neg=1;i++;}
            j=i;
            while(i<aa.length() && aa[i]!=' ')i++;
            ll v=0;
            re(k,i-j){
// cout<<v<<endl;
                v = v + (ll)((aa[k+j]-'0')*pow(10,(i-1-j-k)));
                // cout<<v;
            // cout<<"d"<<(ll)((aa[k+j]-'0')*pow(10,(i-1-j-k)))<<"d";
                // cout<<"d"<<pow(10,(i-1-j-k))<<"dd"<<endl;
            }
            // cout<<"d"<<neg<<v<<"d";
            if(neg==1)
                v*=-1;
            // cout<<l<<r<<v;
            if(v==0)
                continue;
            if(l>r){
                update(1,1,n,l+1,n,v);
                update(1,1,n,1,r+1,v);
            }
            else
                update(1,1,n,l+1,r+1,v);
        }
    }

//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;

    
}