f = open("record.txt","r")
record = []
for i in f:
    d = {}
    x = i.split(',')
    d.update({"Name": x[0]})
    d.update({"Employee ID": x[1]})
    d.update({"Designation":x[2]})
    d.update({"Salary": int(x[3])})
    d.update({"Experience": x[4]})
    record.append(d)

for i in record:
    for key,value in i.items():
        print(key,": ",value)
