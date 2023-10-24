from math import comb

n = 20  # Grid size (n x n)
routes = comb(2 * n, n)
print(f"Number of routes in a {n}x{n} grid: {routes}")
