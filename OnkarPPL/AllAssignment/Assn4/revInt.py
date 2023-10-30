def reverse(num):
    rev=0
    while(num>0):
        n=num%10
        rev=(rev*10)+n
        num=num//10
    return rev
print(f'Rev: {reverse(56)}')
