import keyword
import string
def isFloat(num):
    try:
        float(num)
        return True
    except ValueError:
        return False


op = ['+','-','','//','/','','%','=','==','+=','-=','/=','=','<<','>>','>','<','<=','>=']
with open("D:/Programming/CC/Assignment 2/sample.txt") as file:
    for line in file:
        line = line.split(" ")
        for i in line:
            if keyword.iskeyword(i):
                print(i = "\t" + i)
            elif i.isidentifier():
                print(i + "\t" + "Identifier")
            elif isFloat(i):
                print(i + "\t" + "Constant")
            elif i in op:
                print(i + "\t" + "Operator")
            elif i in string.punctuation:
                print(i + "\t" + "Special Symbol")
