def gcd(num1,num2):
    if num1<num2:
        min=num1
    else:
        min = num2
    while(min>0):
        if(num1%min==0 and num2%min==0):
            return min
        else:
            min-=1

def lcm(num1,num2):
    if(num1>num2):
        max=num1
    else:
        max=num2
    while(1):
        if(max%num1==0 and max%num2==0):
            return max
        else:
            max+=1
print(f'gcd: {gcd(8,16)}')
print(f'lcm: {lcm(8,16)}')