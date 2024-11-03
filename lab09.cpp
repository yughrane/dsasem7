#include <iostream>
#include <list>

using namespace std;

class Graph
{
private:
    int v = 0;
    list<int> *adjList;

public:
    Graph(int V) : v(V), adjList(new list<int>[V]) {}
    
};
