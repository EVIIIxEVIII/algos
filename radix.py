import math

def getNthDigit(number, n):
    number = abs(number)
    length = len(str(number))
    if n < 0 or n >= length:
        return 0

    return (number // (10 ** n)) % 10


def countSort(array, digit):
    sortedByDigit = [[] for _ in range(10)]

    for num in array:
        sortedByDigit[getNthDigit(num, digit)].append(num)

    return [num for row in sortedByDigit for num in row]

def radix(array):
    maxNum = max(array)
    digitsCount = math.ceil(math.log10(maxNum))

    res = array[:]
    for i in range(digitsCount):
        res = countSort(res, i)
        print(res)

    return res


res = radix([170, 45, 75, 90, 802, 24, 2, 66])
print(res)
