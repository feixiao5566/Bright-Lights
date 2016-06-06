#!/usr/bin/env python
# encoding: utf-8

import  xdrlib ,sys
import xlrd
def open_excel(file= 'file.xls'):
#    try:
        data = xlrd.open_workbook(file)
        return data

def excel_table_byname(file= 'file.xls',colnameindex=0,by_name=u'Sheet1'):
    data = open_excel(file)
    table = data.sheet_by_name(by_name)
    nrows = table.nrows #行数 
    colnames =  table.row_values(colnameindex) #某一行数据 
    list =[]
    for rownum in range(1,nrows):
         row = table.row_values(rownum)
         if row:
             app = {}
             for i in range(len(colnames)):
                app[colnames[i]] = row[i]
             list.append(app)
    return list

def main():

   tables = excel_table_byname()
   for row in tables:
       print("%s有" % row["展馆"] if row["展馆"] else "", row["甲方名称"], "展位号是 %s" % row["展位号"])
#       print(row["甲方名称"], "展位号是 %s" % row["展位号"])
       

if __name__=="__main__":
    main()
    
