def h1(k):
    return (2*k+3) % 13

def h2(k):
    return 1 + k % 11

def h(k,i):
    return (h1(k) + i * h2(k)) % 11

print(h(3,0))
print(h(14,1))
print(h(15,2))
print(h(68,3))
print(h(92,4))

