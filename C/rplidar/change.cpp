#include <iostream>
 
using namespace std;
 
typedef unsigned int UINT;
typedef unsigned char UCHAR;
 
int main()
{
    UINT i=0x12345678;
    cout<<hex<<i<<endl; //格式化16进制输出
    UCHAR *p = (UCHAR*)&i; 
    UINT num,num1,num2,num3,num4;
    num1=(UINT)(*p)<<24;
    num2=((UINT)*(p+1))<<16;
    num3=((UINT)*(p+2))<<8;
    num4=((UINT)*(p+3));
    num=num1+num2+num3+num4;
 
    cout<<"num1:"<<hex<<num1<<endl;     //看num1的16进制表示，下同
    cout<<"num2:"<<hex<<num2<<endl;
    cout<<"num3:"<<hex<<num3<<endl;
    cout<<"num4:"<<hex<<num4<<endl;
    cout<<"num:"<<hex<<num<<endl;
 
    unsigned char *q = (unsigned char*)&num;
    if((*q==0x78)&(*(q+1)==0x56))          
        cout<<"小端"<<endl;
    else if((*q==0x12)&(*(q+1)==0x34))
        cout<<"大端"<<endl;
    else
        cout<<"这是神马字节顺序呢？";
    return 0;
}
