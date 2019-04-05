#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	int n,k;
	again:
		printf("enter your input:\n");
		scanf("%d",&k);
		if(k<0)
		{
			printf("*** Invalid Input ***\n");
			goto again;
		}
		n=fork(); //new process
		if(n==0)
		{
			while(k>0)
			{
				printf("%d ",k);
				k=k/2;
			}
		}
		else
		{
			wait(NULL);
			printf("\nparent process is waiting:");
		}
}
