#! /bin/python
import random 
f1 = open("test.in", "w")
f2= open("test.out", "w")
i = 1
while i < 1000:
	number1 = random.randint(0, 122112222222222222222222222222222222222222)
	number2 = random.randint(0, 122112222222222222222222222222222222222222)
	
	number3 = number1 / number2
	
	f1.write(str(number1)+'\n');
	f1.write(str(number2)+'\n');
	f2.write(str(number3)+'\n');
	i += 1
f1.close()
f2.close()

