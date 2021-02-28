CC := gcc
CFLAGS := -Wall -Wextra -O2 -g

poll: poll/poll_example
kqueue_kevent: poll/kqueue_kevent
writev: scatter-gather-io/writev
readv: scatter-gather-io/readv
