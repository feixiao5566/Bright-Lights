#include<stdio.h>

void main()
{
    char a[4] = {1, 2, 3, 4};
    char *ptr = (int*)(&a+1);
    printf("%d", *(ptr - 1));
}

/*这个题,真的很经典,虽然做对了,还是觉得有必要写出来
 * (int*)(&a+1) 这样加,每次加一步,char一步是1, int一步4
 * 所以ptr被加到了a[4]
 * 作为char减一a[3]
 * 所以等于4
 *
 * */
