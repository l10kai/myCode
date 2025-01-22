from datetime import date, timedelta


def is_prime(n):
    if n < 2:
        return False
    if n % 2 == 0 and n != 2:
        return False
    r = int(n**0.5)
    for i in range(3, r + 1, 2):
        if n % i == 0:
            return False
    return True


start = date(2005, 1, 1)
end = date(2005, 12, 30)
delta = timedelta(days=1)

total_days = 0
prime_days = 0

current = start
while current <= end:
    date_int = int(current.strftime("%Y%m%d"))
    total_days += 1
    if is_prime(date_int):
        prime_days += 1
        print(current)
    current += delta

probability = prime_days / total_days
print(f"近100年生日为质数的概率: {probability:.8f}")
