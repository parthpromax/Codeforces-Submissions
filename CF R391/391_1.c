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

char in[100001];
ss(in);
int cb=0,u=0,l=0,b=0,a=0,s=0,r=0;
int i;
forall(i,0,strlen(in))
{
	if(in[i]=='B')
		cb++;
	else if(in[i]=='u')
		u++;
	else if(in[i]=='l')
		l++;
	else if(in[i]=='b')
		b++;
	else if(in[i]=='a')
		a++;
	else if(in[i]=='s')
		s++;
	else if(in[i]=='r')
		r++;
}

printf("%d",miN(miN(miN(miN(miN(miN(cb,u/2),l),b),a/2),s),r));
return 0;
}
