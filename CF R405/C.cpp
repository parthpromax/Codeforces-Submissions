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


int main()
{

#ifndef ONLINE_JUDGE
	freopen("C_in.txt","r",stdin);
#endif

	int n,k;
	cin>>n>>k;
	int smart=0;
	string h[52]={"Aa","Ba","Ca"
	,"Da","Ea","Fa","Ga","Ha","Ia","Ja","Ka","La","Ma","Na","Oa","Pa","Qa","Ra","Sa","Ta","Ua","Va","Wa","Xa","Ya","Za","A","B","C"
	,"D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

		string a[n-k+1];
	string ans[n];
	forall(i,0,n-k+1)
	{cin>>a[i];}
	forall(i,0,k-1)
	{
		cout<<h[smart++]<<" ";
		ans[i]=h[smart-1];
	}

	forall(i,k-1,n)
	{
		if(a[i-k+1]=="NO")
		{
			if(i==n-1)
				cout<<ans[i-k+1];
			else
				cout<<ans[i-k+1]<<" ";
			ans[i]=ans[i-k+1];
		}
		else
		{
			if(i==n-1)
				cout<<h[smart++];
			else
				cout<<h[smart++]<<" ";
			ans[i]=h[smart-1];
		}
	}
    return 0;
}
