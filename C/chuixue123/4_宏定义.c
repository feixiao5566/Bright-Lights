/*写一个"标准"宏MIN, 这个宏输出两个参数并返回较小的一个*/
#include<stdio.h>

#define MIN(a,b) (a>b?b:a)

void main()
{
    int a;
    int b;
    printf("请输入a,b的值:\n");
    scanf("%d, %d",&a, &b);
    printf("%d\n", MIN(a,b));
}

/*自己的总结反思
 *经典题目了,也还是会有疏漏,怎么可以忘记在比大小的时候忘记等于号呢!!!!
 *另外,要懂得在宏中小心地把参数用括号括起来(养成好习惯)
 *标准写法:
 *define MIN(A,B) ((A)<=(B)?(A):(B))
 *
 *大于等于 括号
 * */
