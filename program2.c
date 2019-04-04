#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
int fd[2],n,pid,fd1,fd2;
char buff[50],buffer[50];

pipe(fd);//intialization of pipe
pid=fork();

if(pid>0)
{
 close(fd[0]);  // closing first end of file
 fd1=open("file",O_RDWR,0777); // opening existing file

n=read(fd1,buffer,50);  // reading from the file

 write(fd[1],buffer,n);    // writing at other end of pipe

}
else
{
//sleep(1);
 close(fd[1]);   // closed second end of pipe

  n=read(fd[0],buff,100);  // reading data from the buff
 write(1,buff,n);   // printtin on screen

 fd2=open("copy",O_RDWR|O_CREAT,0777);  // opening new file named copy
 write(fd2,buff,n);   // writing its content in file

}

return 0;
}
