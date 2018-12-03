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


string a[2123];
ll n;

string dp[2123][2123];

string findd(int r,int c)
{
    if(dp[r][c]!="")
        return dp[r][c];

    if(r==n-1)
    {
        string temp="";
        rep(i,c,n)
            temp+=a[r][i];
        return dp[r][c]=temp;
    }

    if(c==n-1)
    {
        string temp="";
        rep(i,r,n)
            temp+=a[i][c];
        return dp[r][c]=temp;
    }

    if(a[r+1][c]<a[r][c+1])
        return dp[r][c]=a[r][c]+findd(r+1,c);
    if(a[r+1][c]>a[r][c+1])
        return dp[r][c]=a[r][c]+findd(r,c+1);
    string temp1=findd(r+1,c);
    string temp2=findd(r,c+1);
    if(temp1<temp2)
        return dp[r][c]=a[r][c]+temp1;
    else
        return dp[r][c]=a[r][c]+temp2;
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

    cin>>n;
    s(k);

    re(i,n)
        cin>>a[i];
    re(i,n)
        re(j,n)
            dp[i][j]="";
    int f;
    string ans="";
    int done=0;
    for(int x=0;x<n;x++)
    {
        f=0;
        for(int r=0;r<=x;r++)
        {
            // cout<<a[r][x-r]<<"pop";
            if(a[r][x-r]=='a')
                f=1;
        }
        if(!f)
        {
            // cout<<"its not a\n";
            if(k==0)
            {
                // if(x == n-1)
                //     break;
                // cout<<x<<"Asa"<<endl;
                int mr=0;
                int mc=x;
                for(int r=0;r<=x;r++)
                {
                    // cout<<a[r][x-r]<<"sasa";
                    if(a[r][x-r] < a[mr][mc])
                    {

                        mr=r;
                        mc=x-r;
                    }
                    //     f=1;
                }
                ll best=a[mr][mc];
                string minn="";
                re(i,2*n-x+1)
                    minn+='z';
                for(int r=0;r<=x;r++)
                {
                    // cout<<a[r][x-r]<<"sasa";
                    if(a[r][x-r]==best)
                    {
                        string temp=findd(r,x-r);
                        if(temp<minn)
                        {
                            minn=temp;
                        }
                    }
                    //     f=1;
                }
                ans+=minn;
                done=1;
                break;
            }
            else
                ans+='a';
            k--;
        }
        else
        {
            // cout<<"Its a\n";
            ans+='a';
        }
    }
    // cout<<ans<<endl;
    // cout<<k<<endl;
    if(!done) {
        for(int x=n;x<2*n-1;x++)
        {
            f=0;
            for(int r=x-n+1;r<n;r++)
            {
                // cout<<a[r][x-r]<<" ";
                if(a[r][x-r]=='a')
                    f=1;
            }
            if(!f)
            {
                // cout<<"ITs not a\n";
                if(k==0)
                {
                    if(x == 2*n-1)
                        break;
                    
                    int mr=x-n+1;
                    int mc=x-mr;
                    for(int r=x-n+1;r<n;r++)
                    {
                        if(a[r][x-r] < a[mr][mc])
                        {
                            mr=r;
                            mc=x-r;
                        }
                        //     f=1;
                    } 
                    ll best=a[mr][mc];
                    string minn="";
                    re(i,2*n-x+1)
                        minn+='z';
                    for(int r=x-n+1;r<n;r++)
                    {
                        // cout<<a[r][x-r]<<"sasa";
                        if(a[r][x-r]==best)
                        {
                            string temp=findd(r,x-r);
                            if(temp<minn)
                            {
                                minn=temp;
                            }
                        }
                        //     f=1;
                    }
                    ans+=minn;
                    break;
                }
                else
                    ans+='a';
                k--;
            }
            else
            {
                ans+='a';
            }

        }
    }

    cout<<ans;

//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}