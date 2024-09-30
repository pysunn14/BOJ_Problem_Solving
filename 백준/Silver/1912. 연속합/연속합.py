n = int(input())

a = list(map(int, input().split()))

d = [0]*n
d[0] = a[0]

# d[i] = i를 포함해서 연속합을 제작했을때, 최대값을 의미


for i in range(1,n):

    d[i] = a[i]
    d[i] = max(d[i-1] + d[i], d[i])

print(max(d))