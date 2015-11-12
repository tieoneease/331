#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

enum Color { WHITE, BLACK, NONE };

struct Vertex
{
    int vertex;
    Color color;
    vector<Vertex*> adjacencies;

    // Default constructor
    Vertex():
        vertex(0),
        color(WHITE) {};

    // Constructor
    Vertex(int v):
        vertex(v),
        color(NONE) {};

    // Color vertex
    void Color(Color c) { color = c; }

    // Add vertex to adjacency list
    void AddAdjacency(Vertex *v) { adjacencies.push_back(v); }


    // Check adjacencies for conflicts
    Vertex* CheckAdjacencies()
    {
        for (vector<Vertex*>::iterator it = adjacencies.begin(); it != adjacencies.end(); ++it)
        {
            if (color == (*it)->color) return *it;
        }
        return 0;
    }

    // Print vertex information
    void PrintVertex()
    {
        cout << "Vertex: " << vertex << endl;
        cout << "Color: " << (color == WHITE? "White":
                              color == BLACK? "Black":
                                              "None") << endl;

        cout << "Adjacencies:\t";
        for (vector<Vertex*>::iterator it = adjacencies.begin(); it != adjacencies.end(); ++it)
        {
            cout << (*it)->vertex << ' ';
        }
        cout << endl;
    }
};


class Graph
{
    private:
        map<int, Vertex*> vertices;
        int size;

    public:
        Graph(const char* filename) {
            ifstream filestream;
            filestream.open(filename);
            if (filestream)
            {
                size = 0;
                string line;
                while (getline(filestream, line))
                {
                    int numvertex;
                    int numadjacency;
                    istringstream sstream(line);

                    sstream >> numvertex;
                    if (vertices.find(numvertex) == vertices.end())
                        vertices[numvertex] = new Vertex(numvertex);
                    while (sstream >> numadjacency)
                    {
                        Vertex *v;
                        map<int, Vertex*>::iterator it = vertices.find(numadjacency);
                        if (it != vertices.end())
                        {
                            v = it->second;
                        }
                        else
                        {
                            v = new Vertex(numadjacency);
                            vertices[numadjacency] = v;
                        }
                        vertices[numvertex]->AddAdjacency(v);
                    }
                    size++;
                }
            }
            else
                cout << "ERROR: File not found" << endl;
        }

        ~Graph() { 
            for (int i = 0; i < size; i++)
            {
                delete vertices[i];
            }
        } 

        void PrintGraph()
        {
            for (int i = 0; i < size; i++)
            {
                vertices[i]->PrintVertex();
                cout << endl;
            }
        }

        // function to determine whether a graph is bipartite
        // start traverse a graph from node u
        // return true if a graph is bipartite. Otherwise, return false
        bool isBipartitePrintTraversePath(int u);
};

// function to determine whether a graph is bipartite
// start traverse a graph from node u
// return true if a graph is bipartite. Otherwise, return false
bool Graph::isBipartitePrintTraversePath(int u) {
    return 0;
}


int main()
{
    /*
       Vertex *v1 = new Vertex(1);
       Vertex *v2 = new Vertex(2);
       Vertex *v3 = new Vertex(3);
       Vertex *v4 = new Vertex(4);

       v1->Color(BLACK);
       v2->Color(WHITE);
       v3->Color(BLACK);

       v1->AddAdjacency(v2);
       v1->AddAdjacency(v3);
       v2->AddAdjacency(v1);
       v2->AddAdjacency(v3);
       v3->AddAdjacency(v1);
       v3->AddAdjacency(v2);

       v1->PrintVertex();
       cout << endl;
       v2->PrintVertex();
       cout << endl;
       v3->PrintVertex();
       cout << endl;
       v4->PrintVertex();
       cout << endl;

       cout << endl;
       cout << "Checking adjacencies of 1: " << endl;
       Vertex *conflict = v1->CheckAdjacencies();

       if (conflict)
       cout << "CONFLICT: " <<  v1->vertex << " : " << conflict->vertex << endl;
       else
       cout << "NO CONFLICT" << endl;

       cout << endl;
       */
    Graph g("g1.txt");
    g.PrintGraph();

    return 0;
}
