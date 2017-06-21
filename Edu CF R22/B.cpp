#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)                for(ll i=a;i<b;i++)
#define re(i,b)                for(ll i=0;i<b;i++)
#define repr(i,n)                for(ll i=n-1;i>=0;i--)
#define ll long long
#define ld long double
#define llu long long unsigned
#define vll std::vector<ll>
#define mll std::map<ll, ll>
#define mpll std::map<pair<ll,ll>, ll>
#define sll std::set<ll>
#define msll std::multiset<ll>
#define all(c) c.begin(), c.end()
#define allr(c) c.rbegin(), c.rend()
#define srt(x) sort(all(x))
#define rsrt(x) sort(allr(x))
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define s(yy) ll yy;cin>>yy
#define mod 1000000007
#define maxlong 9223372036854775808


/*
###################################################### 
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#      https://www.cse.iitb.ac.in/~parthiitb/        #
#                                                    #
###################################################### 
*/


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("B_in.txt","r",stdin);
    #endif


//--------------------------------------------------------------------------------------
    
    s(x);
    s(y);
    s(l);
    s(r);

    vll xp;
    vll yp;
    ll cx=1,cy=1;
    ll cox=1e18/x,coy=1e18/y;
    rep(i,0,1e18)
    {
        if(cox<cx){
            xp.pb(cx);
            break;
        }
        xp.pb(cx);
        cx*=x;
    }
    rep(i,0,1e18)
    {
        if(coy <cy ){
            yp.pb(cy);
            break;
        }
        yp.pb(cy);
        cy*=y;
    }
    sll rg;
    rep(i,0,xp.size()){
        rep(j,0,yp.size()){

            if(xp[i]+yp[j]>=l && xp[i]+yp[j]<=r)
                rg.insert(xp[i]+yp[j]);
        }
    }

    if(rg.empty())
    {
        cout<<r-l+1;
        return 0;
    }
    ll ma=*rg.begin()-l;
    // srt(rg);
    sll::iterator it;
    for(it=rg.begin();it!=rg.end();){
        // cout<<*it<<endl;
        ll aa=*it;
        it++;
        if(it==rg.end()){
            ma=max(ma,r-aa);
            break;}
        ll bb=*it;
        ma=max(ma,bb-aa-1);
// cout<<bb;


    } 
    cout<<ma;

//--------------------------------------------------------------------------------------

    return 0;
}
