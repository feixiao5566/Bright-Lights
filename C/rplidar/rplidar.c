#include"rplidar.h"

const char CMD_HEALTH[2]  = {0xA5,0x52};
const char CMD_INFO[2]  = {0xA5,0x50};
const char CMD_SCAN[2]  = {0xA5,0x20};
const char FORCE_SCAN[2]  = {0xA5,0x21};
const char CMD_STOP[2]  = {0xA5,0x25};
const char CMD_RESET[2]  = {0xA5,0x40};

int InitUart()
{
    const char* serial_port[1];
    serial_port[0] = "/dev/rplidar";
    int ret_select = 0;
    int bytes = 0;
    int write_num = 0;
    int read_num = 0;
    int fd = open(serial_port[0], O_RDWR|O_NONBLOCK);
    int status;
    int baudrate = B115200;
    if(-1 == fd)
    {
        perror("can`t open rplidar\n");
//        exit(-1);
    }
    else
    {
        fcntl(fd, F_SETFL, 0);
        //fcntl()针对文件描述符提供控制.参数fd是被参数cmd操作的描述符
        //设置文件描述符状态标识,参数arg为新标识,但只允许O_APPEND
        //O_NONBLOCK和O_ASYNC位的改变,其它位的改变将不受影响
    }
    //Uart set
    struct termios options;
    tcgetattr(fd, &options);
    //用于获取与终端相关的参数
    cfsetispeed(&options, baudrate);
    cfsetospeed(&options, baudrate);
    //Linux系统调用,获取和设置Linux终端属性,线路控制,获取和设置波特率
    options.c_cflag |= (CLOCAL | CREAD);
    //c_cflag 控制模式标识,指定终端硬件控制信息
    //CLOCAL忽略调制解调线路状态
    //CREAD使用接收器
    tcflush(fd, TCIOFLUSH);
    status = tcsetattr(fd, TCSANOW, &options);
    //用于设置终端参数.TCSANOW：不等数据传输完毕就立即改变属性
    
    //设置串口格式为8N1
    options.c_cflag &= ~CSIZE;
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_iflag &= ~(INPCK | ISTRIP);
    tcflush(fd, TCIOFLUSH);
    
    options.c_cflag &= ~CRTSCTS;
    options.c_iflag &= ~(IXON | IXOFF | IXANY);
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_oflag &= ~OPOST;
    options.c_cc[VMIN]  = 1;
    options.c_cc[VTIME] = 15;
    tcflush(fd, TCIOFLUSH);
    status=tcsetattr(fd, TCSANOW, &options);
    if(status != 0)
    {
        perror("tcsetattr etc abnormal");
//        exit(-1);
    }
    printf("Init!\n");
    printf("fd is: %d\n", fd);
    return fd;

}

void WrietUart(int fd, char *cmd, int size)
{
    //int
    int ret = 0;
    ret = write(fd, cmd, size);
    if(ret == -1)
    {
        perror("Write Faile.\n");
    }
    else
    {
        printf("%s cmd has been writen %d bytes.\n", cmd, ret);
    }
}

