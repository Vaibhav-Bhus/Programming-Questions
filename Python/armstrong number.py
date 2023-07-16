n = int (input ("Enter a number "))
temp = n
sum = 0
while n>0:
    digit = n%10
    sum=sum + (digit**3)
    n//=10
if temp == sum:
    print("Armstrong number ")
else:
    print ("Not a armstrong numbrer")
