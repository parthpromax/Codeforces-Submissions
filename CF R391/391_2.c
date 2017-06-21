#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%-1c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define forall(i,a,b)               for(i=a;i<b;i++)
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define ll long long int
#define llu long long unsigned
#define ld long
#define mod 1000000007
#define P(x) printf("%d\n",x)



int main()
{
int n;
s(n);
int pf[100001]={0};
int maxpf=0;
int i,j;
forall(i,0,n)
{
	int temp;
	sl(temp);
	forall(j,2,ceil(sqrt(temp))+1)
	{
		if(temp%j==0)
		{
			pf[j]++;
			do
			{
				temp/=j;
			}
			while(temp>=j && temp%j==0);

			maxpf=maX(j,maxpf);
		}
	}
	if(temp!=1)
	{
		pf[temp]++;
		maxpf=maX(temp,maxpf);
	}
}
int ans=pf[0];
forall(i,1,maxpf+1)
{
	ans=maX(pf[i],ans);
}
if(ans==0)ans=1;
printf("%d",ans);
return 0;
}
