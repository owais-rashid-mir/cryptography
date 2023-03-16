#include<stdio.h>
int main()
{
	
	int i,j,k;
	
	for(i=97;i<123;i++)
	{
		printf("%c",i);
			
		for(j=i+1;j<123;j++)
		{
			printf("%c",j);	
		}
		
		for(k=97;k<i;k++)
		{
			printf("%c",k);
				
		}
		printf("\n");
		
	}
	
	return 0;
	
}
	
	
	
	
	
