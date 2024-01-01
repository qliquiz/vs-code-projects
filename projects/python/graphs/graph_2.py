def dfs(graph, vertex, visited):
    visited[vertex] = True
    for neighbor, connected in enumerate(graph[vertex]):
        if connected and not visited[neighbor]:
            dfs(graph, neighbor, visited)

def count_connected_components(graph):
    n = len(graph)
    visited = [False] * n

    count = 0

    for vertex in range(n):
        if not visited[vertex]:
            dfs(graph, vertex, visited)
            count += 1

    return count

n = int(input("Введите количество вершин: "))
graph = []

for _ in range(n):
    row = list(map(int, input().split()))
    graph.append(row)

result = count_connected_components(graph)

print(result)