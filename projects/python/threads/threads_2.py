import requests
import threading
import queue

API_KEY = "ee0f0048de4d7e61d0358e2eee241121"

cities = ["Irkutsk", "Moscow", "London", "New York"]
threads = []
results = []

result_queue = queue.Queue()

def get_weather_data(city, API_KEY, result_queue):
    response = requests.get('https://api.openweathermap.org/data/2.5/weather', params={'q': city, 'appid': API_KEY, 'units': 'metric', 'lang': 'ru'})
    result_queue.put(response.json())

for city in cities:
    thread = threading.Thread(target=get_weather_data, args=(city, API_KEY, result_queue))
    threads.append(thread)
    thread.start()
    thread.join()

while not result_queue.empty():
    result = result_queue.get()
    results.append(result)

for i, result in enumerate(results):
    print(f"Температура в городе {cities[i]}: {result['main']['temp']} С")
