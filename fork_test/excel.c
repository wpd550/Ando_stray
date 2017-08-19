#include <unistd.h>

int main()
{
    fork();
    execlp("ls","ls","-l",NULL);
}
