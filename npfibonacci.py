import numpy as np

#exponentiation by squaring
def ebs(bas, exp):
    t = bas.copy()
    while exp > 0:
        if exp % 2:
            t = np.dot(t,bas)
        bas = np.dot(bas,bas)
        exp = exp // 2
    return t

m = np.array([[1,1],[1,0]], dtype=object)

fibN = (int)(input("Enter the fibonacci position: "))

fib = ebs(m, fibN)
print(fib[1][1])
'''
fib = n+2 f+1
	  n+1 f
'''
#entire matrix
print(fib)
