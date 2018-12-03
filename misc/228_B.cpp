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

char a[51][51];
char b[51][51];


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef PARTH_LATHIYA_HOME

        freopen("228_B_in.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

    s(x);
    s(y);
    // ll a[x][y];
    re(i,x)
        re(j,y)
            cin>>a[i][j];
    s(x1);
    s(y1);
    // ll b[x1][y1];
    re(i,x1)
        re(j,y1)
            cin>>b[i][j];
    ll x2=-1;
    ll y2=-1;
    ll mm=-1;
    ll ans;
    // re(i,x1)
    for(ll i=-x;i<x1;i++)
        for(ll j=-y;j<y1;j++) {
        // re(j,y1){
            ans=0;
            // cout<<i<<j<<endl;    
            re(k,x)
                re(l,y)
                    if(k+i>=0 && l+j>=0 && k+i<x1 && l+j<y1)
                    ans+=(a[k][l]-'0')*(b[k+i][l+j]-'0');
            if(ans>mm){
                mm=ans;
                x2=i;
                // cout<<i<<endl;
                y2=j;
            }
        }
    cout<<x2<<" "<<y2;
//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}