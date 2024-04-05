#include <iostream>
#include <queue>
#include <set>
#include <map>


class Node {
    typedef std::set<Node*>::const_iterator node_iterator;
    std::string name;
    std::set<Node*> neighbours;

    void addNeighbour(Node* neighbour);
    void removeNeighbour(Node* neighbour);
public:
    Node(const std::string& aname) : name(aname) {}
    // virtual ~Node();
    
    const int getWeight(Node* neighbour) const { return neighbour->neighbours.size(); }
    const std::string& getName() const { return name; }
    node_iterator nb_begin() const { return neighbours.begin(); }
    node_iterator nb_end() const { return neighbours.end(); }
    friend class Graph;
};


class Graph
{
    typedef std::set<Node*>::const_iterator node_iterator;
    std::set<Node*> nodes;
public:
    // virtual ~Graph();

    void addNode(Node* node);
    void removeNode(Node* node);
    void addEdge(Node* begin, Node* end);
    void removeEdge(Node* begin, Node* end);
    node_iterator begin() const { return nodes.begin(); }
    node_iterator end() const { return nodes.end(); }
};


class BFS
{
    const Graph& graph;
public:
    BFS(const Graph& agraph) : graph(agraph) {}
    bool connected(Node* begin, Node* end);
};


class DFS
{
    std::set<Node*> visited;
    const Graph& graph;

    bool connected(Node* begin, Node* end, int depth);
public:
    DFS(const Graph& agraph) : graph(agraph) {}
    bool connected(Node* begin, Node* end);
};


struct MarkedNode
{
    Node* node; int mark;
    Node* prev;
    MarkedNode(Node* anode = 0, int amark = 0, Node* aprev = 0) : node(anode), mark(amark), prev(aprev) {}
};


class PriorityQueue
{
    std::vector<MarkedNode> nodes;
public:
    MarkedNode pop();
    void push(Node* node, int mark, Node* prev);
    bool empty() const { return nodes.empty(); }
};


struct Way
{
    std::vector<Node*> nodes;
    int length;
    Way() : length(-1) {}
};


class Dijkstra {
    const Graph& graph;
public:
    Dijkstra(const Graph& agraph) : graph(agraph) {}
    Way shortestWay(Node* begin, Node* end);
};