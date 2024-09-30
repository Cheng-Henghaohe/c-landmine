#include "all.h"
#include "BFS.h"

void game_end(int line, int column, char **list, char **list_hide,char **Unlock_list)
{
    while (1)
    {
        printf("请输入你所要探的雷的坐标\n先横坐标，后竖坐标\n即先多少列，后多少排\n");
        int x, y, landmine_around_num;
        scanf("%d%d", &x, &y);
        if (list_hide[y][x] == '1')
        {
            printf("你踩到雷了\n");
            list[y - 1][x - 1] = '!';
            game_output();
            free(list);
            free(list_hide);
            system("pause");
            return;
        }
        
        
        landmine_around_num=landmine_around_number(x, y, line, column, list_hide);
        list[y - 1][x - 1] = (char)(landmine_around_num + '0');
        Queue_LAnumber(x, y, line, column, list_hide, list,Unlock_list);
        game_output();

        //胜利的判断条件
        int total_landmines = 0;
        int total_uncovered = 0;

        // Count the total number of landmines and uncovered cells
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (list_hide[i][j] == '1')
                {
                    total_landmines++;
                }
                if (list[i][j] != '*')
                {
                    total_uncovered++;
                }
            }
        }

        // Check if all non-landmine cells are uncovered
        if (total_uncovered == (line * column) - total_landmines)
        {
            printf("Congratulations! You have won the game!\n");
            free(list);
            free(list_hide);
            system("pause");
            return;
            // Perform any additional actions for winning the game
        }
    }
}

int landmine_around_number(int x, int y, int line, int column, char **list_hide) //计算并返回给定(x,y)四周的雷的数量
{
    int landmine_around_num = 0;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (x + j < 0 || y + i < 0 || x + j >= column || y + i >= line)
            {
                continue;
            }
            landmine_around_num += (int)(list_hide[y + i][x + j] - '0');
        }
    }
    return landmine_around_num;
}

void Queue_LAnumber(int x, int y, int line, int column, char **list_hide, char **list,char **Unlock_list)
{
    int xy[2];
    Queue Q;
    Queue *q=&Q;
    initQueue(q);
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (x + j < 0 || y + i < 0 || x + j >= column || y + i >= line)//||Unlock_list[y+i][x+j]!=o)
            {
                continue;
            }
            xy[0]=y+i;
            xy[1]=x+j;
            enQueue(q,xy);
        }
    }
}




















/* void recursive_LANumber(int x, int y, int line, int column, char **list_hide, char **list) //递归计算周围没有雷的地方，并自动点亮
{

    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (x + j < 1 || y + i < 1 || x + j >= column + 1 || y + i >= line + 1)
            {
                continue;
            }
            int landmine_around_num = 0;
            landmine_around_num = landmine_around_number(x + i, y + j, line, column, list_hide);
            if (landmine_around_num == 0)
            {
                list[y + i - 1][x + j - 1] = '0';
                recursive_LANumber(x + i, y + j, line, column, list_hide, list);
            }
            else
            {
                return;
            }
        }
    }
} */