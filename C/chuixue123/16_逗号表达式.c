#include<stdio.h>

void main()
{
    int a, b;
    a = b = 1;
    b = a++, b++, ++a;
    printf("%d\n", b);
}




/*这个题十分得有趣
 * 关于逗号表达式
 * 我开始以为的逗号表达式是b = (a++, b++, ++a)
 * 所以算出来结果是3
 * 然,这个逗号表达式的第一个其实是 b = a++......
 * 所以最后那个++a算不得数的
 * 就是2咯
 *
 *
 *
 * */
