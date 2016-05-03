#!/usr/bin/env python
# encoding: utf-8

##collections是Py内建的一个集合模块,提供了许多有用的集合类

#namedtuple
#namedtuple是一个函数,它用来创建一个自定义的tuple对象,
#并且规定了tuple元素的个数,并可以用属性而不是索引来引用tuple的某个元素
#这样一来,用nametpule可以很方便地定义一种数据类型,它具备tuple的不变性,
#又可以根据属性来引用.使用十分方便
#可以验证创建Point对象是tuple的一种子类

from collections import namedtuple
Point = namedtuple('Point',['x','y'])
p = Point(1,2)
print(p.x)
print(p.y)
print(isinstance(p,Point))
print(isinstance(p,tuple))

#类似的,如果要用坐标和半径表示一个圆,也可以用nametpule定义:
#nametpule('名称',[属性list]):
Circle = namedtuple('Circle', ['x','y','r'])

##deque
#使用list存储数据时,按照索引访问元素很快,但是插入和删除元素就很慢了,
#因为list是线性存储,数据量大的时候,插入和删除效率很低.
#deque是为了高效实现插入和删除操作的双向列表,适合用于队列和栈
from collections import deque
q = deque(['a', 'b', 'c'])
q.append('x')
q.appendleft('y')
print(q)
#deque除了实现list的append()和pop()外,还支持appendleft()和popleft(),
#这样就可以非常高效地往头部添加或删除元素

##defaultdict
#使用dict时,如果引用的key不存在,就会抛出keyError.如果希望key不存在时,
#返回一个默认值,就可以用defaultdict:
from collections import defaultdict
dd = defaultdict(lambda:'N/A')
dd['key1'] = 'abc'
print(dd['key1'])
print(dd['key2'])
#注意默认值是调用函数返回值的,而函数在创建defaultdict对象时传入
#除了在Key不存在时返回默认值,defaultdict的其他行为跟dict是完全一样的


