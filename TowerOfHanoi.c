#include<stdio.h>

void tower(int n,char src,char tmp,char dst)
{
    if(n==1)
    {
        printf(" Move disk %d from %c to %c\n",n,src,dst);
        return;
    }
    tower(n-1,src,dst,tmp);
    printf("move disk %d from %c to %c\n",n,src,dst);
    tower(n-1,tmp,src,dst);
    return;
}

int main()
{
    tower(3,'a','b','c');

    //printf ("hello world\n");
    return 0;
}