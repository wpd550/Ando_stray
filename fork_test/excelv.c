#include <unistd.h>

int main()
{
    char *arg[]={"ls","-la",NULL};
    execv("/bin/ls",arg);
}
