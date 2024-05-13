#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

void start(void);
void game(void);
void game_start(void);
void game_middle(int,int,char **);
void game_end(int,int,char**,char**);
void game_output(int,int,char **);

int landmine_around_number(int,int,char **);
void recursive_LANumber(int,int,char **,char**);