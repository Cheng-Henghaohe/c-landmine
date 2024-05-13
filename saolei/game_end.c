#include "all.h"

void game_end(int line,int column,char **list,char **list_hide)
{
    printf("请输入你所要探的雷的坐标\n先横坐标，后竖坐标\n即先多少列，后多少排");
    int x,y,landmine_around_num;
    scanf("%d%d",&x,&y);
    landmine_around_number(x,y,list_hide);
    list[y][x]=(char)(landmine_around_num+'0');
    recursive_LANumber(x,y,list_hide,list);
    game_output(line,column,list);
}


int landmine_around_number(int x, int y,char **list_hide) //计算并返回给定(x,y)四周的雷的数量
    {
        int landmine_around_num = 0;
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                landmine_around_num += (int)(list_hide[y + i][x + j]-'0');
            }
        }
        return landmine_around_num;
    }


void recursive_LANumber(int x, int y,char **list_hide,char **list)//递归计算周围没有雷的地方，并自动点亮
    {
        
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {   
                int landmine_around_num=0;
                landmine_around_num=landmine_around_number(x+i,y+j,list_hide);
                if(landmine_around_num==0)
                {
                    list[x+i][y+j]='0';
                    recursive_LANumber(x+i, y+j,list_hide,list);
                }
                else
                {
                    return;
                }
            }
        }
        

    }