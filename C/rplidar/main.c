#include"rplidar.h"



void main()
{
    int fd = 0;
    int i = 0;
    printf("hello\n");
    fd = InitUart();
    printf("hi\n");
//    WriteUart(fd, CMD_HEALTH);
    write(fd, CMD_HEALTH, 2);
//    while(1)
    {
        ReadUart(fd);
    }
    
    write(fd, CMD_INFO, 2);
    printf("device info\n");
    ReadUart(fd);
    write(fd, CMD_SCAN, 2);
    printf("start scan\n");
    ReadUart(fd);
    for(i = 0; i<10000; i++)
    {
        ;
    }
    write(fd, CMD_STOP, 2);
    printf("stop scan\n");
    ReadUart(fd);
    CloseUart(fd);
}
