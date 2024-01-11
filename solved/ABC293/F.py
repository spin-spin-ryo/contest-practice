def root_n(N,s):
    l = 1
    r = N+1
    while r - l >1:
        m = (r+l)//2
        if pow(m,s) <= N:
            l = m
        else:
            r = m
    return l

def check_zeroone(N,b,d):
    if b== 1:
        return False
    while N!=1:
        if N%b == 0:
            N//= b
            d-=1
        else:
            if N%b != 1:
                return False
            else:
                N = (N-1)//b
                d-=1
    return d==1

T = int(input())
for _ in range(T):
    N = int(input())
    if N == 2:
        print(1)
        continue

    ans = 0
    bit_num = 0
    for bit in range(65):
        if (N>>bit_num) > 0:
            bit_num+=1
    for d in range(2,bit_num+1):
        if d == 2:
            ans +=2
        else:
            b = root_n(N,d-1)
            # print(N,b,d)
            if check_zeroone(N,b,d):
                ans+=1
    print(ans)
    

