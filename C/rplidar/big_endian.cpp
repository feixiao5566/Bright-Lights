#include <iostream>

typedef unsigned int UINT;
typedef unsigned char UCHAR;

int main()
{
    UINT i = 0x12345678;
//    std::cout<<std::hex<<i<<std::endl;
    UCHAR *p = (UCHAR*)&i;          //将i的地址传给数组指针p，实际上p指向的地址是i在内存中存储的第一个字节，大端就是0x12，小端就是0x78
    if((*p==0x78)&(*(p+1)==0x56))
        std::cout<<"小端"<<std::endl;
    else if((*p==0x12)&(*(p+1)==0x34))
        std::cout<<"大端"<<std::endl;
    else
        std::cout<<"这是神马字节顺序呢？";
    return 0;
}
