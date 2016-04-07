#include"rplidar.h"

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
    /*
    if(status != 0)
    {
        perror("open UART tcsetattr error\n");
        //失败的errno值有错误信息
        exit(-1);
    }*/
//设置串口格式为8N1
    options.c_cflag &= ~CSIZE;
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_iflag &= ~(INPCK | ISTRIP);
    tcflush(fd, TCIOFLUSH);
    /*
    status = tcsetattr(fd, TCSANOW, &options);
    if(status != 0)
    {
        perror("tcsetattr error\n");
        exit(-1);
    }*/
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
//    close(fd);
    printf("fd is: %d\n", fd);
    return fd;

}

void WrietUart(int fd, char *cmd, int size)
{
    //int
    write(fd, cmd, size);
}

void ReadUart(int fd)
{
    int ret = 0;
    unsigned char buff[1024];
//    tcflush(fd, TCIOFLUSH);
        //清除终端未完成的输入/输出请求及数据
        //TCIOFLUSH清除所有正在发生的I/O数据
    ret = read(fd, buff, 1024);
    if(ret == -1)
    {
        perror("ReadFailed.\n");
    }
    else
    {
        printf("Read: %d bytes read.\n", ret);
    }
    printf("%d\n", buff);
}

void CloseUart(int fd)
{
    close(fd);
    printf("close dev.\n");
}
