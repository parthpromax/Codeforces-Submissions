#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b)                for(ll i=a;i<b;i++)
#define repr(i,n)                for(ll i=n-1;i>=0;i--)
#define ll long long int
#define ld long double
#define llu long long unsigned
#define pb push_back
#define mod 1000000007
/*
                    ** author **
                ** Parth Lathiya **
    ** https://www.cse.iitb.ac.in/~parthiitb/ **
*/



int main()
{

ios::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
	freopen("C_in.txt","r",stdin);
#endif

//  --------------------------------------------------------------------------------------

    string a;
    cin>>a;
    ll dp[a.length()][3];
    dp[0][0]=((int)a[0]%3)==0?0:100002;
    dp[0][1]=((int)a[0]%3)==1?0:100002;
    dp[0][2]=((int)a[0]%3)==2?0:100002;
    rep(i,1,a.length())
    {
        if(a[i]!='0')
        {
            if(((int)a[i]%3)==0)
            {
                dp[i][0]=min(i,dp[i-1][0]);
                dp[i][1]=dp[i-1][1];
                dp[i][2]=dp[i-1][2];
            }
            else if(((int)a[i]%3)==1)
            {
                dp[i][0]=min(dp[i-1][2],dp[i-1][0]+1);
                dp[i][1]=min(min(i,dp[i-1][0]),dp[i-1][1]+1);
                dp[i][2]=min(dp[i-1][1],dp[i-1][2]+1);
            }
            else if(((int)a[i]%3)==2)
            {
                //cout<<"ss";
                dp[i][0]=min(dp[i-1][1],dp[i-1][0]+1);
                dp[i][1]=min(dp[i-1][2],dp[i-1][1]+1);
                dp[i][2]=min(min(i,dp[i-1][0]),dp[i-1][2]+1);
            }
        }
        else
        {

                dp[i][0]=min(i,dp[i-1][0])==i?i+1:min(i,dp[i-1][0]);
                dp[i][1]=dp[i-1][1]==i?i+1:dp[i-1][1];
                dp[i][2]=dp[i-1][2]==i?i+1:dp[i-1][2];
        }
    }
cout<<dp[a.length()-1][0]<<a.length();
  if(dp[a.length()-1][0]>=a.length())
    {
cout<<"s";
    }

//  --------------------------------------------------------------------------------------

return 0;
}
