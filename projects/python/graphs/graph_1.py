from collections import deque

def bfs(graph, enter, exit):
    is_visited = set()
    queue = deque([enter])

    while queue:
        vert = queue.popleft()
        if vert in is_visited:
            continue

        is_visited.add(vert)

        if vert != enter and graph[enter][vert] > exit:
            return vert

        for neighbor, weight in enumerate(graph[vert]):
            if weight > 0 and neighbor not in is_visited:
                queue.append(neighbor)

    return None

graph = [
    [0, 0, 0, 0, 3],
    [0, 0, 1, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 1, 0, 0],
    [3, 0, 0, 0, 0]
]

exit_vertex = bfs(graph, 0, 3)

if exit_vertex is not None:
    print(f"Выход из лабиринта найден. Вершины, соединенные ребром-выходом: 0 -> {exit_vertex}")
else:
    print("Выход из лабиринта не найден.")