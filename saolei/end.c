#include "landmine_info.h"
#include <stdio.h>
#include <stdlib.h>
#define BFS_H
#include "BFS.h"

extern int line, column;
extern landmine_info **list;
extern double difficulty;

int landmine_around_number(int l, int c);
void game_output();

void Queue_LAnumber(int l, int c)
{
    int move[2][4] = {{-1, 0, 1, 0}, {0, -1, 0, 1}};
    Queue q;
    initQueue(&q);
    enQueue(&q, (int[]){l, c});
    while (!isEmpty(&q))
    {
        int *lc;
        lc = deQueue(&q);

        for (int i = 0; i < 4; i++)
        {
            //printf("%d %d\n", lc[0], lc[1]);//test
            if (lc[0] + move[0][i] < 0 || lc[0] + move[0][i] >= line || lc[1] + move[1][i] < 0 || lc[1] + move[1][i] >= column || list[lc[0] + move[0][i]][lc[1] + move[1][i]].lock == 1)
            {
                continue;
            }

            list[lc[0] + move[0][i]][lc[1] + move[1][i]].lock = 1;
            list[lc[0] + move[0][i]][lc[1] + move[1][i]].landmine_around_num = landmine_around_number(lc[0] + move[0][i], lc[1] + move[1][i]);
            if (list[lc[0] + move[0][i]][lc[1] + move[1][i]].landmine_around_num == 0)
            {
                list[lc[0] + move[0][i]][lc[1] + move[1][i]].show = '0';
            }
            else
            {
                list[lc[0] + move[0][i]][lc[1] + move[1][i]].show = (char)('0' + list[lc[0] + move[0][i]][lc[1] + move[1][i]].landmine_around_num);
                continue;//这里跳过循环，故不会执行接下来的enQueue函数
            }
            enQueue(&q, (int[]){lc[0] + move[0][i], lc[1] + move[1][i]});
        }
        free(lc);
    }
}

int landmine_around_number(int l, int c)
{
    int move[2][8] = {{-1, -1, 0, 1, 1, 1, 0, -1}, {0, -1, -1, -1, 0, 1, 1, 1}};
    int num = 0;
    for (int i = 0; i < 9; i++)
    {
        if (l + move[0][i] < 0 || l + move[0][i] >= line || c + move[1][i] < 0 || c + move[1][i] >= column)
        {
            continue;
        }
        num += list[l + move[0][i]][c + move[1][i]].is_landmine;
    }
    return num;
}

void game_end()
{
    while (1)
    {
        printf("请输入你所要探的雷的坐标\n先第几行，后第几列\n");
        int l, c;
        scanf("%d%d", &l, &c);
        l--;
        c--;
        if (list[l][c].is_landmine == 1)
        {
            printf("你踩到雷了\n");
            list[l][c].show = '!';
            game_output();
            free(list);
            system("pause");
            return;
        }

        list[l][c].landmine_around_num = landmine_around_number(l, c);
        list[l][c].show = (char)(list[l][c].landmine_around_num + '0');

        Queue_LAnumber(l, c);
        game_output();

        // 胜利的判断条件
        int total_landmines = difficulty * line * column;
        int total_uncovered = 0;

        // Count the total number of landmines and uncovered cells
        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (list[i][j].show == '*')
                {
                    total_uncovered++;
                }
            }
        }

        // Check if all non-landmine cells are uncovered
        if (total_uncovered == total_landmines)
        {
            printf("Congratulations! You have won the game!\n");
            free(list);
            system("pause");
            return;
            // Perform any additional actions for winning the game
        }
    }
}
