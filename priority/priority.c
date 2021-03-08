#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>

/**
 * このコードを実行するプロセスのnice値を調べるコード
 */
int main() {
    int ret;
    ret = getpriority(PRIO_PROCESS, 0);
    printf("nice valie is %d", ret);
}
