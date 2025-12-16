#include <monic.h>
#include <stdio.h>
#include <stdlib.h>

LoadAverage get_average(){
	FILE *f_avg = fopen("/proc/loadavg","r");
	if(!f_avg){
		perror("fopen");
    }

    LoadAverage lavg;

    fscanf(f_avg,"%f %f %f",&lavg.one_min,&lavg.five_min,&lavg.fifteen_min);

    return lavg;
}
