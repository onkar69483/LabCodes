class Data:
    def __init__(self):
        self.data = []

    def read(self,size):
        for i in range(size):
            num=int(input("Enter number: "))
            self.data.append(num)
    def sort(self):
        size=len(self.data)
        for i in range(size-1):
            for j in range(size-i-1):
                if(self.data[j]>self.data[j+1]):
                    temp=self.data[j]
                    self.data[j]=self.data[j+1]
                    self.data[j+1]=temp
    def display(self):
        print("Data: ",self.data)

newData = Data()
newData.read(5)
newData.sort()
newData.display()