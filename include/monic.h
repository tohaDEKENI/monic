#ifndef __MONIC__
#define __MONIC__

#include <stdio.h>

void print_bar(float percentage) ;

//FILE *f_cpu;
float get_cpu_usage();
float get_ram_usage();

typedef struct LoadAverage {
    float one_min;     // charge moyenne sur 1 minute
    float five_min;    // charge moyenne sur 5 minutes
    float fifteen_min; // charge moyenne sur 15 minutes
} LoadAverage;

LoadAverage get_average();
void print_avg();

typedef struct Uptime{
    int hours,min,sec;
}Uptime;
Uptime get_uptime();
void print_uptime();

#endif