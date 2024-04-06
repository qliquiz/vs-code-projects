import geocoder
import requests
import pandas as pd
import json


#===================================== Sunrise Sunset =====================================#
city = geocoder.arcgis('Иркутск')

crdnt = [city.json['lat'], city.json['lng']]

URL = 'https://api.sunrise-sunset.org/json'

params = {
    'lat': crdnt[0], # берем первый элемент из списка
    'lng': crdnt[1], # берем второй элемент из списка
    'date': '2024-06-04'
}

sun_r_s = requests.get(URL, params=params) # requests за нас формирует конечный URL из параметров
sun_r_s_dict = sun_r_s.json() # переводим в json
sun_r_s_df = pd.DataFrame([sun_r_s.json()['results']]) # переводим в датафрейм

print(sun_r_s_dict)
print(sun_r_s_df)

#===================================== World Bank =====================================#

INDICATORS_URL = "http://api.worldbank.org/v2/indicator"

indicators = requests.get(url=INDICATORS_URL, # ссылка на API
                            params={'format':'json'}) # параметры запроса

indicators_data = json.loads(indicators.content)

# print(indicators_data)

indicators = requests.get(url=INDICATORS_URL, # ссылка на API
                            params={'format':'json','per_page':20083}) # параметры запроса
# вместо числа 20083 можно передать ссылку на это же значение, например вот так:  indicators_data[0]['total']

indicators.connection.close()