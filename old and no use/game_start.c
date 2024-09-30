#include "all.h"

#define ratio 0 //雷的比例
int line, column;
char **list;
char **list_hide;
int **unlock_list;

int digit_number(int);

void game_start() //给出list二维数组
{
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

    game_output();

    game_middle(line + 2, column + 2, list);
}

void game_output() 打印list
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

void game_middle(int line, int column, char **list) //给出list_hide二维数组
{

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

    int landmine_number; //生成雷的数量
    landmine_number = ratio * (line * column);
    int landmine_xy[2][landmine_number];
    srand((unsigned)time(NULL));

    for (int i = 0; i < landmine_number; i++) // x，横为x
    {
        landmine_xy[0][i] = rand() % (column - 2);
    }

    for (int i = 0; i < landmine_number; i++) // y 竖为y
    {
        landmine_xy[1][i] = rand() % (line - 2);
    }
    int landmine_y, landmine_x;
    for (int i = 0; i < landmine_number; i++)
    {

        landmine_y = landmine_xy[1][i] + 1;
        landmine_x = landmine_xy[0][i] + 1;
        list_hide[landmine_y][landmine_x] = '1';
    }

    unlock_list = Unlock_list();
    game_end(line - 2, column - 2, list, list_hide, unlock_list);
}

char **Unlock_list(void) //记得修改使用Unlock_list的返回值的形参列表
{
    unlock_list = (char **)malloc(line * sizeof(char *));
    if (list == NULL)
    {
        perror("list二维数组获取失败");
    }
    for (int i = 0; i < line; i++)
    {
        [i] = (char *)malloc(column * sizeof(char));
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
}
{
    unlock_list = (char **)malloc(line * sizeof(char *));
    if (list == NULL)
    {
        perror("list二维数组获取失败");
    }
    for (int i = 0; i < line; i++)
    {
        [i] = (char *)malloc(column * sizeof(char));
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
}