from collections import Counter 
def common(str1,str2): 	
	a = Counter(str1) 
	b = Counter(str2) 
	com = a & b
	if len(com) == 0: 
		return "No common characters."

	com_ch = list(com.elements()) 
	com_ch = sorted(com_ch) 

	return ','.join(com_ch) 

str1 = input()
str2 = input()

print("Common characters are : ", common(str1, str2))
