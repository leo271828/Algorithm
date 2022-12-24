class Calculator():
    def power(self, n, p):
        self.n = n
        self.p = p
        print(n, p)
        if n < 0 or p < 0 :
            raise ValueError("n and p should be non-negative")
        return pow(n, p)
        

myCal = Calculator()
ans = myCal.power(2, -3)
print(ans)