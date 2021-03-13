#include<stdio.h>
#include<sched.h>

int main() {
    int min, max;

    min = sched_get_priority_min(SCHED_RR);
    if (min == -1) {
        perror("sched_get_priority_min");
    }

    max = sched_get_priority_max(SCHED_RR);
    if (max == -1) {
        perror("sched_get_priority_min");
    }

    printf("SCHED_PR priority range is %d - %d", min, max);
    return 1;
}
