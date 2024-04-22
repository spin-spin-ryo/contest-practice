def power(n: int, r: int) -> int:
    return pow(n, r)  # Use Python's built-in pow function with modulus.

def f(n: int, k: int, N: int) -> int:
    if k > 70:
        return 0
    r = 1 << k  # This is more efficient than pow(2, k).
    return min(max(N - r * n + 1, 0), r)

def main():
    T = int(input())
    for _ in range(T):
        N, X, K = map(int, input().split())
        ans = f(X, K, N)
        # print(ans)
        count = 0
        while X != 0:
            x = X // 2
            count += 1
            if X!=1:
                y = 2*x+1 if X % 2 == 0 else 2*x
                if y <= N and K - count - 1 >= 0 and y > 0:
                    ans += f(y, K - count - 1, N)
                if count == K:
                    ans += 1
            X = x
        print(ans)

if __name__ == "__main__":
    main()
