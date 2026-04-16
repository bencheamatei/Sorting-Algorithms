import random 

def gen_test(n,file):
    fin=open(file+".in", "w")
    ffin=open(file+".ok","w")
    fin.write(str(n)+"\n")
    for i in range(n):
        u=random.randint(0,10**9)
        fin.write(str(u)+" ")
    fin.write("\n")
    fin.close()
    ffin.close()

def main():
    big_n=10000000
    small_n=20000
    for i in range(20):
        gen_test(big_n,"./teste/big-test-"+str(i))
    for i in range(10):
        gen_test(small_n,"./teste/small-test-"+str(i))

main()