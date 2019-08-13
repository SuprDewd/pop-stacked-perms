import sys
import os

DIR = os.path.dirname(os.path.realpath(__file__))

with open(os.path.join(DIR, 'state.txt'), 'r') as f:
    n = int(f.readline())
    primes = []
    for line in f: 
        primes.append(int(line))

seq = {}
mn = n
for prime in primes:
    seq[prime] = []
    try:
        with open(os.path.join(DIR, 'sequence_%d.txt' % prime), 'r') as f:
            for line in f:
                seq[prime].append(int(line))
    except:
        pass
    mn = min(mn, len(seq[prime]))

for i in range(1, mn+1):
    ans = 0
    mod = 1

    need = 1
    for j in range(1,i+1):
        need *= j

    for p in primes:
        q = seq[p][i-1]
        k = (q-ans) * pow(mod, p-2, p) % p
        ans += k * mod
        mod *= p

    assert mod > need
    print('%d %d' % (i, ans))

