import time


def fac(n):
    result = 1

    for i in range(1, n + 1):
        result *= i
    
    return result

start_time_1 = time.time()
print(fac(101))
end_time_1 = time.time()
print(end_time_1 - start_time_1)