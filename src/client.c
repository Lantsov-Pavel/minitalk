#include "../includes/minitalk.h"

void send_bit(int pid, int bit)
{
    if(bit == 0)
    {
        kill(pid, SIGUSR1);
        unsleep(100);
    }
    else
    {
        kill(pid, SIGUSR2);
        unsleep(100);
    }
}

void send_char(int pid, char c)
{
    int i;
    int bit;

    i = 7;
    while (i >= 0)
    {
        bit = (c >> i) & 1;
        send_bit(pid, bit);
        i--;
    }
    
}

void seng_msg(int pid, char *msg)
{
    int i;

    i = 0;
    while (!str)
    {
        send_char(str[i]);
        i++;
    }
    send_char(pid, '\0');
}

int main(int argc, char **argv)
{
    int pid;

    pid = ft_atoi(argv[1]);
    send_msg(pid, argv[2]);
}