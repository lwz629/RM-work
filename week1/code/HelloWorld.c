#include<stdio.h>
int main()
{
    int x;
    while(1)
    {
        printf("请输入-1、0或1:");
        scanf("%d",&x);
    
        if(x==-1)
        {
            printf("程序退出\n");
            break;
        }
        else if(x==0)
        {
            printf("helloworld\n");
        }
        else if(x==1)
        {
            printf("HELLOWORLD\n");
        }
    }
    return 0;
}
