#include "all.h"

void game_middle(int line, int column)
{
    char **list_hide;
    list_hide = (char **)malloc(line * sizeof(char *));
    if (list_hide == NULL)
    {
        perror("list_hide二维数组获取失败");
    }
    for (int i = 0; i < line; i++)
    {
        list_hide[i] = (char *)malloc(column * sizeof(char));
        if (list_hide[i] == NULL)
        {
            perror("list_hide[i]一维数组获取失败");
            i--;
        }
    }

    //用1表示有雷，0表示没有雷
    for (int i = 0; i < line; i++) //生成基础的0，即无雷的地图
    {
        for (int j = 0; j < column; j++)
        {
            list_hide[i][j] = '0';
        }
    }

    int landmine_number;//生成雷的坐标
    landmine_number = 0.3 * (line * column);
    int landmine_xy[2][landmine_number];
    srand((unsigned)time(NULL));

    for (int i = 0; i < landmine_number; i++)//x，横为x
    {
        landmine_xy[0][i] = rand() % (column - 2);
    }

    for (int i = 0; i < landmine_number; i++)//y 竖为y
    {
        landmine_xy[1][i] = rand() % (line - 2);
    }
    int landmine_y,landmine_x;
    for(int i=0;i<landmine_number;i++)
    {
        
        landmine_y=landmine_xy[1][i]+1;
        landmine_x=landmine_xy[0][i]+1;
        list_hide[landmine_y][landmine_x]='1';
    }




    //debug
    for(int i=0;i<line;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("%c",list_hide[i][j]);
        }
    }
    free(list_hide);
    
    







}    