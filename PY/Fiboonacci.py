nterms = int(input("Enter No. Of terms : "))
n1, n2 = 0, 1

print("Fibonacci sequence : ", end="")
for i in range (nterms):
    print(n1, end = " ")
    nxt = n1 + n2
    n1 = n2
    n2 = nxt
