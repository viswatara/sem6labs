tupl1e=(12, 7, 38, 56, 78 )
res=[]
for x in tupl1e:
	if x%2==0:
		res.append(x)

tup=tuple(res)
print(tup)