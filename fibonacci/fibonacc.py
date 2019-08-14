 # https://www.bilibili.com/video/av32330574?from=search&seid=13428083893378930898

import time

def fib_recursion(n):
    if n==1 or n==2:
        result = 1
    else:
        result = fib_recursion(n - 1) + fib_recursion(n - 2)
    return result


def fib_memoize(n, memo):

    if n==1 or n==2 :
        result = 1
    else:
        if memo is None:
            memo = [None] * (n+1)

        if memo[n] != None:
            return memo[n]
        result = fib_memoize(n - 1, memo) + fib_memoize(n - 2, memo)
        memo[n] = result

    return result

def fib_bottom_up(n) :
     if n==1 or n==2:
         return 1
     bottom_up = [None] * (n+1)
     bottom_up[1] = bottom_up[2] = 1

     for i in range(3, n+1) :
         bottom_up[i] = bottom_up[i-1] + bottom_up[i-2]

     return bottom_up[n]

def fib_best(n):
     if n==1 or n==2:
         return 1

     fibn_2 = 1
     fibn_1 = 1
     fibn_0 = 0

     for i in range(3, n+1) :
         fibn_0 = fibn_1 + fibn_2
         fibn_2 = fibn_1
         fibn_1 = fibn_0

     return fibn_0

if __name__ == '__main__' :

    begintime = time.time()
    fib35= fib_recursion(35)
    endtime = time.time()

    diff = endtime - begintime

    print(''' -------------------------------------------------
    fib_recursion(35) value=%d, time cost=%.2fs''' %(fib35, diff))

    begintime = time.time()
    fib35= fib_memoize(35, None)
    endtime = time.time()

    diff = endtime - begintime

    print(''' -------------------------------------------------
    fib_memoize(35) value=%d, time cost=%.2fs''' %(fib35, diff))

    begintime = time.time()
    fib35= fib_bottom_up(35)
    endtime = time.time()

    diff = endtime - begintime

    print(''' -------------------------------------------------
    fib_botom_up(35) value=%d, time cost=%.2fs''' %(fib35, diff))


    begintime = time.time()
    fib35= fib_best(35)
    endtime = time.time()

    diff = endtime - begintime

    print(''' -------------------------------------------------
    fib_best(35) value=%d, time cost=%.2fs''' %(fib35, diff))







