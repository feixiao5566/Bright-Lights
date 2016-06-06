#include"UART.h"
int main()
{
    int fd;
    int i = 0, n = 0;
//    char CMD_SINGLE[10]  = {0xA5,0x5A,0x00,0x10,0x00,0x00,0x02,0x3A,0x00,0x01};
char CMD_SINGLE[7]  = {0xAA,0x00,0x22,0x00,0x00,0x22,0x8e};
    char port[] = {"/dev/ttyUSB0"};
    unsigned int buff[2] = {0}; //关于读数异常,可以把int改成char
    std::cout<<"Init Uart"<<std::endl;
    fd = InitUart(port, 115200);
    std::cout<<"Write Uart"<<std::endl;
//    WrietUart(fd, CMD_SINGLE, 10);
    tcflush(fd, TCIOFLUSH);
    WrietUart(fd, CMD_SINGLE, sizeof(CMD_SINGLE));
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    ret_select = select(fd + 1, &set_input, NULL, NULL, &timeout);
    if(ret_select < 0)
    perror("select failed");
  else
    if (ret_select == 0)
        printf("timeout\n");
    else
    {
        if (FD_ISSET(fd, &set_input))
        {
            std::cout<<"Read Uart"<<std::endl;
    
            ReadUart(fd, 24, buff);
            for(i = 0; i < 24; i++)
            {
                std::cout << buff[i];
            }
            std::cout<<std::endl;
        } 
     }  
    CloseUart(fd);
}
