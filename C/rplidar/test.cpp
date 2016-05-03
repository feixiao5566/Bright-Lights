#include"UART.h"
int main()
{
    int fd;
    int i = 0, n = 0;
    char CMD_SINGLE[7]  = {0xAA,0x00,0x22,0x00,0x00,0x22,0x8e};//single
    char port[] = {"/dev/rfid"};
    unsigned int buff[28] = {0};
    std::cout<<"Init Uart"<<std::endl;
    fd = InitUart(port, 115200);
    std::cout<<"Write Uart"<<std::endl;
    WrietUart(fd, CMD_SINGLE, 7);
    std::cout<<"Read Uart"<<std::endl;

    ReadUart(fd, 50, buff);
    for(i = 0; i < 50; i++)
    {
        cout << buff[i];
    }
    std::cout<<std::endl;
    
    CloseUart(fd);
}
