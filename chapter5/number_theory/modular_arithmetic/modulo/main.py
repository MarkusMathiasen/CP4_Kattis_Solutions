A=[0]*42
for _ in range(10):
    A[int(input())%42]=1
print(sum(A))
