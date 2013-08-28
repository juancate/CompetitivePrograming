import random, time

random.seed(time.time())

print 50
for cases in xrange(50):
    N = random.randint(1, 1000)
    print N
    for clase in xrange(N):
        Mi = random.randint(1, 10)
        print Mi,
        for child in xrange(Mi):
            c = random.randint(1, Mi)
            while c == clase:
                c = random.randint(1, Mi)
            print c,
        print ''

