#include "all.h"

int digit_number(int);

void game_start()
{
    int line, column;
    char **list;

    printf("请输入想要游玩的行数与列数\n");
    scanf("%d%d", &line, &column);

    list = (char **)malloc(line * sizeof(char *));
    if (list == NULL)
    {
        perror("list二维数组获取失败");
    }
    for (int i = 0; i < line; i++)
    {
        list[i] = (char *)malloc(column * sizeof(char));
        if (list[i] == NULL)
        {
            perror("list[i]一维数组获取失败");
            i--;
        }
    }

    for (int i = 0; i < line; i++) // input
    {
        for (int j = 0; j < column; j++)
        {
            list[i][j] = '*';
        }
    }

    printf("    ");                   // output//写判断语句吗，让其*阵输出对行
    for (int j = 0; j <= column; j++) //第一行 数字行
    {
        int dc;

        dc = 5 - digit_number(j);

        if (dc == 5) //改掉digit_number(0)=0的bug
        {
            dc = 4;
        }

        printf("%d", j);

        while (dc > 0)
        {
            printf(" ");
            dc--;
        }
    }

    printf("\n"); //真正的*行输出

    for (int i = 0; i < line; i++) //*行的起头数字

    {
        int dl;
        dl = 5 - digit_number(i + 1);

        while (dl > 0)
        {
            printf(" ");
            dl--;
        }

        printf("%d", i + 1);

        for (int j = 0; j < column; j++) //*行输出
        {
            int dc;
            dc = 4; //- digit_number(1);

            while (dc > 0)
            {
                printf(" ");
                dc--;
            }

            printf("%c", list[i][j]);
        }

        printf("\n");
    }

    game_middle(line+2,column+2);














    free(list);
}















int digit_number(int number)
{
    int digit = 0;
    while (number > 0)
    {

        number /= 10;
        digit++;
    }
    return digit;
}