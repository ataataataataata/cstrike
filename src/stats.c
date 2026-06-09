#include "stats.h"

#include <stdio.h>

void initStats(Stats *stats) {
    stats->total = 0;
    stats->total_latency=0;
    stats->success=0;
    stats->failed=0;
    stats->min_latency=DBL_MAX;
    stats->max_latency=0;
}

void addResult(Stats *stats, double latency,int statusCode) {

    if (statusCode<300 && statusCode>199) {
        stats->total_latency += latency;
        stats->success += 1;
        if (stats->min_latency>latency) stats->min_latency=latency;
        if (stats->max_latency<latency) stats->max_latency=latency;
    }
    else {
        stats->failed += 1;
    }
    stats->total += 1;

}

void printResult(Stats *stats) {
    printf(BOLD"━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"RESET);
    printf(BOLD"  Total:    %d\n"RESET, stats->total);
    printf(GREEN"  Success:  %d\n"RESET, stats->success);
    printf(RED"  Failed:   %d\n"RESET, stats->failed);
    printf(BOLD"━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"RESET);
    printf(CYAN"  Min:      %.2f ms\n"RESET, stats->min_latency);
    printf(YELLOW"  Max:      %.2f ms\n"RESET, stats->max_latency);
    printf(BOLD"  Avg:      %.2f ms\n"RESET, stats->total_latency / stats->success);
    printf(BOLD"━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"RESET);
}