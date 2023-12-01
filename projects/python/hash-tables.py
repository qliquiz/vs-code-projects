def rabin_karp_matcher(pattern, text):
    n = len(text)
    m = len(pattern)
    prime = 101  # простое число

    def poly_hash(s):
        h = 0
        for c in s:
            h = (h * prime + ord(c)) % n
        return h

    pattern_hash = poly_hash(pattern)
    h = [0] * (n - m + 1)
    t = poly_hash(text[:m])
    h[0] = t

    x = 1
    for _ in range(m - 1):
        x = (x * prime) % n

    for s in range(1, n - m + 1):
        t = (t + n - x * ord(text[s - 1]) % n) % n
        t = (t * prime + ord(text[s + m - 1])) % n
        h[s] = t

    matches = [i for i in range(n - m + 1) if h[i] == pattern_hash]
    return matches


# Чтение входных данных
pattern = input()
text = input()

# Поиск вхождений с использованием алгоритма Рабина-Карпа
matches = rabin_karp_matcher(pattern, text)

# Вывод результата
print(matches)
