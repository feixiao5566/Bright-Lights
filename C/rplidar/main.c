#include"rplidar.h"

/*
const char CMD_HEALTH[2]  = {0xA5,0x52};
const char CMD_INFO[2]  = {0xA5,0x50};
const char CMD_SCAN[2]  = {0xA5,0x20};
const char FORCE_SCAN[2]  = {0xA5,0x21};
const char CMD_STOP[2]  = {0xA5,0x25};
const char CMD_RESET[2]  = {0xA5,0x40};
*/

void main()
{
    int fd = 0;
    int i = 0;
    
    fd = InitUart();
    printf("Init!\n");
    GetHealth(fd);
    //TODO 检测数据接受状态,判断保护性停机
    
    
    
/*    write(fd, CMD_HEALTH, 2);
    ReadUart(fd);
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
    ReadUart(fd);*/
/*    before = GetTime_ms();
    printf("before: %ld\n", before);*/
            //发送scan请求
    RplidarScan(fd);
    printf("start scan\n");
    while(1)
    {
        ReadUart(fd, 5);
    }
    StopScan(fd);
    CloseUart(fd);
}
