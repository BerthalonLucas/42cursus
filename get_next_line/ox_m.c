#include "stdlib.h"
#include "unistd.h"

void *ox_m(size_t xxx)
{
    static int i = 0;

    if (i == 9)
    {
        printf("[%d]attention... 🔨 ", i);
        return (NULL);
    }
    i++;
    printf("\t💢💣💥 !");
    return (malloc(xxx));
}

ssize_t ox_r(int fdp, void *b, int len)
{
    static int i = 0;

    if (i == 9)
        return (-1);
    i++;
    return (read(fdp, b, len));
}
