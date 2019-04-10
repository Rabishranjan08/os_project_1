#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	int n,k;
	again:
		printf("enter your input:\n");
		scanf("%d",&k);
		if(k<0)    //checking the condition that input must be greater than zero
		{
			printf("*** Invalid Input ***\n");
			goto again;
		}
		n=fork(); //new process is generated
		if(n==0)   //n=0 then it is the child process of that parent process
		{
			while(k>0)  //this is done to print the no each time divided by two untill the number is greater than 0
			{
				printf("%d ",k);  
				k=k/2;
			}
		}
		else
		{
			wait(NULL); //this is done for waiting of the parent process
			printf("\nparent process is waiting:");
		}
}
