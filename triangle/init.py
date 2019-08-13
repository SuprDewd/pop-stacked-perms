import sys
import os

DIR = os.path.dirname(os.path.realpath(__file__))

if len(sys.argv) != 2:
    sys.stderr.write('usage: %s max-n\n' % sys.argv[0])
    sys.exit(1)

n = int(sys.argv[1])

path = os.path.join(DIR, 'triangle_mod.cpp')
with open(path, 'r') as f:
    source = f.read()

source = '\n'.join( '#define MAXN %d' % n if line.startswith('#define MAXN') else line for line in source.split('\n') )
with open(path, 'w') as f:
    f.write(source)

os.system('make')

need = 1
for i in range(2,n+1):
    need *= i

have = 1
primes = []
cur = 1000000000
while have <= need:
    assert cur >= 2

    at = 2
    prime = True
    while at*at <= cur:
        if cur % at == 0:
            prime = False
            break
        at += 1
    if prime:
        have *= cur
        primes.append(cur)
    cur -= 1

with open(os.path.join(DIR, 'state.txt'), 'w') as f:
    f.write('%d\n' % n)
    for prime in primes:
        f.write('%d\n' % prime)

with open(os.path.join(DIR, 'primes.sh'), 'w') as f:
    f.write('primes=(%s)\n' % ' '.join(map(str,primes)))

path = os.path.join(DIR, 'job.sh')
with open(path, 'r') as f:
    job = f.read()

job = '\n'.join( '#SBATCH --array=0-%d' % (len(primes)-1) if line.startswith('#SBATCH --array=') else line for line in job.split('\n') )
with open(path, 'w') as f:
    f.write(job)

