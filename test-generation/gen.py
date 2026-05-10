import random
import sys
import os
import shutil
import numpy as np
import spec_random as sr

def get_min(st,dr,itter):
    ans=random.randint(st,dr)
    for _ in range(itter-1):
        ans=min(ans,random.randint(st,dr))
    return ans

def gen_test(file, n, tip):
    a=None
    if tip==0:
       a=sr.true_random(n)
    elif tip==1:
        a=sr.all_eq(n)
    elif tip==2:
        a=sr.decreasing_ish(n)
    elif tip==3:
        a=sr.increasing_ish(n)
    elif tip==4:
        a=sr.anti_merge(n)
    elif tip==5:
        a=sr.almost_eq(n)
    fout=open(file,"w")
    fout.write(str(n)+"\n")
    for x in a:
        fout.write(str(x)+" ")
    fout.write("\n")
    fout.close()

names=["pure-random", "all-equal", "decreasing-ish", "increasing-ish", "anti-merge", "almost-equal"]

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
                gen_test(unde+"/"+names[i%6]+"-"+str(i)+".in", 10000000, i%6)
        else:
            for i in range(int(sys.argv[2])):
                gen_test(unde+"/"+names[i%6]+"-"+str(i)+".in", 20000, i%6)
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