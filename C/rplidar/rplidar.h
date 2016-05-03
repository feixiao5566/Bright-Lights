#pragma once
#include<stdio.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<sys/time.h>
#include<sys/select.h>
//#include<unistd.h>
#include<fcntl.h>
#include<termios.h>
#include<errno.h>
#include<time.h>
#include<string.h>
#include <stdlib.h>
#include <malloc.h>
//usleep功能把进程挂起一段时间， 单位是微秒（百万分之一秒）； 　　
#include<unistd.h>
//语法: void usleep(int micro_seconds); 
/*
const char CMD_HEALTH[2]  = {0xA5,0x52};
const char CMD_INFO[2]  = {0xA5,0x50};
const char CMD_SCAN[2]  = {0xA5,0x20};
const char FORCE_SCAN[2]  = {0xA5,0x21};
const char CMD_STOP[2]  = {0xA5,0x25};
const char CMD_RESET[2]  = {0xA5,0x40};
*/


int InitUart();
void WrietUart(int fd, char *cmd, int size);
int ReadUart(int fd);
void RplidarInfo(int fd);
int GetHealth(int fd);
time_t GetTime_ms();
void RplidarReset(int fd);
void StopScan(int fd);
void CloseUart(int fd);
