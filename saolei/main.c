/* #include <stdio.h>
#include <stdlib.h>
#include <stddef.h> */
#include "all.h"

int main()
{
    int in;
    do
    {
        start();
        scanf("%d", &in);
        switch (in)
        
        {
        case 2:
            break;
        case 1:
            game();
            system("pause");
            break;
        default:
            printf("输入错误，请重新输入");
            break;
        }

    } while (!2);
}