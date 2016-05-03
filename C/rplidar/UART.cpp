#include"UART.h"

int InitUart(char *port, int baudrate)
{
    int ret_select = 0;
    int bytes = 0;
    int write_num = 0;
    int read_num = 0;
    int status;
    int fd = open(port, O_RDWR|O_NONBLOCK);
    if(-1 == fd)
    {
        perror("can`t open UART\n");
        exit(-1);
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
        perror("UART:tcsetattr etc abnormal");
        exit(-1);
    }
    std::cout<<"UART Init!\n";
    return fd;

}

void WrietUart(int fd, char *sendmsg, int size)
{
    int ret = 0;
    ret = write(fd, sendmsg, size);
    if(ret == -1)
    {
        perror("UART:Write Faile.\n");
        exit(-1);
    }
    else
    {
        std::cout << "%s cmd has been writen %d bytes.\n" << sendmsg << ret;
    }
}

int ReadUart(int fd, int size, unsigned int *buff)
{
    int ret = 0;
    int n = 0;
    buff = (unsigned int *)memset(buff, 0, size);
    ret = read(fd, buff, size);
    if(ret == -1)
    {
        perror("UART Read Failed.\n");
    }

    std::cout << std::endl;
    
    return ret;
}

void CloseUart(int fd)
{
    close(fd);
    printf("close dev.\n");
}
