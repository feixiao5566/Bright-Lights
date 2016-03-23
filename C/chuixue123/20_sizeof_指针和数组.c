//在 32位系统下，执行如下代码，运算结果是多少？
#include<stdio.h>
void func( char str[100])
{
    printf("%d\n",sizeof( str )   );
    //数组传递到子函数,会退化为指针
}

int main(void)
{
    char str[] = "www.chuxue123.com";
    char *p = str ;
    int n = 10;

/*    int a = 10;
    char s = 'a';
    int *aa = &a;
    char *ss = &s;
*/

    printf("%d,%d,%d,",sizeof (str ),sizeof ( p ) ,sizeof ( n )  );

    func(str);
//    printf("%d, %d, %d, %d\n", sizeof(a), sizeof(s), sizeof(aa), sizeof(ss));

    return 0;
}







/*char str[] = "www.chuxue123.com";
 * sizeof (str ) ，str是 数组，存放字符串  "www.chuxue123.com" ，注意，字符串后面有 '\0'的，共 18个字节，所以 sizeof (str )  的结果为 18.有的人 以为是 4 或者 17，都是错的
 * ===================================================================================================
 * char *p = str ;
 * sizeof ( p ) ，p 是 指针， 指针占用 4 个字节，因此 结果为 4
 * ===================================================================================================
 * int n = 10;
 * sizeof ( n ) ，int 在 32 位 系统下 一般都为 4 ，因此 结果为 4
 * ===================================================================================================
 * void func( char str[100])
 * {
 *     printf("%d",sizeof( str )   );
 *
 *     }
 *     这个比较多人选择 100 ，实际上 会 当作指针进行处理，而不是 栈里面开辟 这么大的数据，因而 sizeof(str )是 4 ，而不是 100
 *
 * */
