import random 

def gen_test(n,file,spec=0):
    fin=open(file+".in", "w")
    ffin=open(file+".ok","w")
    fin.write(str(n)+"\n")
    if spec==0:
        for i in range(n):
            u=random.randint(-10**9,10**9)
            fin.write(str(u)+" ")
    else:
        u=random.randint(-10**9,10**9)
        for i in range(n):
            fin.write(str(u)+" ")
    fin.write("\n")
    fin.close()
    ffin.close()

def main():
    big_n=10000000
    small_n=20000
    # for i in range(20):
    #     if i<15:
    #         gen_test(big_n,"./teste/big-test-"+str(i))
    #     else:
    #         gen_test(big_n,"./teste/big-test-"+str(i),1)
    for i in range(20):
        gen_test(small_n,"./teste-mici/small-test-"+str(i))
main()