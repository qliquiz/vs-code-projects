def dfs(graph, vert, is_visited):
    is_visited[vert] = True
    for neighbor, is_connected in enumerate(graph[vert]):
        if is_connected and not is_visited[neighbor]:
            dfs(graph, neighbor, is_visited)

def ccc(graph):
    length = len(graph)
    cnt = 0
    is_visited = [False] * length

    for vert in range(length):
        if not is_visited[vert]:
            dfs(graph, vert, is_visited)
            cnt += 1

    return cnt

n = int(input("Введите количество вершин: "))
graph = []

for _ in range(n):
    row = list(map(int, input().split()))
    graph.append(row)

print(ccc(graph))