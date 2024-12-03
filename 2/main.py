import math

def test_it(numbers, j, inc, startdiff, increasing):
    if j == 0 or inc == 0:
        return inc
   
    diff = startdiff
    if inc == 1:
        diff += 1
   
    if j - diff < 0:
        return inc
   
    if math.fabs(numbers[j] - numbers[j-diff]) < 1 or \
            math.fabs(numbers[j] - numbers[j-diff]) > 3:
        return inc - 1
    if increasing:
        if numbers[j] < numbers[j-diff]:
            return inc - 1
        return inc
   
    else:
        if numbers[j] > numbers[j-diff]:
            return inc - 1
        return inc
   
   
def test_array(numbers, startval, startdiff):
    inc = startval
    dec = startval
   
    for j in range(len(numbers)):
        inc = test_it(numbers, j, inc, startdiff, True)
        dec = test_it(numbers, j, dec, startdiff, False)
   
    return inc > 0 or dec > 0


safe = 0
for i in range(1):
    line = input()
    numbers = list(map(int, line.split()))
   
    if test_array(numbers, 2, 1) or test_array(numbers[1:], 1, 0):
        safe += 1
        print(i)
   
print(safe)