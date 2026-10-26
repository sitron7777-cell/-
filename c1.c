from fractions import Fraction

def print_matrix(M):
    for row in M:
        coefficients = " ".join(f"{str(v):>6}" for v in row[:-1])
        print(f"[{coefficients} | {str(row[-1]):>6}]")
    print()

M = [
    [0, -1, -1,  1,  0],
    [1,  1,  1,  1,  6],
    [2,  4,  1, -2, -11],
    [3,  1, -2,  2,  31]
]

M = [[Fraction(v) for v in row] for row in M]
n = len(M)

print("초기 첨가행렬")
print_matrix(M)

for col in range(n):
    pivot_row = None
    for r in range(col, n):
        if M[r][col] != 0:
            pivot_row = r
            break
            
    if pivot_row is None:
        raise ValueError("피벗이 0이므로 행 교환이 필요합니다.")
        
    if pivot_row != col:
        M[col], M[pivot_row] = M[pivot_row], M[col]
        print(f"R{col + 1} ↔ R{pivot_row + 1}")
        print_matrix(M)
        
    pivot = M[col][col]
    M[col] = [v / pivot for v in M[col]]
    
    for r in range(n):
        if r == col:
            continue
        factor = M[r][col]
        if factor != 0:
            M[r] = [
                M[r][c] - factor * M[col][c]
                for c in range(n + 1)
            ]

print("최종 행렬")
print_matrix(M)