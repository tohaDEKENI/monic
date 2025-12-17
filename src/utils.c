#include <monic.h>
#include <stdio.h>

void print_bar(float percentage) {
    int bar_length = (int)(percentage / 100.0 * 40);
    printf("[");
    for (int i = 0; i < bar_length; i++) {
        printf("#");  
    }
    for (int i = bar_length; i < 40; i++) {
        printf(" ");  // Espaces vides
    }
    printf("] %.2f%%\n", percentage);
}

void print_avg(LoadAverage lavg){
    printf("Load Average : %.2f %.2f %.2f\n",lavg.one_min,lavg.five_min,lavg.fifteen_min);
}

void print_uptime(){
    
}