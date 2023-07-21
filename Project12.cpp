//LaBerge, Kaleena Ann
//COP-3530-01Z
//Project 12 (Directed Graph - GraphNodes)
//A DIRECTED GRAPH, or a digraph, G=(V,E) consists of a nonempty set V of vertices
//and a set E of edges, where each edge is a pair of vertices from V.	

#include <iostream>
#include <vector>

class GraphNode {
public:
    int pointNum;
    std::vector<GraphNode*> connectedNodes;

    GraphNode(int num) : pointNum(num) {}
};

class Graph {
private:
    std::vector<GraphNode*> V;

public:
    // Constructor: Build the graph using the 2D array
    Graph(int numNodes, int** connectivityMatrix) {
        for (int i = 0; i < numNodes; i++) {
            addGraphNode(i, numNodes, connectivityMatrix);
        }
    }

    // Destructor: Release allocated memory of GraphNode objects
    ~Graph() {
        for (GraphNode* node : V) {
            delete node;
        }
    }
 // Method to add a new GraphNode object to the vector
    void addGraphNode(int num, int numNodes, int** connectivityMatrix) {
        GraphNode* newNode = new GraphNode(num);

        for (int i = 0; i < numNodes; i++) {
            if (connectivityMatrix[num][i] == 1) {
                newNode->connectedNodes.push_back(V[i]);
            }
        }

        V.push_back(newNode);
    }

    // Method to display the graph (adjacency list representation)
    void displayGraph() {
        for (const GraphNode* node : V) {
            std::cout << "Node " << node->pointNum << " is connected to: ";
            for (const GraphNode* connectedNode : node->connectedNodes) {
                std::cout << connectedNode->pointNum << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int numNodes;
    std::cout << "Enter the number of nodes: ";
    std::cin >> numNodes;
	
	 // Create a 2D array to store connectivity information
    int** connectivityMatrix = new int*[numNodes];
    for (int i = 0; i < numNodes; i++) {
        connectivityMatrix[i] = new int[numNodes];
    }

    std::cout << "Enter the connectivity matrix (1 if connected, 0 if not):\n";
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            std::cin >> connectivityMatrix[i][j];
        }
    }

    // Create the Graph object using the connectivity matrix
    Graph graph(numNodes, connectivityMatrix);

    // Display the graph
    std::cout << "\nThe Directed Graph G = (V, E) consists of:\n";
    graph.displayGraph();

    // Release allocated memory
    for (int i = 0; i < numNodes; i++) {
        delete[] connectivityMatrix[i];
    }
    delete[] connectivityMatrix;

    return 0;
}   
    
    
    
    
    
    
    
    
    
