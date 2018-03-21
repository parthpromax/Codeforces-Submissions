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

ll dp[212345];


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef PARTH_LATHIYA_HOME

        freopen("in.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

    s(n);
    ll a[n],l[n],r[n];

    re(i,n)
        cin>>a[i];
    re(i,n)
        cin>>l[i];
    re(i,n)
        cin>>r[i];

    vppll v;
    re(i,n) {
        v.pb({{i,1},i});
        v.pb({{i+r[i],2},i});
    }

    srt(v);

    set<pll> s;

    ll ans=0;
    re(i,n<<1)
    {

        if(v[i].ff.ss==1)
        {
            if(s.empty()) {
                dp[v[i].ss]=a[v[i].ss];
                continue;
            }

            auto it2=s.rbegin();
            if((v[i].ss-l[v[i].ss])>(*it2).ff) {
                dp[v[i].ss]=a[v[i].ss]+(*it2).ss;
                continue;
            }

            auto it=s.lower_bound({v[i].ss-l[v[i].ss],-1});
            if(it==s.begin()) {
                dp[v[i].ss]=a[v[i].ss];
                continue;
            }

            it--;
            dp[v[i].ss]=a[v[i].ss]+(*it).ss;
            continue;
        }
        else {

            if(s.empty()) {
                s.insert({v[i].ss,dp[v[i].ss]});
                continue;
            }

            auto it2=s.rbegin();

            if((*it2).ff<v[i].ss) {
                if((*it2).ss<dp[v[i].ss])
                    s.insert({v[i].ss,dp[v[i].ss]});
                continue;
            }

            auto it=s.lower_bound({v[i].ss,-1});
            vpll tempp;
            while(it!=s.end()) {
                if(((*it).ff)>v[i].ss && (it->ss)>dp[v[i].ss])
                    break;
                if(((*it).ff)>v[i].ss)
                    tempp.pb({(*it).ff,(*it).ss});
                it++;
            }

            while(tempp.size()) {
                s.erase(s.lower_bound(tempp.back()));
                tempp.pop_back();
            }

            it=s.lower_bound({v[i].ss,-1});
            if(it==s.begin()) {
                s.insert({v[i].ss,dp[v[i].ss]});
                continue;
            }
            it--;

            if((*it).ss<dp[v[i].ss])
                s.insert({v[i].ss,dp[v[i].ss]});
        }
    }
    re(i,n)
        ans=max(ans,dp[i]);
    
    cout<<ans;

//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}