#include <iostream>
#include "graph.h"


int main()
{
    Graph graph;

    return 0;
}


typedef std::set<Node*>::const_iterator node_iterator;

void Graph::addNode(Node* node)
{
    nodes.insert(node);
    // Add also to all neighbours list
    for (std::set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
        (*it)->addNeighbour(node);
}

void Graph::removeNode(Node* node)
{
    nodes.erase(node);
    // Remove also from all neighbours list
    for (std::set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
        (*it)->removeNeighbour(node);
}

void Graph::addEdge(Node* begin, Node* end)
{
    if (nodes.find(begin) == nodes.end())
        return;
    if (nodes.find(end) == nodes.end())
        return;

    begin->addNeighbour(end);
    end->addNeighbour(begin);
}

void Graph::removeEdge(Node *begin, Node *end)
{
    if (nodes.find(begin) == nodes.end())
        return;
    if (nodes.find(end) == nodes.end())
        return;

    begin->removeNeighbour(end);
    end->removeNeighbour(begin);
}

void Node::addNeighbour(Node *neighbour)
{
    neighbours.insert(neighbour);
    for (std::set<Node*>::iterator it = neighbours.begin(); it != neighbours.end(); it++)
        neighbour->neighbours.insert(*it);
}

void Node::removeNeighbour(Node *neighbour)
{
    neighbours.erase(neighbour);
    for (std::set<Node*>::iterator it = neighbours.begin(); it != neighbours.end(); it++)
        neighbour->neighbours.erase(*it);
}

bool BFS::connected(Node* begin, Node* end)
{
    std::set<Node*> visited;
    std::queue<Node*> nodes;
    nodes.push(begin);
    
    while (!nodes.empty())
    {
        Node* next = nodes.front();
        nodes.pop();

        if (end == next)
            return true;

        visited.insert(next);

        for (node_iterator it = next->nb_begin(); it != next->nb_end(); it++)
            if (visited.find(*it) == visited.end())
                nodes.push(*it);
    }

    return false;
}

bool DFS::connected(Node* begin, Node* end)
{
    visited.clear();

    return connected(begin, end, 0);
}

bool DFS::connected(Node* begin, Node* end, int depth)
{
    if (begin == end)
        return true;

    visited.insert(begin);

    for (node_iterator it = begin->nb_begin(); it != begin->nb_end(); it++)
    {
        if (visited.find(*it) == visited.end())
            if (connected(*it, end, depth + 1))
                return true;
    }

    return false;
}

MarkedNode PriorityQueue::pop()
{
    MarkedNode mn = nodes.back(); 
    nodes.pop_back();

    return mn;
}

void PriorityQueue::push(Node* node, int mark, Node* prev)
{
    std::vector<MarkedNode>::iterator it = nodes.begin();
    MarkedNode mn(node, mark, prev);
    
    // From higher to lower
    while (it != nodes.end() && mark < it->mark) it++;

    if (it == nodes.end()) nodes.push_back(mn);
    else nodes.insert(it, mn);
}

Way Dijkstra::shortestWay(Node* begin, Node* end)
{
    std::map<Node*, MarkedNode> visited;
    PriorityQueue nodes;

    nodes.push(begin, 0, 0);

    while (!nodes.empty()) {
        MarkedNode next = nodes.pop();
        visited[next.node] = next;

        if (end==next.node)
            return unroll(visited, begin, end);
            
        for (node_iterator it = next.node->nb_begin(); it != next.node->nb_end(); it++)
        {
            int weight = (*it)->getWeight(next.node) + next.mark;
            
            if (visited.find(*it)==visited.end())
                nodes.push(*it, weight, next.node);
        }
    }
    
    return Way();
}

static Way unroll(std::map<Node*, MarkedNode> visited, Node* begin, Node* curr)
{
    Way way;
    way.length = visited[curr].mark;
    
    while (curr != begin)
    {
        way.nodes.push_back(curr);
        curr = visited[curr].prev;
    }
    
    way.nodes.push_back(begin);

    return way;
}