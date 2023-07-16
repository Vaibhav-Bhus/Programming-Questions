a = int(input("Enter first no.: "))
b = int(input("Enter second no.: "))
c = int(input("Enter third no.: "))
if a > b:
    if a > c:
        print("The largest no is ",a)
elif c > a :
    if c > b:
        print("The largest no is ",c)
elif b > a :
    if b > c:
        print("The largest no is ",b)
else:
    print("All nos are equal")
