#include"rplidar.h"

void main()
{
    int fd = 0;
    printf("hello\n");
    fd = InitUart();
    printf("hi\n");
    while(1)
    {
        ReadUart(fd);
    }
    CloseUart(fd);
}
