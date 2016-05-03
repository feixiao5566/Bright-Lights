#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from email import encoders
from email.header import Header
from email.mime.text import MIMEText
from email.utils import parseaddr, formataddr
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase

def _format_addr(s):
    name, addr = parseaddr(s)
    return formataddr((Header(name, 'utf-8').encode(), addr))

from_addr = input('From: ')
password = input('Password: ')
to_addr = input('To: ')
smtp_server = input('SMTP server: ')
#邮件对象
msg = MIMEMultipart()
msg['From'] = _format_addr('东华帝君 <%s>' % from_addr)
msg['To'] = _format_addr('青丘凤九 <%s>' % to_addr)
msg['Subject'] = Header('来自团子的问候……', 'utf-8').encode()
#邮件正文是MIMEText:
msg.attach(MIMEText('开心,我一直都开着心','plain','utf-8'))
#添加附件就是加上一个MIMEBase, 从本地读取一个图片:
with open('/home/feixiao/图片/eggeye.jpg','rb') as f:
    mime = MIMEBase('image','png',filename = 'eggeye.jpg')
    mime.add_header('Content-Disposition','attachment',filename='eggeye.jpg')
    mime.add_header('Content-ID','<0>')
    mime.add_header('X-Attachment-Id', '0')
    mime.set_payload(f.read())
    encoders.encode_base64(mime)
    msg.attach(mime)
server = smtplib.SMTP(smtp_server, 25)
server.set_debuglevel(1)
server.login(from_addr, password)
server.sendmail(from_addr, [to_addr], msg.as_string())
server.quit()
