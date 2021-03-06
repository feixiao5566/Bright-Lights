#include<stdio.h>
void main()
{
    int a[5] = {1,2,3,4,5};
    int *ptr = (int *)(&a + 1);
    printf("%d, %d", *(a + 1), *(ptr -1));
}

/*预测输出:
 *2, 1
 *实际输出:
 *2, 5
 *分析:
 *    a即是数组首地址,&a是首地址的首地址,&a+1一步就跨了a的四步
 *    因此&a+1就相当于a+4,指向a[5](a[5]就可以理解a[1][0]),因此ptr-1 = (&a+1)-1 = a[4]=5
 *    *(ptr-1)=*(&a[4]+4-4) = a[4]
 *a+1表示数组a的首元素地址+偏移1
 *&a+1表示数组a的地址+偏移1, 指向数组a外面的下一个地址
 * */
