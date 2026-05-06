import random
import sys
import os
import shutil
import numpy as np

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
            en=len(a)

            pp=(en-1)//2+1
            st=[]
            dr=[]
            if pp>2:
                s=set(np.random.choice(range(en-2),pp))
                for i in range(en-2):
                    if i in s:
                        st.append(a[i])
                    else:
                        dr.append(a[i])
            if random.randint(0,1)==0:
                st.append(a[-1])
                dr.append(a[-2]) 
            else:
                st.append(a[-2])
                dr.append(a[-1]) 
            st=anti_merge(st)
            dr=anti_merge(dr)
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
    fout.close()

names=["pure-random", "all-equal", "decreasing-ish", "increasing-ish", "anti-merge", "radix-random", "anti-quick"]

def main():
    if len(sys.argv)<4:
        print("Not enough arguments, should have <folder> <no. of tests> <big/small>")
        exit(0)
    # print(sys.argv)
    unde=sys.argv[1]
    if os.path.exists(unde):
        shutil.rmtree(unde)
    os.makedirs(unde)
    print("Generating tests...")
    if len(sys.argv)==4:
        if sys.argv[3]=="big":
            for i in range(int(sys.argv[2])):
                gen_test(unde+"/"+names[i%7]+"-"+str(i)+".in", 10000000, i%7)
        else:
            for i in range(int(sys.argv[2])):
                gen_test(unde+"/"+names[i%7]+"-"+str(i)+".in", 20000, i%7)
    else:
        care=list(map(int,sys.argv[4:]))
        if sys.argv[3]=="big":
            for i in range(int(sys.argv[2])):
                gen_test(unde+"/"+names[care[i%len(care)]]+"-"+str(i)+".in", 10000000, care[i%len(care)])
        else:
            for i in range(int(sys.argv[2])):
                gen_test(unde+"/"+names[care[i%len(care)]]+"-"+str(i)+".in", 20000, care[i%len(care)])
    print("Done!")
main()