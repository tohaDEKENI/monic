#include <stdio.h>
#include <monic.h>
#include <stdlib.h>
#include <unistd.h>
		
int main()
{
	//char *lang = getenv("LANG");

	while(1){
		system("clear");
		printf("===== MINI SYSTEM MONITOR =====\n");
		get_user();
		get_host();
		printf("CPU usage: ");
		print_bar(get_cpu_usage());
		printf("RAM usage: ");
		print_bar(get_ram_usage());
		print_avg(get_average());
		print_uptime(get_uptime());
		sleep(1);
	}

	return 0;
}

// gcc src/*.c -o prog -I include