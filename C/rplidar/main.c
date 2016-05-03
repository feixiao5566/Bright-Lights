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
    int n = 0;
    
    fd = InitUart();
    printf("Init!\n");
    RplidarInfo(fd);
    //gethealth的时候挺容易失败的?
    GetHealth(fd);//√
    //TODO 检测数据接受状态,判断保护性停机

    RplidarScan(fd);
    printf("start scan\n");
    n = 0;
    while(1)
    {
//        ReadUart(fd, 5);
        i = ReadUart(fd);
        n++;
        printf("read U %d, n = %d\n", i, n);
        if(n >= 50)
        {
            n = 0;
            //RplidarReset(fd);
            //StopScan(fd);
            //force_scan();
/*            usleep(1000);
            GetHealth(fd);
            printf("Jevens!\n");
            RplidarScan(fd);*/
        }
    }
    StopScan(fd);
    CloseUart(fd);
}
