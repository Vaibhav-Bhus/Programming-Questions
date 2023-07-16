
f = open('sample.txt','a')
inp = input("Enter Content to be append in the file: ")
f.write(inp)
print("Sucessfully appended content in file.")
f.close()
