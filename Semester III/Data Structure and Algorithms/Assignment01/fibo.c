#include<stdio.h>


int fibInt(int n){
		int i,p,n1=1,n2=1;
		for (i=3;i<=n;i++){
			p = n1 + n2;
			n2 = n1;
			n1= p;
		
		}
		return p;
		
	
}

long fibLong(long n){
		int i;
		long p,n1=1,n2=1;
		for (i=3;i<=n;i++){
			p = n1 + n2;
			n2 = n1;
			n1= p;
		}
		return p;
	
}

// Fn = Fn-1 + Fn-2;
int main()
{
	int p=0,n,j;
	long longInt =0;
	scanf("%d",&n);
	
	if (n == 1 || n== 2)
	{
		printf("1\n");
	}
	else if(n==3){
		printf("2\t2");
	}
	else{
		for(j=3;j<n;j++)
		{
			longInt = fibLong(j);
			p = fibInt(j);
			printf("%d\t\t",p);
			printf("%lld\n",longInt);
		}
	}
	
	
	return 0;
}
