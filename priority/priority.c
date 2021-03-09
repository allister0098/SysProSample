#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>

/**
 * このコードを実行するプロセスのnice値を調べるコード
 */
int main() {
    int ret;
    ret = setpriority(PRIO_PGRP, 0, 10);
    ret = getpriority(PRIO_PROCESS, 0);
    printf("nice valie is %d", ret);
}
