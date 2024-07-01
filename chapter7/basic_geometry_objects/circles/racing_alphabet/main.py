import math
T = int(input())
C = "ABCDEFGHIJKLMNOPQRSTUVWXYZ '"
for _ in range(T):
    S = input()
    dist = 0
    for i in range(len(S)-1):
        a = C.index(S[i])
        b = C.index(S[i+1])
        dist += min(abs(a-b), 28-abs(a-b))
    dist = dist/28*60*math.pi
    print(len(S) + dist/15)
