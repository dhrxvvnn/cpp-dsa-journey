name = input()

nameset = set(name)
l = len(nameset)

if l%2 == 1:
    print("IGNORE HIM!")
else:
    print("CHAT WITH HER!")