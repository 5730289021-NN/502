A = [1,2,3]
B = [1,2,3,4,5,6,7,8,9]
C = []
for i in range(len(A)):
    q = B[(3*(i))+0]
    w = B[(3*(i))+1]
    e = B[(3*(i))+2]
    C.append([q,w,e])
    print(i)
print(C)
