

list1 = [item for item in input("Enter the strings with space seperated : ").split()]
cnt = 0
for i in list1:
    if len(i) > 2 and i[0] == i[-1]:
      cnt += 1


print(cnt)
