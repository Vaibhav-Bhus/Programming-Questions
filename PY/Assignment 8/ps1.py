class Student:
    def __init__(self):
        self.roll_no = int(input("Enter Student Roll No.: "))
        self.name = input("Enter Student Name.: ")
        self.marks = list(int(num) for num in input("Enter Marks separated by space: ").strip().split())[:5]
    def printInfo(self):
        print("Student Roll No. : ", self.roll_no)
        print("Student Name     : ", self.name)
        for i in range (0, 5):
            print("Subject ", i+1, "Marks : ", self.marks[i])
        print ("Total marks is   : ", sum(self.marks), "/ 500.00")
        self.avg = sum(self.marks)/5
        print ("Average marks is : ", self.avg)
        print ("Percentage is    : ", (sum(self.marks)/500*100), "%")
        if self.avg >= 90:
            self.grade = 'A'
        elif self.avg >= 80 and self.avg < 90:
            self.grade = 'B'
        elif self.avg >= 70 and self.avg < 80:
            self.grade = 'C'
        elif self.avg >= 60 and self.avg < 70:
            self.grade = 'D'
        else:
            self.grade = 'E'
        print ("Grade is         : ", self.grade)
    
obj = Student()
obj.printInfo()
