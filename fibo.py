import numpy as np
import timeit

def matrix_pow(matrix,n):
	if (n == 1): 
		return matrix
	else: 
		x = matrix_pow(matrix,n/2)
		if (n%2 == 0): return np.dot(x,x)
		else: return np.dot(np.dot(x, x),matrix)

def fibo(n):
	if n == 1: 
		return 0
	elif n == 2: 
		return 1
	else: 
		matrix = np.matrix('1,1;1,0')
		mat_ans = matrix_pow(matrix, n-1) 
		return mat_ans.item((0,0))

def main():
	# |F(n)  | = |1 1||F(n-1)|
	# |F(n-1)|   |1 0||F(n-2)| 
  n = input('number for fibonnaci : ')
  number =int(n)
  print(fibo(n))

if __name__ == "__main__": 
	main()
