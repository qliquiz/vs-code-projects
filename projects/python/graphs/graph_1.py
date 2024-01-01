from collections import deque

def bfs(graph, start, exit_threshold):
    visited = set()
    queue = deque([start])

    while queue:
        current_vertex = queue.popleft()
        if current_vertex in visited:
            continue

        visited.add(current_vertex)

        if current_vertex != start and graph[start][current_vertex] > exit_threshold:
            return current_vertex

        for neighbor, weight in enumerate(graph[current_vertex]):
            if weight > 0 and neighbor not in visited:
                queue.append(neighbor)

    return None

graph_weights = [
    [0, 0, 0, 0, 3],
    [0, 0, 1, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 1, 0, 0],
    [3, 0, 0, 0, 0]
]

# Номер вершины, с которой нужно начинать обход
start_vertex = 0

# Вес, обозначающий выход из "лабиринта"
exit_weight = 3

exit_vertex = bfs(graph_weights, start_vertex, exit_weight)

if exit_vertex is not None:
    print(f"Выход из лабиринта найден. Вершины, соединенные ребром-выходом: {start_vertex} -> {exit_vertex}")
else:
    print("Выход из лабиринта не найден.")

""" from collections import deque

def bfs(graph, start, exit_weight):
    num_vertices = len(graph)
    visited = [False] * num_vertices
    queue = deque([start])
    exit_vertices = []

    while queue:
        v = queue.popleft()
        visited[v] = True
        for i in range(num_vertices):
            if graph[v][i] > 0 and not visited[i]:
                if graph[v][i] == exit_weight:
                    exit_vertices.append(i)
                else:
                    queue.append(i)
                visited[i] = True
    
    return exit_vertices

# Пример матрицы весов графа
graph_weights = [
    [0, 1, 0, 0, 3],
    [1, 0, 1, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 1, 0, 0],
    [3, 0, 0, 0, 0]
]

# Номер вершины, с которой нужно начинать обход
start_vertex = 0

# Вес, обозначающий выход из "лабиринта"
exit_weight = 3

# Выполнение обхода в ширину
exit_vertices = bfs(graph_weights, start_vertex, exit_weight)
print("Вершины, соединенные ребром-выходом из лабиринта:", exit_vertices) """
