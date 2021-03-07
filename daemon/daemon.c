#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fs.h>

/**
 * プロセスをデーモン化させるサンプル
 */
int main(void) {
    pid_t pid;
    int i;

    pid = fork();
    if (pid == -1)
        return -1;
    else if (pid != 0)
        exit (EXIT_SUCCESS); // 親プロセス終了


    // セッションとプロセスグループを新規作成。この時のセッションIDとプロセスグループIDは子プロセスのIDと一致するはず
    if (setsid() == -1)
        return -1;

    // ルートディレクトリに移動
    if (chdir("/") == -1)
        return -1;

    // 全ファイルクローズ
    for (i = 0; i < NR_OPEN; i++) {
        close(i);
    }

    open("/dev/null", O_RDWR);
    dup(0);
    dup(0);
            
    do_something();

    return 0;
}

void do_something(void) {
}
