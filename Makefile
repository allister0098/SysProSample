CC := gcc
CFLAGS := -Wall -Wextra -O2 -g

poll: poll/poll_example
writev: scatter-gather-io/writev

# gcc -Wall -Wextra -O2 -o -g poll_example poll_example.c
