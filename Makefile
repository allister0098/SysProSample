CC := gcc
CFLAGS := -Wall -Wextra -O2 -g

poll: poll/poll_example
kqueue_kevent: poll/kqueue_kevent
writev: scatter-gather-io/writev
readv: scatter-gather-io/readv
mmap: mmap/mmap
fstat: stat/fstat
stat: stat/stat
ioctl: ioctl/ioctl
atexit: exit/atexit
wait: wait/wait
system: wait/system
daemon: daemon/daemon
priority: priority/priority
affinity: affinity/affinity
check_affinity: affinity/check_affinity
