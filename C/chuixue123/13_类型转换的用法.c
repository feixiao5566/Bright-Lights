#include<stdio.h>
typedef signed char int8;
typedef short int   int16;
typedef short unsigned int uint16;
void main()
{
    int8 i = -1;
    uint16 t = i;
    printf("%d\n", t);
    printf("%d\n", (uint16)-1);
}



/*这个题的考点是signed和unsigned之间的转换
 * 怎样理解负数在之间的转换呢,举个0x0~0xF的栗子:
 *      15      7
 *      14      6
 *      13      5
 *      12      4
 *      11      3
 *      10      2
 *      9       1
 *      8       0
 *      7       -1
 *      6       -2
 *      5       -3
 *      4       -4
 *      3       -5
 *      2       -6
 *      1       -7
 *      0       -8
 *而int 1和 uint 1是相等的,都是1,0都是0
 *所以把右边这一溜的-1~-8和左边的15~8对应起来
 *很明显-1对应的就是最大数15啊
 *
 *这样的好处是,-1+1 = 0
 *0xf+1 = 0
 *see?
 *
 * */
