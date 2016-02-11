#include <stdio.h>

char op[]={'+','-','*','/'};
bool eval(int a[],int target,int n,int pos,int prev)
{
	if(pos == n) {
		if(prev == target)	{
            return true;
		}
		return false;
	}
	for(int i=0;i<;4;i++) {
		int res = 0;
		char ch = op[i];
		if(ch == '+') {
			res = prev + a[pos];
		} else if(ch == '-') {
			res = prev - a[pos];
		} else if(ch == '*') {
			res = prev * a[pos];
		} else {
			res = prev / a[pos];
		}
		if(	eval(a,target,n,pos+1,res ) )
			return true;
	}
	return false;
}
