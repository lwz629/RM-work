#include<stdio.h>
int main()
{
    int x,y,s;
    scanf("%d %d", &x, &y);
    if(y==0)
    {
        printf("error\n");
        return 1;
    }
    s = x / y;
    printf("%d\n", s);
    return 0;
}
