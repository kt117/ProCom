n = int(input())
ans = 1;
for i in range(n // 2):
	ans *= n - i
	
for i in range(n // 2):
	ans //= i + 1;
	
for i in range(n // 2 - 1):
	ans *= (i + 1) * (i + 1);
	
print(ans // 2)