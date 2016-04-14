#pragma once
#include<stdio.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<sys/time.h>
#include<sys/select.h>
#include<unistd.h>
#include<fcntl.h>
#include<termios.h>
#include<errno.h>
#include<time.h>
#include<string.h>

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
void ReadUart(int fd);
int GetHealth(int fd);
time_t GetTime_ms();
void StopScan(int fd);
void CloseUart(int fd);
