N, W, H, L = map(int, input().split())

WW = W // L
HH = H // L

print(min(WW * HH, N))