#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

void start(void);
void game(void);
void game_start(void);
void game_middle(int,int,char**);
   void game_end(int,int,char**,char**,char**);
void game_output(void);

int landmine_around_number(int,int,int,int,char**);
//void recursive_LANumber(int,int,int,int,char **,char**);
void Queue_LAnumber(int,int,int,int,char **,char**,char**);
char** LAnumber_list(void);//