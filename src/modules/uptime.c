#include <monic.h>
#include <stdio.h>


Uptime get_uptime() {
    FILE *f_upt = fopen("/proc/uptime", "r");
    Uptime up = {0, 0, 0};

    if (!f_upt) {
        perror("fopen");
        return up;
    }

    double time;
    fscanf(f_upt, "%lf", &time);
    fclose(f_upt);

    int total_seconds = (int)time;

    up.hours = total_seconds / 3600;
    up.min   = (total_seconds % 3600) / 60;
    up.sec   = total_seconds % 60;

    return up;
}
