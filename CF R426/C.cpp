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
#define mll std::map<ll, ll> 
#define mpll std::map<pll, ll>
#define mppll std::map<ppll, ll>
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


vll primes;
mll prime;
mll primee;

void sieve(ll n)
{
	rep(i,2,n+1)
	{
		if(!prime[i])
		{	
			primes.pb(i);
			primee[i]=1;
			// s.pb(i);
			for(ll j=i+i;j<=n;j+=i)
				prime[j]=1;
		}
	}
}


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifdef PARTH_LATHIYA_HOME

		freopen("C_in.txt","r",stdin);
	
		ll ttt,bkkk;
		cin>>ttt;
		bkkk=ttt;
		while(ttt--) {
			cout<<"Testcase - "<<bkkk-ttt<<"\n";
	#endif

//--------------------------------------------------------------------------------------

	// std::vector<int> v[100];
	// std::vector<int> temp(100,4);
	// rep(i,0,100)
	// 	v[i] = temp;

	s(n);
	sieve(31634);
	ll x,y;
	while(n--)
	{
		cin>>x>>y;
		ll bkx=x;
		ll bky=y;
		vpll vx,vy;
		for(auto a:primes)
		{
			if(a>x)break;
			ll cnt=0;
			while(x!=1 && x%a==0)
			{
				cnt++;
				x/=a;
			}
			if(primee[x]==1)
			{
				vx.pb({x,1});x=1;
				// break;
			}
			if(cnt)
				vx.pb({a,cnt});
		}
		for(auto a:primes)
		{
			if(a>y)break;
			ll cnt=0;
			while(y!=1 && y%a==0)
			{
				cnt++;
				y/=a;
			}
			if(primee[y]==1)
			{
				// cout<<y;
				vy.pb({y,1});y=1;
				// break;
			}
			// cout<<y<<"dd"<<cnt<<"d"<<endl;
			if(cnt)
				vy.pb({a,cnt});
		}
		int ans=-1;
		// cout<<vx.size()<<vy.size();
		if(bkx==1 && bky==1)
			ans=1; 
		else if(x!=1 && y!=1)
			ans=0;
		else if(vx.size()!=vy.size())
			ans=0;
		else
		{
			srt(vx);
			srt(vy);
			ll i=0;
			while(i<vx.size())
			{
				if(vx[i].ff!=vy[i].ff)
					{ans=0; break;}
				else
				{
					// ll temp=vx[i].ss;
					int f=0;
					// re(p,temp/2+1)
					// {
					// 	cout<<p<<"s";
					// 	cout<<p<<" "<<(temp-p*2)*2+p<<endl;
					// 	if((temp-p*2)*2+p==vy[i].ss){
					// 		f=1;break;}
					// }
					// if(f==0)
					// 	{ans=0; break;}

					ll t1=vx[i].ss;
					ll t2=vy[i].ss;
					while(t1>=0 && t2>=0)
					{
						if(t1>t2){t1-=2;
							t2--;
						}
						else
						{
							t1--;
							t2-=2;
						}
						if(t1==0 && t2==0){f=1;break;}
					}
					if(f==0)
					{				ans=0;break;}

				}
				
				i++;
			}
			if(ans==-1)
				ans=1;
		}
		if(ans==0)
			cout<<"No\n";
		else
			cout<<"Yes\n";
			
	}



//--------------------------------------------------------------------------------------
	
	#ifdef PARTH_LATHIYA_HOME
		cout<<"\n"; }
	#endif

	return 0;
}