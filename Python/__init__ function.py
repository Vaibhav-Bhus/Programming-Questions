class vehical(object):
    def __init__ (self, name, kind, color, value):
        self.name = name
        self.kind = kind
        self.color = color
        self.value = value
    def print_detail(self):
        print("name: ", self.name)
        print("kind: ", self.kind)
        print("color: ", self.color)
        print("value: ", self.value)


car1 = vehical("Ferrari", "car", "red", 70000)
car1.print_detail()
car2 = vehical("JEEP", "VAN", "BUE", 15000)
car2.print_detail()        
