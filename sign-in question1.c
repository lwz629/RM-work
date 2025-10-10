#include<stdio.h>
int main()
{
    int x,y,s;
    printf("请输入两个整数（用空格分隔）:");
    scanf("%d %d", &x, &y);
    s = x / y;
    printf("商是: %d", s);
    return 0;
}