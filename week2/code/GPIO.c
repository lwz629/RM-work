#include<stdio.h>
typedef enum {GPIO_Speed_2MHz,GPIO_Speed_10MHz,GPIO_Speed_50MHz}GPIO_Speed_enum;
typedef struct{GPIO_Speed_enum GPIO_Speed;}GPIO_Speed_structment;
void GPIO_StructureInit(GPIO_Speed_structment*GPIO_InitStruct);
int main()
{
    GPIO_Speed_structment GPIO_InitStructure;
    GPIO_StructureInit(&GPIO_InitStructure);\
    return 0;
}
void GPIO_StructureInit(GPIO_Speed_structment*GPIO_InitStruct)
{
    if(GPIO_InitStruct != NULL)
    {
        GPIO_InitStruct->GPIO_Speed = GPIO_Speed_2MHz;
    }
}
