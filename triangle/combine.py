import sys
import os

DIR = os.path.dirname(os.path.realpath(__file__))

with open(os.path.join(DIR, 'state.txt'), 'r') as f:
    n = int(f.readline())
    primes = []
    for line in f: 
        primes.append(int(line))

seq = {}
mn = n+1
for prime in primes:
    seq[prime] = []
    try:
        with open(os.path.join(DIR, 'triangle_%d.txt' % prime), 'r') as f:
            for line in f:
                seq[prime].append(map(int, line.split()))
    except:
        pass
    mn = min(mn, len(seq[prime]))

for i in range(mn):
    mn2 = min( len(seq[p][i]) for p in primes )
    row = []
    for j in range(mn2):
        ans = 0
        mod = 1

        need = 1
        for k in range(1,i+1):
            need *= k

        for p in primes:
            q = seq[p][i][j]
            k = (q-ans) * pow(mod, p-2, p) % p
            ans += k * mod
            mod *= p

        assert mod > need
        row.append(ans)

    print(' '.join(map(str, row)))

