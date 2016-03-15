#include<stdio.h>

void main()
{
    int a = 20;
    if(1<=a<=10)
        printf("In range");
    else
        printf("Out of range");
}

/*
 *猜测答案:In Range
 *理由,从左向右 先是1 再是1
 *运行结果:In Range
 *分析:这两个<=的优先级是一样的,所以从左往右
 *
 *
 *
 *
 *
 *
 *
 * */
