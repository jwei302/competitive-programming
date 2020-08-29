n = int(input())

a = map(int, input().split())

s = 0
ans = 0
for i in range(n):
	s+=a[i]
for i in range(n):
	s -= a[i]
	ans += a[i]*s

print(ans % (1000000007))