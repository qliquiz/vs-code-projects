import os
import threading

def process_file(file, thread_name):
    with open(file, 'r') as f:
        line_count = len(f.readlines())
        print(f"Поток {thread_name} прочитал файл {file} и насчитал {line_count} строк.")

def threads(directory):
    files = [os.path.join(directory, file) for file in os.listdir(directory) if file.endswith('.txt')]

    threads = []
    for file in files:
        thread = threading.Thread(target=process_file, args=(file, file))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

directory = "projects\python"
threads(directory)
