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
#define len length()
#define sz size()


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

        freopen("471_D.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

    s(n);
    s(w);
    ll a[n];
    ll aa[n];
    ll b[w];
    ll bb[w];
    re(i,n){
        cin>>a[i];
        if(i)
            aa[i]=a[i]-a[i-1];
    }
    re(i,w){
        cin>>b[i];
        if(i)
            bb[i]=b[i]-b[i-1];
    }

    ll c[n+w];
    ll st=0;
    re(i,w-1)
        c[st++]=bb[i+1];
    c[st++]=maxlong;
    re(i,n-1)
        c[st++]=aa[i+1];
    
    ll l=0,r=0;    
    ll z[st];
    ll ans=0;
    if(w==1){
        cout<<n;
        return 0;
    }
    // re(i,st)
    //     cout<<c[i]<<" ";
    rep(i,1,st)
    {
        if(i>r)
        {
            // cout<<i<<"ss"<<endl;
            l=i;
            r=i;
            while(r<st && c[r-l]==c[r])r++;
            z[i]=r-l;
            r--;
        }
        else
        {
            if(z[i-l]<r-i+1)
                z[i]=z[i-l];
            else
            {
                l=i;   
                while(r<st && c[r-l]==c[r])r++;
                z[i]=r-l;
                r--;
            }
        }
        
        // cout<<z[i]<<endl;
        if(z[i]==w-1)ans++;
    }   
    cout<<ans;

//-------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}