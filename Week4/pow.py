class Solution:
    def myPow(self, x: float, n: int) -> float:
    
        if n == 0:
            return 1.0
        
        elif n == 1:
            return x
        
        elif n < 0:
            return  self.myPow( 1/x, -n)
        
        if n & 1:
            return x * self.myPow( x*x, n // 2)
        else:
            return self.myPow( x*x, n // 2)
