#include<stdio.h>

int main()
{
    int *p = 0;
    p++;
    printf("p = %d\n", p);
//    printf("*p = %d\n", *p);
    return 0;
}

/*指针输出
 *这里,p = 0和 p = NULL值是一样的
 *事实上内存地址是4的地方确实是不能访问的
 *但是,它的地址可以访问的
 *所以答案是4
 *
 *
 *
 *下面的这句注释的值就不能用了
 *会segment fault
 *
 * */
