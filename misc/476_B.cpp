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

ll fact(ll a)
{
    if(a==0)
        return 1;
    if(a==1)
        return 1;
    return a*fact(a-1);

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef PARTH_LATHIYA_HOME

        freopen("476_B.txt","r",stdin);
    
        ll ttt,bkkk;
        cin>>ttt;
        bkkk=ttt;
        while(ttt--) {
            cout<<"Testcase - "<<bkkk-ttt<<"\n";
    #endif

//--------------------------------------------------------------------------------------

    string s1,s2;

    cin>>s1>>s2;
    ll p=0,m=0;
    re(i,s1.len)
        if(s1[i]=='+')
            p++;
        else
            m++;
    ll p1=0,m1=0,q=0;
    re(i,s2.len)
         if(s2[i]=='+')
            p1++;
        else if(s2[i]=='-')
            m1++;
        else
            q++;

    cout<<fixed<<setprecision(12);
    if(q==0 && p==p1 && m==m1)
        cout<<1.0;
    else if(p1>p || m1>m || (p-p1)>q || (m-m1)>q)
        cout<<0.0;
    else
        cout<< ( fact(q)/fact(q+p1-p)/fact(p-p1))*1.0/ (1<<q);
   

//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}