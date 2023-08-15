n = int(input())
A = [int(input()) for _ in range(n)]
def score(A):
    res = 0
    for i in range(len(A)):
        res += (4/5)**i * A[i]
    return 0.2*res
print(score(A))
print(sum(score(A[:i] + A[i+1:]) for i in range(len(A)))/len(A))
