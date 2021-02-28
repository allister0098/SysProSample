#include <sys/event.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>   /* for strerror() */
#include <unistd.h>

void diep(const char *s);

int main(void)
{
    struct kevent change;
    struct kevent event;
    pid_t pid;
    int kq, nev;


    // 複数のファイルディスクリプタを監視するためのファイルディスクリプタみたいな者
    // kqueue/keventを使うときはこの初期化から始まる
    kq = kqueue();
    /* create a new kernel event queue */
    if (kq == -1) {
        diep("kqueue()");
    }

    // kevent構造体の初期化
    // 5秒ごとにchangeを初期化する
    EV_SET(&change, 1, EVFILT_TIMER, EV_ADD | EV_ENABLE, 0, 5000, 0);

    while(1) {
        nev = kevent(kq, &change, 1, &event, 1, NULL);

        if (nev < 0)
            diep("kevent()");

        else if (nev > 0) {
            if (event.flags & EV_ERROR) {
                fprintf(stderr, "EV_ERROR: %s\n", strerror(event.data));
                exit(EXIT_FAILURE);
            }

            if ((pid = fork()) < 0)
                diep("fork()");

            else if (pid == 0)
                if (execlp("date", "date", (char*)0) < 0)
                    diep("execlp()");
        }
    }

    close(kq);
    return EXIT_SUCCESS;
}

void diep(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}
