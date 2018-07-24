import math
t = input()
x,y = t.split(' ')
x = float(x)
y = float(y)
a = x*math.log(y)
b = y*math.log(x)
if a == b:
	print('=')
elif a < b:
	print('>')
else:
	print('<')
