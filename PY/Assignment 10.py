class Student:
    def __init__(self):
        self.student_id=None
        self.marks=None
        self.age=None
    def set_marks(self,marks):
        self.marks=marks
    def set_age(self,age):
        self.age=age
    def set_student_id(self,student_id):
        self.student_id=student_id
    def get_student_id(self):
        return self.student_id
    def get_marks(self):
        return self.marks
    def get_age(self):
        return self.age
    def validate_age(self):
        return self.age > 20
    def validate_marks(self):
        return 0<=self.marks<=100
    def check_qualification(self):
        return self.validate_marks() and self.validate_age() and self.marks>=65 
    
s=Student()
s.set_student_id(24)
s.set_age(21)
s.set_marks(89)
print(s.check_qualification())
