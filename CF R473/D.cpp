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

vll pff[112345];
ll a[112345];
ll alr[112345];
ll pp[3234567];
void pf()
{
    rep(i,2,112345)
    {
        for(ll j=i;j<112345;j+=i)
        {
            pff[j].pb(i);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef PARTH_LATHIYA_HOME

        freopen("D_in.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------
  
    pf();
    s(n);
    ll i;
    int f;
    re(i,n)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        // cin>>a[i];
        f=0;
        for(auto aa:pff[a[i]])
        {
            if(alr[aa]){
                f=1;
                break;
            }
        }
        if(!f){
            for(auto aa:pff[a[i]]){
                alr[aa]=1;
                for(ll k=aa;k<3234567;k+=aa)
                    pp[k]=1;
            }
        }
        else{
            for(ll k=a[i]+1;k<3234567;k++){
                if(!pp[k])
                {
                    a[i]=k;
                    for(auto aa:pff[k])
                        for(ll o=aa;o<3234567;o+=aa)
                            pp[o]=1;
                    break;
                }
            }
            break;
        }
    }
    i++;
    for(ll k=2;k<3234567 && i<n;k++)
        if(!pp[k]) {
            a[i++]=k;
            for(ll o=k;o<3234567;o+=k)
                pp[o]=1;
        }
    re(i,n)
        cout<<a[i]<<" ";

//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}