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
#define pll std::pair<ll, ll>
#define mpll std::map<pair<ll,ll>, ll>
#define sll std::set<ll>
#define ff first
#define ss second
#define msll std::multiset<ll>
#define all(c) c.begin(), c.end()
#define allr(c) c.rbegin(), c.rend()
#define srt(x) sort(all(x))
#define rsrt(x) sort(allr(x))
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define s(yy) ll yy;cin>>yy
#define mod 1e9+7
#define maxlong 1e18+5


/*
###################################################### 
#                                                    #
#                     @author                        #
#                  Parth Lathiya                     #
#      https://www.cse.iitb.ac.in/~parthiitb/        #
#                                                    #
###################################################### 
*/

ll a[1000001];
ll ml[1000001],mr[1000001],Ml[1000001],Mr[1000001];
        

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

    s(n);


    re(i,n)
        cin>>a[i];


    stack<ll> s;
    re(i,n)
    {
        if(!s.empty() && a[s.top()]<a[i]){
            while(!s.empty() && a[s.top()]<a[i])
            {
                Mr[s.top()]=i;
                s.pop();
                // s.push(i);
            }
            s.push(i);
        }
        else
        {
            s.push(i);
        }
    }
    while(!s.empty())
    {
        Mr[s.top()]=n;
        s.pop();
    }

    repr(i,n)
    {
        if(!s.empty() && a[s.top()]<=a[i]){
            while(!s.empty() && a[s.top()]<=a[i])
            {
                Ml[s.top()]=i;
                s.pop();
                // s.push(i);
            }
            s.push(i);
        }
        else
        {
            s.push(i);
        }
    }
    while(!s.empty())
    {
        Ml[s.top()]=-1;
        s.pop();
    }
    // if(s.empty())cout<<"s";
    re(i,n)
    {   
        // if(i)cout<<s.top()<<" "<<a[i];
        if(!s.empty() && a[s.top()]>a[i]){
            while(!s.empty() && a[s.top()]>a[i])
            {
                mr[s.top()]=i;
                s.pop();
                // s.push(i);
            }
            s.push(i);
        }
        else
        {
            s.push(i);
        }
    }
    while(!s.empty())
    {
        mr[s.top()]=n;
        s.pop();
    }
    // cout<<"ss"<<mr[1]<<endl;
    repr(i,n)
    {
        if(!s.empty() && a[s.top()]>=a[i]){
            while(!s.empty() && a[s.top()]>=a[i])
            {
                ml[s.top()]=i;
                s.pop();
                // s.push(i);
            }
            s.push(i);
        }
        else
        {
            s.push(i);
        }
    }
    while(!s.empty())
    {
        ml[s.top()]=-1;
        s.pop();
    }


    ll ans=0;
    // re(i,n)
    //     cout<<Ml[i]<<Mr[i]<<ml[i]<<mr[i]<<endl;
    re(i,n)
        ans += a[i]* ((Mr[i]-i)*(i-Ml[i]));
    re(i,n)
        ans -= a[i]* ((mr[i]-i)*(i-ml[i]));
    cout<<ans;
    // ll l=1;
    // ll r=n+1,mid;
    // while(l<r-1)
    // {
    //     mid=(l+r)/2;
    //     ll temp=mid;
    //     ll diff=0;
    //     ll i=0,mul=1;
    //     while(temp)
    //     {
    //         diff+= (temp%10)*mul;
    //         temp/=10;
    //         if(mul!=1)
    //             mul += 9*pow(10,i++);
    //         else
    //             mul=9;
    //     }
    //     if(diff>s)
    //         r=mid;
    //     else
    //         l=mid;
    // }

    // cout<<l;
 

//--------------------------------------------------------------------------------------
    
    #ifdef PARTH_LATHIYA_HOME
        cout<<"\n"; }
    #endif

    return 0;
}