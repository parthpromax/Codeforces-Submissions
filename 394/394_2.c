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
int x,y;
s(x);
s(y);
int temp=x-y;
if(temp==0 || temp==-1 || temp==1)
	printf("YES");
else
	printf("NO");
return 0;
}
