
char *func(char *dest, const char *src, int count)
{
    char *tmp = dest;
    while(count)
    {
        if((*tmp = *src) != 0)
            src++;
        tmp++;
        count--;
    }
    return dest;
}

//请解析 上述 代码的执行功能
//遍历src字符串,直到src字符串遇到'\0', 把src的字符串赋值给tmp,返回dest

/*啊..忘记上面 tmp=dest了
 *把src复制给dest
 *事实上,这就是strncpy函数..
 *
 * */
