class stand:
    lemonade = int(0)
    cash = int(2)
    ing = int(0)
    def make(self):
        if self.ing > 0:
            self.lemonade += 1
            self.ing -= 1
        else:
            print("not enough ingredients")
    def sell(self):
        if self.lemonade > 0:
            self.lemonade -= 1
            self.cash += 2
        else:
            print("no lemonade to sell")
    def buy(self):
        if self.cash > 0:
            self.ing += 1
            self.cash -= 1
        else:
            print("not enough money")

mystand = []
mystand.append(stand())
def makeS():
    mystand.append(stand())
while True:
    act = input("What do you want to do?") 
    x = int(input("To what stand?"))
    if x > len(mystand):
        print("oopsie woopsie thats not a stand")
    elif act == "make":
        mystand[0].make()
    elif act == "buy":
        mystand[0].buy()
    elif act == "sell":
        mystand[0].sell()
    else:
        print("not valid action")
    print("Cash = " + str(mystand[0].cash))
    print("ingredients = " + str(mystand[0].ing))
    print("lemoande = " + str(mystand[0].lemonade))
