if True :
	print(1)

if False :
	print(2)
print(3)


input_id = input("id: ")
if input_id == "egoing" :
	print("Welcome")
elif input_id == "ego" :
	print("r u egoing?")
else :
	print("who r u??")

input_id = input("id: ")
input_password = input("password: ")
id = "egoing"
password = "1234"
if input_id == id:
	if input_password == password:
		print("welcome")
	else :
		print("wrong password")
else :
	print("wrong id")