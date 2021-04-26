// C++
#include <iostream>
#include <string>

// Boost::Graph
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/topological_sort.hpp>
#include <boost/graph/graph_utility.hpp>

// Neuron
struct Vertex
{
    int threshold;
};

// Synapse
struct Edge
{
    int speed;
    std::string channel;
};

int main()
{
    std::cout << "Boost::Graph usage\n";

    typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS, Vertex, Edge > Graph;
    typedef boost::graph_traits<Graph>::vertex_descriptor vertex_t;
    typedef boost::graph_traits<Graph>::edge_descriptor edge_t;

    //Instanciate a graph
    Graph g;

    // Create two vertices in that graph
    vertex_t u = boost::add_vertex(g);
    vertex_t v = boost::add_vertex(g);

    // Create an edge conecting those two vertices
    edge_t e; bool b;
    boost::tie(e,b) = boost::add_edge(u,v,g);

    // Set the properties of a vertex and the edge
    g[u].threshold = 42;
    g[e].speed = 108;
    g[e].channel = "test";

    std::cout << "Number of vectices = " << boost::num_vertices(g) << std::endl;
    std::cout << "Number of edges = " << boost::num_edges(g) << std::endl;

    boost::print_graph(g);

    return 0;
}
