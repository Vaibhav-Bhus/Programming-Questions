import openpyxl
wb = openpyxl.load_workbook("D:\\Super Market Management System.xlsx")
sh1 = wb.active

data = [(1, 'vaibhav' ,2001),(2, 'yash', 2005)]
for i in data:
    sh1.append(i)


wb.save("D:\\Super Market Management System.xlsx")
