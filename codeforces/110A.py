x = int(input())

count = 0

while (x>0):
    dig = x%10
    if dig == 4 or dig == 7:
        count += 1
    x//=10

def islucky(x):
    if x == 0:
        return False
    
    while x>0:
        dig = x%10
        if dig != 4 and dig != 7:
            return False
        x//=10

    return True

if islucky(count):
    print("YES")
else:
    print("NO")