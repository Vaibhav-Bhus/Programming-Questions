import collections
str1 = input("Enter String:")
i = collections.defaultdict(int)
for c in str1:
    i[c] += 1

for c in sorted(i, key = i.get, reverse = True):
  if i[c] > 1:
      print('%s %d' % (c, i[c]))
