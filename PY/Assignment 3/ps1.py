import collections
def wid(str1, str2):
    r = collections.Counter(str2)
    s = len(str2)
    i = a = b = 0
    for j, c in enumerate(str1, 1):
        s -= r[c] > 0
        r[c] -= 1
        if not s:
            while i < b and r[str1[i]] < 0:
                r[str1[i]] += 1
                i += 1
            if not b or j - i <= b - a:
                a = i
                b = j
    return str1[a:b]
           
str1 = input()
str2 = input()
print("Minimum window = ", wid(str1, str2))
