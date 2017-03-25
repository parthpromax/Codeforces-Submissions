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
	freopen("B_in.txt","r",stdin);
#endif

	int n,m;
	cin>>n>>m;

	set<int> *e;
    e = new set<int>[n];

    forall(i,0,m)
    {
        ll p, q;
        cin>>p>>q;
        e[p-1].insert(q-1);
        e[q-1].insert(p-1);
    }

     forall(i,0,n)
    {
for (set<int>::iterator it=e[i].begin(); it!=e[i].end(); ++it)
cout<<*it<<" ";
cout<<endl;    	
    }
int ans=1;
    forall(i,0,n)
    {

for (set<int>::iterator it=e[i].begin(); it!=e[i].end(); ++it)
    	{
for (set<int>::iterator it1=e[*it].begin(); it1!=e[*it].end(); ++it1)
    		{	
				if(i!=*it1 && e[i].find(*it1)==e[i].end())
				{
					ans=0;
					break;
				}
    		}
    	if(!ans)break;
    	}
    	if(!ans)break;

    }
if(ans)
	cout<<"YES";
else
	cout<<"NO";

    return 0;
}
