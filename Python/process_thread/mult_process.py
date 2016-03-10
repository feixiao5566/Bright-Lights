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
    p = Pool(4)
    for i in range(5):
        p.apply_async(long_time_task, args = (i, ))
    print('Writing for all subprocesses done...')
    p.close()
    p.join()
    print('All subprocesses done.')
