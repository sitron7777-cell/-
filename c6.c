import numpy as np
import matplotlib.pyplot as plt

theta_deg = 60
theta = np.deg2rad(theta_deg)

A = np.array([
    [np.cos(theta), np.sin(theta)],
    [-np.sin(theta), np.cos(theta)]
])

P = np.array([
    [1, 1, 2, 2],
    [1, 2, 2, 1]
], dtype=float)

Q = A @ P

np.set_printoptions(precision=4, suppress=True)

print("회전행렬 A:")
print(A)

print("\n네 꼭짓점의 변환 결과:")
for i in range(P.shape[1]):
    print(
        f"P{i + 1}: ({P[0, i]:.4f}, {P[1, i]:.4f}) -> "
        f"({Q[0, i]:.4f}, {Q[1, i]:.4f})"
    )

before = np.linalg.norm(P, axis=0)
after = np.linalg.norm(Q, axis=0)
print("\n원점까지의 거리 보존:", np.allclose(before, after))

P_closed = np.column_stack((P, P[:, 0]))
Q_closed = np.column_stack((Q, Q[:, 0]))
fig, ax = plt.subplots(figsize=(7, 7))

ax.plot(
    P_closed[0], P_closed[1],
    "o-", color="royalblue", label="Original"
)
ax.plot(
    Q_closed[0], Q_closed[1],
    "o-", color="darkorange",
    label=f"Rotated {theta_deg} degrees clockwise"
)

for i in range(P.shape[1]):
    ax.annotate(
        f"P{i + 1}", P[:, i],
        xytext=(6, 8), textcoords="offset points"
    )
    ax.annotate(
        f"P'{i + 1}", Q[:, i],
        xytext=(5, -16), textcoords="offset points"
    )

ax.axhline(0, color="gray", linewidth=1)
ax.axvline(0, color="gray", linewidth=1)
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_title("Rotation about the origin")
ax.set_aspect("equal", adjustable="box")
ax.margins(0.2)
ax.grid(True, alpha=0.3)
ax.legend()
plt.tight_layout()
plt.show()