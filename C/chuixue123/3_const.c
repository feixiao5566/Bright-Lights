#include<stdio.h>

int main()
{
    const int a;
    int const a;
    const int *a;
    int * const a;
    int const *a const;
}

/*const只读变量,即变量保存在只读静态存储区.编译时,如何尝试修改只读变量,
 *则编译器提示出错,就能防止误修改
 *1.a的值不可变 a是一个常整型数
 *2.同1,a的值不可变 同一
 *3.a的值可变,地址不可变 指向常整型的指针
 *4.a的地址可变值不可变 指向整型的常指针
 *5.值和址都不可变 指向常整型的常指针
 * */
