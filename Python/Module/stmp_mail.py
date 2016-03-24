#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#SMTP 是邮件发送协议,Python内置对SMTP的支持,可以发送纯文本邮件,HTML邮件以及
#   附带的邮件
#Py对SMTP支持有 smtplib 和 email 两个模块,email负责构造邮件,smtplib负责发送邮件


from email import encoders
from email.header import Header
from email.mime.text import MIMEText
from email.utils import parseaddr, formataddr
import smtplib

def _format_addr(s):
    name, addr = parseaddr(s)
    return formataddr((Header(name, 'utf-8').encode(), addr))
#输入Email地址和口令:
from_addr = input('From: ')
password = input('Password: ')
#输入收件人地址:
to_addr = input('To: ')
#输入SMTP服务器地址:
smtp_server = input('SMTP server: ')
#注意到构造MIMEText对象时,第一个参数就是邮件正文,第二个参数是MIME的subtype,
#传入'plain'表示纯文本,最终的MIME就是'text/plain',最后一定要用
#utf-8编码保证多语言兼容性.然后,通过SMTP发出去:
#下面就是纯文本邮件的本体
msg = MIMEText('hello, send by Python...', 'plain', 'utf-8')
msg['From'] = _format_addr('Python爱好者 <%s>' % from_addr)
msg['To'] = _format_addr('管理员 <%s>' % to_addr)
msg['Subject'] = Header('来自SMTP的问候……', 'utf-8').encode()

server = smtplib.SMTP(smtp_server, 25)  #SMTP协议默认端口是25
server.set_debuglevel(1)
server.login(from_addr, password)
server.sendmail(from_addr, [to_addr], msg.as_string())
server.quit()
