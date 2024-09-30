#ifndef LANDMINE_INTF_H
#define LANDMINE_INTF_H

typedef struct
{
    char show;
    int is_landmine;
    int landmine_around_num;
    int lock;
} landmine_info;

#endif