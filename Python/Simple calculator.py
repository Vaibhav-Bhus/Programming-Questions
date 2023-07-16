print("Simple Calculator\nChoose the operation\n1.Addition\n2.Subtraction\n3.Mult3iplication\n4.Division")
ch = int(input("choose the operation"))
if ch==1:
    a = int(input("Enter first no: "))
    b = int(input("Enter second no: "))
    ans = a + b
    print(ans)
elif ch==2:
    a = int(input("Enter first no: "))
    b = int(input("Enter second no: "))
    ans = a - b
    print(ans)
elif ch==3:
    a = int(input("Enter first no: "))
    b = int(input("Enter second no: "))
    ans = a * b
    print(ans)
elif ch==5:
    a = int(input("Enter first no: "))
    b = int(input("Enter second no: "))
    ans = a / b
    print(ans)
else :
    print("Choosen wrong option")

