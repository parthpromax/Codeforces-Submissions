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

char a[112][112];
char b[112][112];
char c[112][112];
char d[112][112];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef PARTH_LATHIYA_HOME

        freopen("C_in.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

    s(n);   
    ll aa[4],bb[4];
        ll cnt=0;
        re(j,n)
            re(k,n){
                cin>>a[j][k];
                // cout<<a[j][k]<<endl;
                if((j+k)%2+'0' != a[j][k]){
                    // cout<<j<<k<<endl;
                    cnt++;
                }
            }
        aa[0]=cnt;
        bb[0]=n*n-cnt;
        // cin>>endl;

        cnt=0;
        re(j,n)
            re(k,n){
                cin>>b[j][k];
                if(((j+k)%2)+'0'!=b[j][k])
                    cnt++;
            }
        aa[1]=cnt;
        bb[1]=n*n-cnt;
        // cin>>endl;

        cnt=0;
        re(j,n)
            re(k,n){
                cin>>c[j][k];
                if(((j+k)%2)+'0'!=c[j][k])
                    cnt++;
            }
        aa[2]=cnt;
        bb[2]=n*n-cnt;
        // cin>>endl;

        cnt=0;
        re(j,n)
            re(k,n){
                cin>>d[j][k];
                if(((j+k)%2)+'0'!=d[j][k])
                    cnt++;
            }
        aa[3]=cnt;
        bb[3]=n*n-cnt;
        // cin>>endl;
        // cout<<aa[0];
        ll t[6];
        t[0]=aa[1-1]+aa[2-1]+bb[3-1]+bb[4-1];
        t[1]=aa[1-1]+aa[3-1]+bb[2-1]+bb[4-1];
        t[2]=aa[1-1]+aa[4-1]+bb[2-1]+bb[3-1];
        t[3]=aa[2-1]+aa[3-1]+bb[1-1]+bb[4-1];
        t[4]=aa[2-1]+aa[4-1]+bb[1-1]+bb[3-1];
        t[5]=aa[3-1]+aa[4-1]+bb[1-1]+bb[2-1];
        ll ans=INF;
        re(i,6)
            ans=min(ans,t[i]);
        cout<<ans;
    
//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}