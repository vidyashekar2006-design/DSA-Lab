#include <stdio.h>
#include <stdlib.h>
void toh(int n,char s,char d ,char t)
{

    if(n==1)
    {

        printf("\n move % d disc from %c to %c",n,s,d);

    }
    else{
        toh(n-1,s,t,d);
        printf("\move %d disc from %c to %c",n,s,t);
        toh(n-1,t,d,s);
    }
}
int main()
{

    int n;
    printf("\n enter number ");
    scanf("%d",&n);
    printf("\n sequence of moves:\n");
    toh(n,'S','T','D');
    int totalmoves=(1<<n)-1;
    printf("\n total moves=%d\n",totalmoves);
    return 0;
}
