import random
import math

def true_random(n,min_val=-2**31,max_val=2**31-1):
    a=[]
    for i in range(n):
        a.append(random.randint(min_val,max_val))
    return a

def increasing_ish(n,min_val=-2**31,max_val=2**31-1):
    a=true_random(n,min_val,max_val)
    a.sort()
    for i in range(min(500,int(math.sqrt(n)))):
        p1=random.randint(0,n-1)
        p2=random.randint(0,n-1)
        a[p1],a[p2]=a[p2],a[p1]
    return a

def decreasing_ish(n,min_val=-2**31,max_val=2**31-1):
    a=true_random(n,min_val,max_val)
    a.sort(reverse=True)
    for i in range(min(500,int(math.sqrt(n)))):
        p1=random.randint(0,n-1)
        p2=random.randint(0,n-1)
        a[p1],a[p2]=a[p2],a[p1]
    return a 

def anti_merge(n,min_val=-2**31,max_val=2**31-1):
    a=sorted(true_random(n,min_val,max_val))
    def merge(a):
        if len(a)<=1:
            return a 
        st=a[::2]
        dr=a[1::2]
        return merge(st)+merge(dr)
    return merge(a)

def all_eq(n,min_val=-2**31,max_val=2**31-1):
    a=[random.randint(min_val,max_val)]*n 
    return a

def almost_eq(n,min_val=-2**31+1000,max_val=2**31-1-1000):
    base=random.randint(min_val,max_val)
    a=[]
    for i in range(n):  
        offset=random.randint(-1000,1000)
        a.append(base+offset)
    return a 

def sawtooth(n,min_val=-2**31,max_val=2**31-1):
    a=[]
    cnt=max(1,int(math.sqrt(n)))
    for i in range(cnt):
        if i!=cnt-1:
            b=sorted(true_random(cnt,min_val,max_val))
            a.extend(b)
        else:
            b=sorted(true_random(n-len(a),min_val,max_val))
            a.extend(b)
    return a

def few_distinct(n,min_val=-2**31,max_val=2**31-1,cnt=10):
    b=true_random(cnt,min_val,max_val)
    a=[]
    for _ in range(n):
        a.append(b[random.randint(0,len(b)-1)])
    return a

def alternating(n,min_val=-2**31,max_val=2**31-1):
    a=[]
    for i in range(n):
        if i&1:
            a.append(random.randint(0,max_val))
        else:
            a.append(random.randint(min_val,-1))
    return a
