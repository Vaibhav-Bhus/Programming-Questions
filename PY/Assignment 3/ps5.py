def ispalindrome(str):
    return str == str[::-1]

str =input("Enter string:")
string = ispalindrome(str)

if string:
    print(True)
else:
    print(False)
