#!/usr/bin/env python
# encoding: utf-8

import os

print('Process (%s)start...'% os.getpid())
#这个函数是在Unix/Linux/Mac上用的 Windows没有fork调用
pid = os.fork()
if pid == -1:
    print('Fork error')
elif pid == 0:
    print('I am child process(%s)and my parent is %s.'%(os.getpid(), os.getppid()))
else:
    print('I (%s) just created a child process (%s).'%(os.getpid(), pid))
#这同Linux C创建进程的方法步骤是一样的,用的函数也是一样的,
#Linux C进程头文件声明在#include<unistd.h>
#Py要导入os


#用于Win上的跨平台多进程multiprocessing

from multiprocessing import Process
import os

#子进程要执行的代码
def run_proc(name):
    print('Run child process %s (%s)...'%(name, os.getpid()))

if __name__ == '__main__':
    print('Parent process %s.'% os.getpid())
    p = Process(target = run_proc, args = ('test',))
    print('Child process will start.')
    p.start()
    p.join()
    print('Child process end.')
#创建子进程时,只需要传入一个执行函数和函数的参数,创建一个Process实例
#用start()方法启动,这样创建进程比fork()还简单

#join()会等待子进程结束后在继续运行,通常用于进程间的同步

##进程池Pool
#当需要启动大量子进程,用进程池可以批量创建子进程:
from multiprocessing import Pool
import os, time, random

def long_time_task(name):
    print('Run task %s (%s)...'% (name, os.getpid()))
    start = time.time()
    time.sleep(random.random() * 3)
    end = time.time()
    print('Task %s runs %0.2f seconds.'%(name, (end - start)))

if __name__ == '__main__':
    print('Parent process %s.'% os.getpid())
    p = Pool(4) #电脑上同时执行的进程数
    for i in range(5):
        p.apply_async(long_time_task, args = (i, ))
    print('Writing for all subprocesses done...')
    p.close()
    p.join()
    print('All subprocesses done.')
#pool对象调用join()方法会等待所有的子进程执行完毕,调用join()之前必须先调用
#close(),调用close()之后就不能继续添加新的Process了
#pool的默认大小是CPU的核数

##子进程

import subprocess
print('$ nslookup www.python.org')
r = subprocess.call(['nslookup', 'www.python.org'])
print('Exit code:', r)

print('$ nslookup')
p = subprocess.Popen(['nslookup'], stdin = subprocess.PIPE, stdout = subprocess.PIPE, stderr = subprocess.PIPE)
output, err = p.communicate(b'set q = mx\npython.org\nexit\n')
print(output.decode('utf-8'))
print('Exit code:', p.returncode)
#朕,没看明白这个子进程想干啥....先这样吧不想看

##进程间通信
#在Unix/Linux下,multiprocessing模块封装了fork()调用,使我们不需要关注fork()细节
#Win下没有fork, 因此multiprocessing需要模拟出fork的效果,父进程所有python
#对象都必须通过pickle序列化再传到子进程去,所以如果multiprocessing在Win下
#调用失败了,要先考虑是不是pickle失败了
#不写了!!!困
