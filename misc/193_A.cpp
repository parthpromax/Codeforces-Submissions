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


char a[51][51];
int doneat[51][51];
ll tin[51][51];
ll low[51][51];

ll timee;
int n,m;
int ap;

void dfs(int i,int j,int pi,int pj)
{
    if(doneat[i][j])
        return;
    tin[i][j]=low[i][j]=timee++;
    doneat[i][j]=true;
    int child=0;
    if(i+1<n && a[i+1][j]=='#' && !(i+1==pi && j==pj))
    {
        if(doneat[i+1][j])
            low[i][j]=min(low[i][j],tin[i+1][j]);
        else
        {
            dfs(i+1,j,i,j);       
            low[i][j]=min(low[i][j],low[i+1][j]);
            if(low[i+1][j]>=tin[i][j] && !(pi==-1 && pj==-1))
                ap=1;
                child++; 
        }
    }
    if(i-1>=0 && a[i-1][j]=='#' && !(i-1==pi && j==pj))
    {
        if(doneat[i-1][j])
            low[i][j]=min(low[i][j],tin[i-1][j]);
        else
        {
            dfs(i-1,j,i,j);       
            low[i][j]=min(low[i][j],low[i-1][j]);
            if(low[i-1][j]>=tin[i][j] && !(pi==-1 && pj==-1))
                ap=1; 
            child++;
        }
    }
    if(j-1>=0 && a[i][j-1]=='#' && !(i==pi && j-1==pj))
    {
        if(doneat[i][j-1])
            low[i][j]=min(low[i][j],tin[i][j-1]);
        else
        {
            dfs(i,j-1,i,j);       
            low[i][j]=min(low[i][j],low[i][j-1]);
            if(low[i][j-1]>=tin[i][j] && !(pi==-1 && pj==-1))
                ap=1; 
            child++;
        }
    }
    if(j+1<m && a[i][j+1]=='#' && !(i==pi && j+1==pj))
    {
        if(doneat[i][j+1])
            low[i][j]=min(low[i][j],tin[i][j+1]);
        else
        {
            dfs(i,j+1,i,j);       
            low[i][j]=min(low[i][j],low[i][j+1]);
            if(low[i][j+1]>=tin[i][j] && !(pi==-1 && pj==-1))
                ap=1; 
            child++;
        }
    }
    if(pi==-1 && pj==-1 && child>1)
        ap=1;
    
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef PARTH_LATHIYA_HOME

        freopen("193_A.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

    cin>>n>>m;
    ll cnt=0;
    ll ti,tj;
    re(i,n)
        re(j,m){
            cin>>a[i][j];
            if(a[i][j]=='#'){cnt++;ti=i; tj=j;}
            doneat[i][j]=0;
        }
    ap=0;
    timee=0;
    int f=1;
    if(!cnt){
        cout<<-1;
        f=0;
    }
    else
        dfs(ti,tj,-1,-1);

    if(f){
        if(ap)
            cout<<1;
        else if(cnt<3)
            cout<<-1;
        else
            cout<<2;
    }

    
//-------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}