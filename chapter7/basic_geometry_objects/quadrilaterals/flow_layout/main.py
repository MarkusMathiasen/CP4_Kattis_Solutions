while True:
    m = int(input())
    if m == 0:
        break
    h = 0
    max_h = 0
    w = 0
    max_w = 0
    while True:
        a,b = map(int,input().split())
        if a == -1 and b == -1:
            break
        if a + w > m:
            h += max_h
            max_h = 0
            w = 0
        w += a
        max_w = max(max_w,w)
        max_h = max(max_h,b)
    h += max_h
    print(max_w, "x", h)
