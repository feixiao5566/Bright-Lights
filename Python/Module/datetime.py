#!/usr/bin/env python
# encoding: utf-8

#import datetime.datetime    #这两行导入datetime在命令行可以,写入文件不行,为什么
from datetime import datetime
now = datetime.now()    #获取当前datetime
print(now)
print(type(now))
#获取指定日期和时间
dt = datetime(2016, 7, 1, 12, 0)
print(dt)

#datetime转换为timestamp
dt = datetime(2016, 7, 1, 12, 0)
dt.timestamp()
#这个timestamp是1970计算机元年到现在的秒数

#timestamp转换为datetime
#要把timestamp转换为datetime,使用datetime提供的fromtimestamp()方法
t = 1429417200.0
print(datetime.fromtimestamp(t))
#timestamp是一个浮点数,他没有时区概念,而datetime是有时区的
#上面的转换是在timestamp和本地时间做转换
print(datetime.utcfromtimestamp(t))

#str转换为datetime
cday = datetime.strptime('2015-6-1 18:19:59', '%Y-%m-%d %H:%M:%S')
print(cday)
#字符串'%Y-%m-%d %H:%M:%S'规定了日期和时间部分的格式
#转换后的datetime是没有时区信息的

#datetime转换为str strftime()
now = datetime.now()
print(now.strftime('%a, %b %d %H:%M'))
#注意这个日期和时间的格式化字符串

#datetime加减
#对日期和时间进行加减法实际上就是把datetime往后或往前计算,得到新的日期时间
#可以直接使用+和-运算符,要导入timedelta类
from datetime import datetime, timedelta
now = datetime.now()
print(now)
print(now + timedelta(hours = 10))
print(now - timedelta(days = 1))
print(now + timedelta(days = 2, hours = 12))

#本地时间转换为UTC时间
#指系统设定时区的时间
#一个datetime类型有一个时区属性tzinfo,但是默认为None,所以无法区分这个
#datetime到底是哪个时区,除非强行给datetime设置一个时区
from datetime import datetime, timedelta, timezone
tz_utc_8 = timezone(timedelta(hours = 8))#创建时区UTC+8:00
now = datetime.now()
print(now)


