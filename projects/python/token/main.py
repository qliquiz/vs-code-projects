from my_token import access_token as token
import requests
import pandas as pd
import time


def search_query(q, sorting=0): # Если не передать параметр sorting, то по умолчанию он будет равен 0
    # Параметры sort
    # 0 — сортировать по умолчанию (аналогично результатам поиска в полной версии сайта);
    # 6 - сортировать по количеству пользователей
    params = {
        'q': q,                # Поисковой запрос
        'access_token': token,
        'v':'5.89',
        'sort': sorting,
        'is_closed': 0,
        'count': 100           # Просим отдать нам 100 записей, это максимум для обычного запроса
        }
    req = requests.get('https://api.vk.com/method/groups.search', params).json()

    return req['response']['items']


java_communities = search_query('java', 6)
group_df = pd.DataFrame(java_communities)
# print(java_communities)
# print(group_df)


post_counts = []  # В этот список будем последовательно записывать информацию о количестве записей в каждой из групп

for group_id in group_df['id']:

    url_data = 'https://api.vk.com/method/wall.get'

    params = {'access_token': token,
            'v':'5.89',
            'owner_id': '-' + str(group_id),   # Таким интересным способом согласно документации передается ID группы
            'filter': 'all'  # Берем все посты
            }
    
    req = requests.get(url_data, params)
    res = req.json()
    
    try: # пробуем выполнить код
        count = res['response']['count'] # присваиваем значение ключа 'count' из словаря 'response', полученным в ответе на запрос
        post_counts.append(count) # добавляем значение в список с количеством записей 
    except: # если вылетает ошибка, делаем то, что в except — присваиваем значение ноль
        post_counts.append(0)
    
    time.sleep(0.5) # Ограничиваем частоту запросов до одного запроса в полсекунды

group_df = group_df[['id', 'name', 'screen_name']]
group_df['posts'] = post_counts
group_df = group_df.loc[group_df['posts'] > 300]
# print(group_df)


member_counts = []  # В этот список будем последовательно записывать информацию о количестве участников в каждой из групп
descriptions = []  # В этот список будем последовательно записывать описание каждой из групп

for group_id in group_df['id']:

    url_data = 'https://api.vk.com/method/groups.getById'

    params = {
        'access_token': token,
        'v':'5.199',
        'group_id': group_id,
        'fields': 'members_count, description' # здесь мы передали дополнительные параметры групп
    }
    
    req = requests.get(url_data, params)
    res = req.json()['response']['groups'][0]

    try: # пробуем выполнить код
        count = res['members_count'] # присваиваем значение ключа 'members_count'
        description = res['description'] # присваиваем значение ключа 'description'
        member_counts.append(count) # добавляем значение в список с количеством участников
        descriptions.append(description) # добавляем значение в список с описанием
    except: # если вылетает ошибка, делаем то, что в except — присваиваем значение ноль
        member_counts.append(0)
        descriptions.append(0)
    
    time.sleep(0.5) # Ограничиваем частоту запросов до одного запроса в полсекунды

group_df['members'] = member_counts
group_df['description'] = descriptions
group_df = group_df.loc[group_df['members'] > 5000]
print(group_df)