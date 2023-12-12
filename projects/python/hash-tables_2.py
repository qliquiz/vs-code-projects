def rabin_karp(pattern, text):
    # Инициализируем константы для хэш-функции
    prime = 101  # Простое число для вычисления хэша
    modulo = 10**9 + 9  # Большое число для вычисления хэша

    len_pattern = len(pattern)
    len_text = len(text)

    pattern_hash = 0
    text_hash = 0
    base = 1

    # Вычисляем хэш для образца и первой подстроки текста
    for i in range(len_pattern):
        pattern_hash = (pattern_hash + ord(pattern[i]) * base) % modulo
        text_hash = (text_hash + ord(text[i]) * base) % modulo
        if i != len_pattern - 1:
            base = (base * prime) % modulo

    result = []

    # Поиск образца в тексте
    for i in range(len_text - len_pattern + 1):
        if pattern_hash == text_hash:
            # Проверяем совпадение строк
            if pattern == text[i:i+len_pattern]:
                result.append(i)

        # Обновляем хэш для следующей подстроки
        if i != len_text - len_pattern:
            remove_char_hash = ord(text[i]) * base % modulo
            add_char_hash = ord(text[i + len_pattern]) % modulo
            text_hash = ((text_hash - remove_char_hash + modulo) * prime + add_char_hash) % modulo

    return result

# Пример использования
pattern = input("Паттерн: ")
text = input("Текст: ")

result = rabin_karp(pattern, text)

print(result)
