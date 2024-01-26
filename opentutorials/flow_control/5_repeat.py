nums = [1, 2, 3, 4]

for num in nums:
	print(num)

persons = [
    ['egoing', 'Seoul', 'Web'],
    ['basta', 'Seoul', 'IOT'],
    ['blackdew', 'Tongyeong', 'ML'],
]

for person in persons:
	print(person[0] + ", " + person[1] + ", " + person[2])

name, address, interest = ['egoing', 'Seoul', 'Web']
print(name, address, interest)

for name, address, interest in persons:
    print(name+','+address+','+interest)
