x1 = input()
y1 = input()
x2 = input()
y1 = input()
x3 = input()
y3 = input()
ok = False
x1 = int(x1)
x2 = int(x2)
x3 = int(x3)
y1 = int(y1)
y2 = int(y2)
y3 = int(y3)

t1 = (x3 - x2) * (x1 - x0) + (y3 - y2) * (y1 - y0)
t2 = (x3 - x1) * (x2 - x0) + (y3 - y1) * (y2 - y0)
t3 = (x2 - x1) * (x3 - x0) + (y2 - y1) * (y3 - y0)
if not t1 and not t2 and not t3:
	ok = true

if 3 * x0 == x1 + x2 + x3 and 3 * y0 == y1 + y2 + y3:
	ok = true

t1 = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)
t2 = (x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0)
t3 = (x3 - x0) * (x3 - x0) + (y3 - y0) * (y3 - y0)
if t1 == t2 and t2 == t3:
	ok = true




