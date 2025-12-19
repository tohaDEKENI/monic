#include <monic.h>
#include <stdio.h>
#include <string.h>

RamSwap get_ram_and_swap() {
    FILE *f = fopen("/proc/meminfo", "r");
    RamSwap rs = {0};

    if (!f) {
        perror("fopen");
        return rs;
    }

    long mem_total = 0, mem_avail = 0;
    long swap_total = 0, swap_free = 0;

    char key[64];
    long value;
    char unit[16];

    while (fscanf(f, "%63s %ld %15s\n", key, &value, unit) != EOF) {
        if (strcmp(key, "MemTotal:") == 0)
            mem_total = value;
        else if (strcmp(key, "MemAvailable:") == 0)
            mem_avail = value;
        else if (strcmp(key, "SwapTotal:") == 0)
            swap_total = value;
        else if (strcmp(key, "SwapFree:") == 0)
            swap_free = value;
    }

    fclose(f);

    rs.total_ram = mem_total / 1024.0f / 1024.0f;
    rs.ram_used  = (mem_total - mem_avail) / 1024.0f / 1024.0f;

    rs.swap_total = swap_total / 1024.0f / 1024.0f;
    rs.swap_used  = (swap_total - swap_free) / 1024.0f / 1024.0f;

    return rs;
}
