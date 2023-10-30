def isValidDate(day,month,year):
    if year<=0:
        return False
    if month<1 and month>12:
        return False
    max_days = [0,31,28,31,30,31,30,31,31,30,31,30,31]
    if(year%4==0 and year%100!=0) or (year%400==0):
        max_days[2]=29
    if 1<=day<=max_days[month]:
        return True
    return False

print(isValidDate(29,2,2003))