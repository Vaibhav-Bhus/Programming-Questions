def encode(str1):
    output=''
    privious=str1[0]
    i=1
    count=1
    while len(str1)>i:
        if privious == str1[i]:
            count += 1
        else:
            output += str(count) + privious
            count = 1
            privious = str1[i]

        if i == len(str1) - 1:
            output += str(count) + privious
        i += 1
    if len(str1) == 1:
        output += str(count) + privious
    return output


str1 = input()
print(encode(str1))

