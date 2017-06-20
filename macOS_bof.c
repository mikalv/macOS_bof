#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void secret()
{
    printf("You have entered the secret function!!\n");
}

void echo(const char* arg)
{
    char buffer[512];
    // The below strcpy is vulnerable to a buffer overflow
    strcpy(buffer, arg);
}

// execute the challenge using `$./macOS_bof <test_argument>`
int main(int argc, char **argv)
{
    echo(argv[1]);
}
