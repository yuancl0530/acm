Next = []
dic = []
def getNext(s):
	k = -1
	Next[0] = k
	for i in range(0,s.length()):
		while k >=0 and dic[s[k+1]-'a'] != s[i]:
			k = Next[k]
		if dic[s[k+1]-'a'] == s[i]:
			k = k+1
		Next[i] = k
def solve(s):
	getNext(s)
	m = s.length()
	k = Next[m-1]
	while k+1 > m/2:
		k = Next[k]
	m = m - (k+1)
	for i in range(0,m):
		print(s[i],end='')
	for i in range(0,m):
		print(dic[s[i]-'a'],end='')
	print()
	

if __name__ == '__main__':
	T = int(input())
	for kase in range(0,T):
		t = input()
		s = input()
		for i in range(0,26):
			dic[t[i]-'a'] = t[i]
		solve(s)

