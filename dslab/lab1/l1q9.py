l=[11, -21, -2, 45, 66, -93]
pos=neg=0
for x in l:
	if x>0:
		pos=pos+1
	else:
		neg=neg+1
print("Number of positives are :",pos)
print("Number of negativetives are :",neg)