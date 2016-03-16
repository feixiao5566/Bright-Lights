/*
 *如何输出源文件的文件名和当前执行的行数
 * */
#include<stdio.h>
int main(int argc, char *argv[])
{
    printf("%s\n", argv[0]);//执行的文件名
    printf("当前执行行数:%d\n", __LINE__);//当前执行行数,包括注释等,比如8
    printf("%s\n", __FILE__);//源程序的名字
    printf("当前执行行数:%d\n", __LINE__);
    printf("当前日期是:%s\n", __DATE__);
    printf("编译器是否遵循ANSI C标准:%d\n", __STDC__);
    printf("当前时间的字符串:%s\n", __TIME__);
}
