#include <stdio.h>
int main()
{
int d1[1999]={0};
int d2[1999]={0};
int nob=0;
int x=0,y=0;
int noa=0;
scanf("%d",&nob);
for(int i=0;i<nob;i++)
{
scanf("%d",&x);
x--;
scanf("%d",&y);
y--;
d1[999+x-y]=d1[999+x-y]+1;
d2[x+y]=d2[x+y]+1;
}
for(int i=0;i<1999;i++)
{
noa=noa+d1[i]*(d1[i]-1)/2;
noa=noa+d2[i]*(d2[i]-1)/2;
}
printf("%d",noa);
return 1;
}