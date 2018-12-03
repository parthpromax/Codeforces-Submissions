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

        freopen("B_in.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

    s(t);
    ll a[t],b[t];
    re(i,t-1)
    {
        cin>>a[i];
    }
    re(i,t-1)
    {
        cin>>b[i];
    }
    int temp[t+1][2];
    re(i,t+1)
        re(j,2)
            temp[i][j]=-1;
    ll ans=1;
    re(i,t-1)
    {
        // ll tmp=(~a[i]);
        // cout<<(tmp%2==0)<<"Sds";
        // cout<<((tmp>>1)%2==0)<<"asa";
        // cout<<b[i];
        // ll tmp1 =(~a[i]) & b[i];
        // cout<<tmp1; 
        if( ((~a[i]) & b[i]) != 0){
            // cout<< ((~a[i]) & b[i]) ;
            ans=0;
            break;
        }
    }
    if(ans==0)
    {
        cout<<"NO";
    }
    else
    {
        re(i,t-1)
        {
            if((a[i]&1) == 0  && (b[i]&1) == 0)
            {
                temp[i][1]=0;
                temp[i+1][1]=0;
            }
            if((a[i]&1) == 1  && (b[i]&1) == 1)
            {
                temp[i][1]=1;
                temp[i+1][1]=1;
            }
            if(((a[i]>>1)&1) == 0  && ((b[i]>>1)&1) == 0)
            {
                temp[i][0]=0;
                temp[i+1][0]=0;
            }
            if(((a[i]>>1)&1) == 1  && ((b[i]>>1)&1) == 1)
            {
                temp[i][0]=1;
                temp[i+1][0]=1;
            }
        }

        int i=0;
        for(i=0;i<t;i++)
        {
            if(temp[i][0]!=-1)
                break;
        }
        int tempo=i+1;
        for(;tempo<t;tempo++)
        {
            if(temp[tempo][0]==-1)
                temp[tempo][0] = temp[tempo-1][0]==0?1:0;
        }
        tempo=i;
        for(;tempo>=0;tempo--)
        {
            if(temp[tempo][0]==-1)
                temp[tempo][0] = (temp[tempo+1][0]==0?1:0);
        }

        i=0;
        for(i=0;i<t;i++)
        {
            if(temp[i][1]!=-1)
                break;
        }
        tempo=i+1;
        for(;tempo<t;tempo++)
        {
            if(temp[tempo][1]==-1)
                temp[tempo][1] = (temp[tempo-1][1]==0?1:0);
        }
        tempo=i;
        for(;tempo>=0;tempo--)
        {
            if(temp[tempo][1]==-1)
                temp[tempo][1] = (temp[tempo+1][1]==0?1:0);
        }

        cout<<"YES\n";
        re(i,t)
        {
            cout<<temp[i][0]*2+temp[i][1]<<" ";
        }
    }


//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}