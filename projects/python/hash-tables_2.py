D = 256
Q = 101

def search_rabin_karp(pattern, text):
    M = len(pattern)
    N = len(text)
    p = 0  # хеш для pattern
    t = 0  # хеш для text
    h = pow(D, M - 1, Q)
    result = []
    
    for i in range(M):
        p = (D * p + ord(pattern[i])) % Q
        t = (D * t + ord(text[i])) % Q

    for i in range(N-M+1):
        if p == t:
            match = True
            for j in range(M):
                if pattern[j] != text[i+j]:
                    match = False
                    break
            if match:
                result.append(i)
        if i < N-M:
            t = (D * (t - ord(text[i]) * h) + ord(text[i + M])) % Q
            if t < 0:
                t = t + Q

    print(result)


Pattern = "aba"
Text = "abacaba"
search_rabin_karp(Pattern, Text)
