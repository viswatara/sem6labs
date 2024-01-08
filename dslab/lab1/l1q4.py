a= int(input('Enter a:'))
b= int(input('Enter b:'))
c= int(input('Enter c:'))

if a>b:
	if a>c:
		print(" a is largest",a)
	else:
		print("c is largest",c)
elif b>c:
	if b>a:
		print("b is largest",b)
	else:
		print("a is largest",a)
elif c>a:
	if c>b:
		print(" c is largest",c)
	else:
		print("b is largest",b)


