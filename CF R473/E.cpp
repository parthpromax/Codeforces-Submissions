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
    
    // vppll v;
    // re(i,n)
    // // ll mm=INF/*;
    // // ll i=1000000000;
    //     for(ll j=0;j<i;j++){
    //         v.push_back({{(i^j),i},j});
    //         // cout<<i<<" "<<j<<" "<<(i^j)<<endl;
    //     }
    //     srt(v);
    //     for(auto aa:v)
    //     {
    //         // cout<<aa.ff.ss<<" "<<aa.ss<<" "<<aa.ff.ff<<endl;
    //     }
    //     // {
    //         // mm=min(mm,(i^j));
    // //     }
    // //     cout<<mm<<endl;
    // ll till=log2(n);
    // ll i;
    

    s(n);
    ll ans=0;
    ll till=ceil(log2(n));
    n--;
    // int i=38;
    ll temp=1;
    // cout<<temp<<endl;
     // temp=temp<<38;
    for(ll i=1;i<=till;i++){
        ans+=(((n-temp)/(2*temp))+1)*(temp);
        temp*=2;
    }
    cout<<fixed<<ans;

//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}