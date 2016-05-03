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
dt = now.replace(tzinfo = tz_utc_8)
print(dt)

#时区转换
#可以通过utcnow()拿到当前的UTC时间,再转换为任意时区的时间

#拿到UTC时间,并强制设置时区为UTC+0:00:
utc_dt = datetime.utcnow().replace(tzinfo = timezone.utc)
print(utc_dt)
#astimezone()将转换时区为北京时间
bj_dt = utc_dt.astimezone(timezone(timedelta(hours = 8)))
print(bj_dt)
#astimezone()就爱那个转换时区为东京时间:
tokyo_dt = utc_dt.astimezone(timezone(timedelta(hours = 9)))
print(tokyo_dt)
#astimezone()将bj_dt转换为东京时间
tokyo_dt2 = bj_dt.astimezone(timezone(timedelta(hours = 9)))
print(tokyo)

#时区转换的关键在于,拿到一个datetime时,要获知其正确的时区,
#然后强制设置时区,作为基准时间
#利用带时区的datetime,通过astimezone()方法,可以转换到任意时区.

#注:不是必须从UTC+0:00时区转换到其他时区,任何带时区的datetime
#都可以正确转换,例如上面bj_time到tokyo_dt的转换





##datetime表示的时间需要时区信息才能确定一个特定的时间,否则视为
#       本地时间
#如果要存储datetime,最佳方法是将其转换为timestamp再存储,因为
#       timestamp的值与时区完全无关



