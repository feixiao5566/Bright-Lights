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
    //gethealth的时候挺容易失败的?
    GetHealth(fd);//√
    //TODO 检测数据接受状态,判断保护性停机

    RplidarScan(fd);
    printf("start scan\n");
    while(1)
    {
//        ReadUart(fd, 5);
        ReadUart(fd);
    }
    StopScan(fd);
    CloseUart(fd);
}
