import time
import threading

def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

n = 10000

start_time = time.time()
factorial(n)
end_time = time.time()

print(f"Время выполнения программы: {end_time - start_time} секунд")

start_time = time.time()
thread = threading.Thread(target=factorial, args=(n,))
thread.start()
thread.join()
end_time = time.time()

print(f"Время выполнения программы с использованием потока: {end_time - start_time} секунд")

def factorial_partial(start, end):
    result = 1
    for i in range(start, end + 1):
        result *= i
    return result

mid = n // 2

thread1 = threading.Thread(target=factorial_partial, args=(1, mid))
thread2 = threading.Thread(target=factorial_partial, args=(mid + 1, n))

start_time1 = time.time()
thread1.start()
thread1.join()
end_time1 = time.time()

start_time2 = time.time()
thread2.start()
thread2.join()
end_time2 = time.time()

result = (end_time1 - start_time1) * (end_time2 - start_time2)
print(f"Время выполнения программы с двумя потоками: {result} секунд")
