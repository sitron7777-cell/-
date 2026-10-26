from fractions import Fraction

def print_matrix(M):
    for row in M:
        print(f"{row[0]:>3} | {row[1]:>3} | {row[2]:>3} | {row[3]:>3}")
    print()

M = [
    [1, 2, 2, 1],
    [3, 7, 8, 7]
]

print("1. 초기 첨가행렬")
print_matrix(M)

M[1] = [M[1][j] - 3 * M[0][j] for j in range(4)]
print("2. R2 ← R2 - 3R1")
print_matrix(M)

M[0] = [M[0][j] - 2 * M[1][j] for j in range(4)]
print("3. R1 ← R1 - 2R2")
print_matrix(M)

for system in range(2):
    column = 2 + system
    x1 = M[0][column]
    x2 = M[1][column]
    print(f"시스템 {system + 1}의 해: x1 = {x1}, x2 = {x2}")
print_matrix(N)