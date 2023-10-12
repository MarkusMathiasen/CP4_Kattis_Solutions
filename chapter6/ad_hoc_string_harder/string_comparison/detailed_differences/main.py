n=int(input())
for _ in range(n):
    a=input()
    b=input()
    print(a)
    print(b)
    for i in range(len(a)):
        print('.' if a[i]==b[i] else '*', end="")
    print("\n")
