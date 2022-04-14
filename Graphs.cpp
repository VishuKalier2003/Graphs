// Implementation of Graphs using Adjacency List
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;
class Edge
{
    public:
    int end_vertex;        // End vertex as the vertex pointing to
    int distance;        // Path cost or the Edge weight
    public:
    Edge ()
    {
        end_vertex = 0;
        distance = 0;
    }
    public:
    Edge (int vertex_value, int path_cost)   // Parametrized Constructor
    {
        end_vertex = vertex_value;
        distance = path_cost;
    }
    public:   // Setter function
    void CreateEdge (int vertex_value, int path_cost)
    {
        end_vertex = vertex_value;
        distance = path_cost;
    }
    public:    // Setter function
    void ChangeEdge (int w)
    {
        distance = w;
    }
    public:     // Getter function
    int GetEndVertex()
    {
        return end_vertex;
    }
    public:    // Getter function
    int GetEdgeWeight()
    {
        return distance;
    }
};
class Vertex
{
    public:
    int vertex_data;
    list<Edge> edgeList;
    public:
    Vertex ()
    {
        vertex_data = 0;
    }
    public:
    Vertex (int data)    // Parametrized Constructor
    {
        vertex_data = data;
    }
    public:   // Setter Method
    void SetVertexData (int data)
    {
        vertex_data = data;
    }
    public:
    int GetVertexData ()
    {
        return vertex_data;
    }
    public:    // Getter Method
    list<Edge> GetEdgeList()
    {
        return edgeList;
    }
    public:
    void PrintEdgeList()
    {
        cout << "[";
        for(auto i = edgeList.begin(); i != edgeList.end(); i++)
        {
            cout << i -> GetEndVertex() << " (" << i -> GetEdgeWeight() << " ) --> ";
        }
        cout << "]" << endl;
    }
};
class Graph 
{
    public:
    vector<Vertex> vertices;
    public:
    void AddVertex(Vertex newVertex)
    {
        vertices.push_back(newVertex);
        cout << "Vertex Added !!" << endl;
    }
    public:
    void AddEdge(Vertex v1, Vertex v2, int dist)
    {
        for(int i = 0; i < vertices.size(); i++)
        {
            if(vertices.at(i).GetVertexData() == v1.vertex_data)
            {
                Edge e(v2.vertex_data, dist);
                vertices.at(i).edgeList.push_back(e);
            }
            else if(vertices.at(i).GetVertexData() == v2.vertex_data)
            {
                Edge e(v1.vertex_data, dist);
                vertices.at(i).edgeList.push_back(e);
            }
        }
        cout << "Edge Added !!" << endl;
    }
    public:
    void PrintGraph()
    {
        for(int i = 0; i < vertices.size(); i++)
        {
            Vertex temp;
            temp = vertices.at(i);
            cout << "( " << temp.GetVertexData() << " )";
            temp.PrintEdgeList();
        }
    }
};
int main()
{
    Graph graph;
    Vertex vertex, vertex1;
    int s, x, x1, ed;
    cout << "Enter number of vertices to add in a Graph : ";
    cin >> s;
    for(int k = 0; k < s; k++)
    {
        cout << "Enter vertex data : ";
        cin >> x;
        vertex.SetVertexData(x);
        graph.AddVertex(vertex);
        cout << "Enter vertex data : ";
        cin >> x1;
        vertex1.SetVertexData(x1);
        graph.AddVertex(vertex1);
        cout << "Enter Edge distance : ";
        cin >> ed;
        graph.AddEdge(vertex, vertex1, ed);
        graph.PrintGraph();
    }
    return 0;
}