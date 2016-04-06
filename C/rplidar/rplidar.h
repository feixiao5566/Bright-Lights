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

int InitUart();
void WrietUart(int fd);
void ReadUart(int fd);
void CloseUart(int fd);
