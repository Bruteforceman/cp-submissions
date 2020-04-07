test = int(input())
for i in range(test):
	a, b = map(int, input().split(' '))
	print((b - a%b) % b)