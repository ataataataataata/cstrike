#ifndef CSTRIKE_STATS_H
#define CSTRIKE_STATS_H

#include <float.h>
#include "color.h"

typedef struct {
    int total;
    double total_latency;
    int success;
    int failed;
    double min_latency;
    double max_latency;
} Stats;

void initStats(Stats *stats);
void addResult(Stats *stats, double latency,int statusCode);
void printResult(Stats *stats);



#endif //CSTRIKE_STATS_H
