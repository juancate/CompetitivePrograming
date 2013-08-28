import random, time

random.seed(time.time())
print 100
for i in xrange(100) :
    n = random.randint(1, 100)
    s = random.randint(0, n)
    p = random.randint(0, 10)
    msg = "%d %d %d" % (n, s, p)
    for j in xrange(n) :
        msg = msg + (" %d" % (random.randint(1, 30)))
    print msg
