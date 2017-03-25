#include <bits/stdc++.h>
using namespace std;

#define forall(i,a,b)                for(int i=a;i<b;i++)
#define ll long long int
#define llu long long unsigned
#define vll vector<ll>
#define vllu vector<llu>
#define sll set<ll>
#define sllu set<llu>
#define pb push_back
#define mll map<ll,ll>
#define mllu map<llu,llu>
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define mod 1000000007

llu ncr(int n, int r) {
    if(n<r)return 0;
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    llu ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}



int main()
{

	string s;
	cin>>s;
	vector<int>open;
	vector<int>close;
	int pos[200001];

	forall(i,0,200001)
		pos[i]=0;

    forall(i,0,s.length())
    	if(s[i]=='(')
    		open.pb(i+1);
    	else
    		close.pb(i+1);

    int cnt=1;int bk=-1;

    for (vector<int>::reverse_iterator  it = close.rbegin() ; it != close.rend(); it++)
	{
		pos[(*it)-1]=cnt;
		if(bk!=-1)forall(i,(*it),bk)pos[i]=cnt-1;
		bk=(*it)-1;
		cnt++;
	}

	cnt=0;
	llu ans=0;

	for (vector<int>::iterator it = open.begin() ; it != open.end(); it++)
	{
		forall(i,0,cnt+1)
			ans = (ans + (ncr(cnt,i)*ncr(pos[*it],i+1))%mod)% mod ;
		cnt++;
	}

	cout << ans;

    return 0;
}
