/*  
 *考虑到目前大多数的串口通讯都是8N1, 我先不加别的其他方式的选择了,后面如果有需要再选择添加
 */
#pragma once
#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<sys/time.h>
#include<sys/select.h>
#include<fcntl.h>
#include<termios.h>
#include<errno.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int InitUart(char *port, int baudrate);
void WrietUart(int fd, char *sendmsg, int size);
int ReadUart(int fd, int size, unsigned int *buff);
void CloseUart(int fd);

