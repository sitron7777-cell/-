from fractions import Fraction

def print_matrix(name, M):
    print(name)
    for row in M:
        print(f"[" + ", ".join(f"{str(v):>5}" for v in row) + "]")
    print()

A = [
    [ 1,  2,  1],
    [ 2,  3,  3],
    [-3, -10, 2]
]

n = len(A)
U = [[Fraction(v) for v in row] for row in A]
L = [
    [Fraction(1 if i == j else 0) for j in range(n)]
    for i in range(n)
]

print_matrix("초기 행렬 A", A)

for k in range(n - 1):
    if U[k][k] == 0:
        raise ValueError("피벗이 0입니다.")
    for i in range(k + 1, n):
        multiplier = U[i][k] / U[k][k]
        L[i][k] = multiplier
        U[i] = [U[i][j] - multiplier * U[k][j] for j in range(n)]

print_matrix("최종 하삼각행렬 L", L)
print_matrix("최종 상삼각행렬 U", U)

LU = [[sum(L[i][k] * U[k][j] for k in range(n)) for j in range(n)] for i in range(n)]
print_matrix("검산: L × U", LU)
print_matrix("LU = A 확인", LU == A)