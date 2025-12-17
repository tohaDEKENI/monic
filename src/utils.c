#include <monic.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>


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

void print_uptime(Uptime upt) {
    printf("Uptime : ");

    if (upt.hours > 0)
        printf("%dh ", upt.hours);

    if (upt.min > 0 || upt.hours > 0)
        printf("%dmin ", upt.min);

    printf("%dsec\n", upt.sec);
}

void get_host(){
    char hostname[1024];  

    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Hostname : %s\n", hostname);
    } else {
        perror("gethostname");
    }
}

void get_user(){
    uid_t uid = getuid();                 // ID de l'utilisateur
    struct passwd *pw = getpwuid(uid);    // Infos utilisateur

    if (pw) {
        printf("User : %s\n", pw->pw_name);
    } else {
        printf("Impossible de récupérer l'utilisateur\n");
    }

}