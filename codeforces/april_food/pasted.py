n,m,t=map(int,raw_input().split())
s=[]
for i in range(n):s+=[raw_input()]
res=sum(sum(s[j][i]=='Y' for j in range(n))>=t for i in range(m))
print(res)#kitten
