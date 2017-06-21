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
#define ite iterator
#define maxlong 9223372036854775808
#define diff(a,b) max(a,b)-min(a,b)

ll n,m;
int vis[101][101]={0};
char a[101][101];
int found=0;
std::vector<char> v;

int dfs(int i,int j)
{
	// cout<<i<<" "<<j<<endl;
	// rep(k,0,v.size())
	// 	cout<<v[k];
	vis[i][j]=1;
	int fr=0;
	if(a[i][j]=='F'){
		found=1;
		// ans=v;
		// cout<<v[0];
		return 1;
	}
	//L R U D
	if(!found && j>1 && a[i][j-1]!='*' && vis[i][j-1]!=1)
	{
		// vis[i][j-1]=1;
		// cout<<v[1];
		if(dfs(i,j-1))
		{v.pb('L');fr=1;}

	}	
	if(!found && j<m && a[i][j+1]!='*' && vis[i][j+1]!=1)
	{
		// v.pb('R');
		// vis[i][j+1]=1;
		if(dfs(i,j+1)){
		v.pb('R');fr=1;}

	}
	if(!found && i>1 && a[i-1][j]!='*' && vis[i-1][j]!=1)
	{
		// v.pb('U');
		// vis[i-1][j]=1;
		if(dfs(i-1,j)){
		v.pb('U');fr=1;}

	}
	if(!found && i<n && a[i+1][j]!='*' && vis[i+1][j]!=1)
	{
		// v.pb('D');
		// vis[i+1][j]=1;
		if(dfs(i+1,j)){
		v.pb('D');fr=1;}

	}
	return fr;
}
/*
                    ** author **
                ** Parth Lathiya **
    ** https://www.cse.iitb.ac.in/~parthiitb/ **
*/

int main()
{

ios::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
	freopen("D_in.txt","r",stdin);
#endif

//  --------------------------------------------------------------------------------------
cin>>n>>m;

rep(i,1,n+1)
	rep(j,1,m+1)
		cin>>a[i][j];
// std::vector<char> v;
dfs(1,1);

map<char, char> h;
h['L']='L';
h['R']='R';
h['U']='U';
h['D']='D';
// rep(i,0,v.size())
// cout<<v[i];
reverse(v.begin(), v.end());
ll lr=-1, ud=-1;
ll l,r;

if(n>1 && m>1 && a[1][2]=='.' && a[2][1]=='.')
{
	cout<<'R'<<endl;
	fflush(stdout);
	cin>>l>>r;
	if(r==2){
		lr=0;
		cout<<'L'<<endl;
		fflush(stdout);
		cin>>l>>r;	
	}
	else{
		lr=1;
		h['L']='R';
		h['R']='L';
	}
	
	cout<<'D'<<endl;
	fflush(stdout);
	cin>>l>>r;
	if(l==2){
		ud=0;
		cout<<'U'<<endl;
		fflush(stdout);
		cin>>l>>r;	
	}
	else{
		ud=1;
		h['U']='D';
		h['D']='U';
	}

//	l r should be 1,1
//act acordingly lr ud and go from 1,1

//v[0] to end
	ll i=0;
	while(i<v.size())
	{
		cout<<h[v[i]]<<endl;
		fflush(stdout);
		cin>>l>>r;	
		i++;	
	}

}
else if(m>1 && a[1][2]=='.')
{
	cout<<'R'<<endl;
	fflush(stdout);
	cin>>l>>r;
	if(r==2){
		lr=0;
		cout<<'L'<<endl;
	fflush(stdout);
	cin>>l>>r;
	}
	else
		{
		lr=1;
		h['L']='R';
		h['R']='L';

}

//v[0] to end;
 ll i=0;
while(i<v.size() && (v[i]!='D')){
	if(lr==0)
		cout<<'R'<<endl;
	else
		cout<<'L'<<endl;
	fflush(stdout);
	cin>>l>>r;
	i++;
}
	cout<<'D'<<endl;
	fflush(stdout);
	ll bk=l;
	cin>>l>>r;
	if(l==bk+1){
		ud=0;
		cout<<'U'<<endl;
	fflush(stdout);
	cin>>l>>r;
	}
	else{
		
		ud=1;
		h['U']='D';
		h['D']='U';
	
	
	}

	//v[i+1] to end

	while(i<v.size())
	{
		cout<<h[v[i]]<<endl;
		fflush(stdout);
		cin>>l>>r;i++;
	}
}

else if(n>1 && a[2][1]=='.')
{
	cout<<'D'<<endl;
	fflush(stdout);
	cin>>l>>r;
	if(l==2){
		ud=0;
	cout<<'U'<<endl;
	fflush(stdout);
	cin>>l>>r;
	}
	else
		{
		ud=1;
		h['U']='D';
		h['D']='U';
		
	}

//v[0] to end
 ll i=0;
while(i<v.size() && (v[i]!='R')){
	if(ud==0)
		cout<<'D'<<endl;
	else
		cout<<'U'<<endl;	
	fflush(stdout);
	cin>>l>>r;
	i++;
}
	cout<<'R'<<endl;
	fflush(stdout);
	ll bk=r;
	cin>>l>>r;
	if(r==bk+1){
		lr=0;
		cout<<'L'<<endl;
	fflush(stdout);
	cin>>l>>r;
	}
	else{
		
		lr=1;
		h['L']='R';
		h['R']='L';
	

	}

	//v[i+1] to end

	while(i<v.size())
	{
		cout<<h[v[i]]<<endl;
		fflush(stdout);
		cin>>l>>r;i++;
	}
}
else
{
	if(m>1 && a[1][2]=='F')
	{
		cout<<'R'<<endl;
		fflush(stdout);
		cin>>l>>r;
		if(r!=2){
			cout<<'L'<<endl;
			fflush(stdout);
			cin>>l>>r;
		}
	}
	else if(n>1 && a[2][1]=='F')
	{
		cout<<'D'<<endl;
		fflush(stdout);
		cin>>l>>r;
		if(l!=2){
			cout<<'U'<<endl;
			fflush(stdout);
			cin>>l>>r;
		}
	}

}



//  --------------------------------------------------------------------------------------

return 0;
}
