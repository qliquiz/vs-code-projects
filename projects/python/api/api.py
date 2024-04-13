import requests
import pandas as pd


city = input('Введите город: ')
API_KEY = 'ee0f0048de4d7e61d0358e2eee241121'

response = requests.get('https://api.openweathermap.org/data/2.5/weather',
                        params={'q': city, 'appid': API_KEY, 'units': 'metric', 'lang': 'ru'})

json = response.json()

print(f'\nГород:  {city}\n\
        Погода: {json['weather'][0]['description']}\n\
        Температура: {json['main']['temp']} С\n\
        Скорость ветра: {json['wind']['speed']} м/с\n\
        Влажность: {json['main']['humidity']}%')

json_df = pd.DataFrame([json]) # переводим в датафрейм

print('\n', 'DataFrame', '\n', json_df)