from fractions import Fraction

def print_matrix(N):
    for row in N:
        coefficients = " ".join(f"{str(v):>6}" for v in row[:-1])
        print(f"[{coefficients} | {str(row[-1]):>6}]")
    print()

M = [
    [0, -1, -1,  1,  0],
    [1,  1,  1,  1,  6],
    [2,  4,  1, -2, -11],
    [3,  1, -2,  2,  31]
]

N = [[Fraction(v) for v in row] for row in M]
n = len(N)

print("초기 첨가행렬")
print_matrix(N)

for col in range(n):
    pivot_col = next((r for r in range(col, n) if N[r][col] != 0), None)
    if pivot_col is None:
        raise ValueError("pivot row is None")
    
    if pivot_col != col:
        N[col], N[pivot_col] = N[pivot_col], N[col]
        print(f"R{col + 1} ↔ R{pivot_col + 1}")
        print_matrix(N)
        
    pivot = N[col][col]
    N[col] = [v / pivot for v in N[col]]
    print(f"R{col + 1} = R{col + 1} / {pivot}")
    print_matrix(N)
    
    for r in range(n):
        if r == col:
            continue
        factor = N[r][col]
        if factor != 0:
            N[r] = [N[r][c] - factor * N[col][c] for c in range(n + 1)]
            print(f"R{r + 1} = R{r + 1} - ({factor}) * R{col + 1}")
            print_matrix(N)

print("최종 결과")
print_matrix(N)