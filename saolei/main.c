#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
void game_start();
void game_output();
void game_end();

int main()
{
    int in;
    do
    {
        printf("-- -- -- -- -- -- -- -- -- -- -- -- -- --\n");
        printf("开始游戏请输入\"1\"\n退出游戏请输入\"0\"\n");
        printf("-- -- -- -- -- -- -- -- -- -- -- -- -- --\n");

        scanf("%d", &in);
        switch (in)
        {
        case 2:
            break;
        case 1:
            game_start();
            game_output();
            game_end();
            break;
        default:
            printf("输入错误，请重新输入");
            break;
        }

    } while (in);
}