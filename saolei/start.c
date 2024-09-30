#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "landmine_info.h"

int line, column;
double difficulty = 0.0;

landmine_info **list;

void game_end();

void game_start() //给出每个landmine的信息 z只有一个list表格
{
    printf("请输入想要游玩的行数与列数\n");
    scanf("%d%d", &line, &column);

    list = (landmine_info **)malloc(line * sizeof(landmine_info *));
    if (list == NULL)
    {
        perror("list二维数组获取失败");
    }
    for (int i = 0; i < line; i++)
    {
        list[i] = (landmine_info *)malloc(column * sizeof(landmine_info));
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
            list[i][j].show = '*';
            list[i][j].is_landmine = 0;
            list[i][j].landmine_around_num = 0;
            list[i][j].lock = 0;
        }
    }

    { //产生雷
        int landmine_number = difficulty * line * column;
        int landmine_lanecolumn[2][landmine_number];
        memset(landmine_lanecolumn, 0, sizeof(landmine_lanecolumn));

        srand((unsigned)time(NULL));

        for (int i = 0; i < landmine_number; i++) // line
        {
            landmine_lanecolumn[0][i] = rand() % (line);
        }
        for (int i = 0; i < landmine_number; i++) // column
        {
            landmine_lanecolumn[1][i] = rand() % (column);
        }
        int landmine_line, landmine_column;
        for (int i = 0; i < landmine_number; i++)
        {
            landmine_line = landmine_lanecolumn[0][i];
            landmine_column = landmine_lanecolumn[1][i];
            while (1)
            {
                if (list[landmine_line][landmine_column].is_landmine == 1)
                {
                    landmine_line = rand() % line;
                    landmine_column = rand() % column;
                }
                else
                {
                    list[landmine_line][landmine_column].is_landmine = 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < line; i++) // landmine_around_num
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d", list[i][j].is_landmine);
        }
        printf("\n");
    }
}

int digit_number(int number) //获得数位
{
    int digit = 0;
    while (number > 0)
    {

        number /= 10;
        digit++;
    }
    return digit;
}

void game_output() //打印list
{
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

    printf("\n\n"); //真正的*行输出

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

            printf("%c", list[i][j].show);
        }

        printf("\n\n");
    }
}