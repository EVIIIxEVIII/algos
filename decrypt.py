# problem 4.12
from math import sqrt
from decimal import Decimal

def isPrime(num):
    prime_flag = 0

    if(num > 1):
        for i in range(2, int(sqrt(num)) + 1):
            if (num % i == 0):
                prime_flag = 1
                break
        if (prime_flag == 0):
            return True
        else:
            return False
    else:
        return False

def sum_of_digits(n):
  return sum(int(digit) for digit in str(n))

res = 0
prev = 0

for i in range(100_000, 1_000_001):
    if isPrime(i):
        if sum_of_digits(i) == 38:
            prev = res
            res = max(i, res)


print(prev)
print(res)

result = str(11407962388511346587579855268553606923614846491959636902329539196087 // prev)
result = "0" + result
formatted_result = " ".join(result[i:i+2] for i in range(0, len(result), 2))

print(result)
print(formatted_result)
