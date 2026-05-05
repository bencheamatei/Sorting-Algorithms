import random
import sys
import os

def get_min(st,dr,itter):
    ans=random.randint(st,dr)
    for _ in range(itter-1):
        ans=min(ans,random.randint(st,dr))
    return ans

def gen_test(file, n, tip):
    min_val=-2**31
    max_val=2**31-1
    fout=open(file, "w")
    fout.write(str(n)+"\n")
    if tip==0:
        # pure random aici
        for i in range(n):
            u=random.randint(min_val,max_val)
            fout.write(str(u)+" ")
    elif tip==1:
        # toate egale
        u=random.randint(min_val,max_val)
        for i in range(n):
            fout.write(str(u)+" ")
    elif tip==2:
        # un array sortat descrescator in care am dat swap la cateva elemente random 
        a=[]
        for i in range(n):
            u=random.randint(min_val,max_val)
            a.append(u)
        a.sort(reverse=True)

        for i in range(500):
            i=random.randint(0,n-1)
            j=random.randint(0,n-1)
            a[i],a[j]=a[j],a[i]

        for x in a:
            fout.write(str(x)+" ")
    elif tip==3:
        # un array sortat crescator in care sunt swapuite cateve elemente
        a=[]
        for i in range(n):
            u=random.randint(min_val,max_val)
            a.append(u)
        a.sort()

        for i in range(500):
            i=random.randint(0,n-1)
            j=random.randint(0,n-1)
            a[i],a[j]=a[j],a[i]
        
        for x in a:
            fout.write(str(x)+" ")
    elif tip==4:
        a=[]
        for i in range(n):
            u=random.randint(min_val,max_val)
            a.append(u)
        
        def anti_merge(a):
            if len(a)<2:
                return a
            st=anti_merge(a[::2])
            dr=anti_merge(a[1::2])
            st.extend(dr)
            return st
        
        a=anti_merge(a)
        for x in a:
            fout.write(str(x)+" ")
    elif tip==5:
        for i in range(n):
            ce=random.randint(1,4)
            u=0
            if ce==1:
               u=random.randint(0,2048)
            elif ce==2:
                u=random.randint(-2048,0)
            elif ce==3:
                u=random.randint(max_val//2,max_val)
            else:
                u=random.randint(min_val,min_val//2)
            fout.write(str(u)+" ") 
    else:
        # cum la quick nu e determinist, imi e oricum cam imposibil sa pic legit
        # deci at best trebuie sa-l pun sa faca cat mai multe interschimbari
        # si creca anti quick e ceva gen cand am radical valori distincte puse aleator
        unde=int(n**0.5)
        a=random.sample(range(min_val,max_val),unde)
        a.sort(reverse=True)
        b=[]
        for i in range(unde):   
            if i!=unde-1:
                for _ in range(unde):
                    b.append(a[i])
            else:
                p=n-len(b)
                for _ in range(p):
                    b.append(a[i])
        # random.shuffle(b)
        for x in b:
            fout.write(str(x)+" ")
    fout.write("\n")

def main():
    for i in range(10):
        gen_test("./rtests/test-"+str(i)+".in", 10000000, 0)
main()