int ReadUart(int fd)
{
    int ret = 0;
    int n = 0;
    unsigned int *buff = NULL;
    buff = malloc(26);
//    tcflush(fd, TCIOFLUSH);
        //清除终端未完成的输入/输出请求及数据
        //TCIOFLUSH清除所有正在发生的I/O数据
    //TODO 读之前先清空buffer
    buff = memset(buff, 0, 26);
    ret = read(fd, buff, 26);
    if(ret == -1)
    {
        perror("Read Failed.\n");
    }
    else
    {
//        printf("Read: %d bytes read.\n", ret);
    }
//    printf("Read Scan:\n");
    for(n = 0; n<26; n++)
    {
        if(buff[n] != 0)
            printf("0x%x ", buff[n]);
    }
    //输出的数据是低尾端(小端的),实际使用的时候再处理转换吧
    printf("\n");
    free(buff);
    return ret;
}
int GetHealth(int fd)
{
    int health = 0;
    int i = 0;
    unsigned int buff[5] = {0};
    printf("Check health.\n");
    time_t startTs = 0, waitTime = 0;
    startTs = GetTime_ms();
    write(fd, CMD_HEALTH, 2);
    usleep(1000);
//    while((waitTime = GetTime_ms() - startTs) < 5)//000)
    {
        //TODO 读之前先清空buffer
        for(i = 0; i < 5; i++)
                buff[i] = 0;
        printf("before read: buff[0] = %x buff[1] = %x \n", buff[0], buff[1]);
        read(fd, buff, 8);//8代表是8位
        //先判断设备健康的应答代码
        printf("buff[0] = %x buff[1] = %x \n", buff[0], buff[1]);
        while((buff[0] != 0x35aa5)&&((waitTime = GetTime_ms() - startTs) < 5))//||(buff[1]!= 0x60000))
        {
        /*在读取的过程中会遇到
            buff[0] = 35aa5 buff[1] = 0 
            buff[0] = 600 buff[1] = 0
            不知道是什么影响了？*/
            
            printf("before: %ld\n", startTs);
            printf("now: %ld\n", GetTime_ms());
            printf("waitTime: %ld\n", waitTime);
            for(i = 0; i < 5; i++)
                buff[i] = 0;
            write(fd, CMD_HEALTH, 2);
            usleep(1000);
            
            read(fd, buff, 5);
            printf("while:buff[0] = %x buff[1] = %x \n", buff[0], buff[1]);
        }
        
        switch(buff[1] & 0x000f00)//判断返回值
        {
            case 0:
            {
                printf("device health!\n");
                /*if((buff[1]!= 0x0))
                {
                    read(fd, buff, 5);
                    printf("while:buff[0] = %x buff[1] = %x \n", buff[0], buff[1]);
                }*/
                return 0;//break;
            }
            case 1: printf("Health Warning: %x.\n", buff[1] & 0x00f000);
                return 1;//break;
            case 2: printf("Health Error: %x.\n", buff[1] & 0x0f0000);
                return 2;//break;
            default:perror("Health Status error\n");
        }
        printf("in while\n");
        
    }//end of while
    printf("health timoout\n");
    //TODO return timeout code
    // And then add 保护性停机,不能进行scan
    return -1;
}

time_t GetTime_ms()
{
    struct timespec time1 = {0, 0};   
    
    clock_gettime(CLOCK_REALTIME, &time1); 
    //typedef long     time_t;        
    printf("CLOCK_REALTIME: %ld, %ld\n", time1.tv_sec, time1.tv_nsec);
    //L是长整型的标识
    return time1.tv_sec*1000L + time1.tv_nsec/1000000L;
}
void RplidarScan(fd)
{
    StopScan(fd); //非常重要force the previous operation to stop
    write(fd, CMD_SCAN, 2);
//    printf("start scan\n");
//    ReadUart(fd);
/*    unsigned char *p = (unsigned char*)&i; 
    unsigned int num,num1,num2,num3,num4;
    num1=(unsigned int)(*p)<<24;
    num2=((unsigned int)*(p+1))<<16;
    num3=((unsigned int)*(p+2))<<8;
    num4=((unsigned int)*(p+3));
    num=num1+num2+num3+num4;*/
}
void RplidarReset(fd)
{
    usleep(1000);
    write(fd, CMD_RESET, 2);
    usleep(1000);
}
void RplidarInfo(fd)
{
    write(fd, CMD_INFO, 2);
    usleep(1000);
    ReadUart(fd);
}
void force_scan(fd)
{
    write(fd, FORCE_SCAN, 2);
    usleep(1000);
    ReadUart(fd);
}
void StopScan(int fd)
{
    write(fd, CMD_STOP, 2);
    printf("stop scan\n");
//    ReadUart(fd, 7);
    usleep(1000);
    ReadUart(fd);
}
void CloseUart(int fd)
{
    close(fd);
    printf("close dev.\n");
}
