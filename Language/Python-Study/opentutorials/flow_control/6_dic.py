person = {'name': 'egoing', 'address': 'seoul', 'interest': 'Web'}

print(person['name'])

for key in person:
	print(key, person[key])

persons = [
    {'name':'egoing', 'address':'Seoul', 'interest':'Web'},
    {'name':'basta', 'address':'Seoul', 'interest':'IOT'},
    {'name':'blackdew', 'address':'Tongyeong', 'interest':'ML'}
]

print('==== persons ====')
for person in persons:
    for key in person:
        print(key, ':', person[key])
    print('-----------------')