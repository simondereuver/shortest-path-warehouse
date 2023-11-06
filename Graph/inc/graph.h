//              CREATE GRAPH REPRESENTATION IN FOR OF MATRICE, USED FOR FLOYD-WARSHALL ALGORITHM
//              Code and implementation made by Simon de Reuver, student at school of engineering in Jönköping
//              Some code is re-used and modified from earlier projects
#ifndef GRAPH_H_ 
#define GRAPH_H_
#include <stdio.h>

//for now just some testing values
#define COLS 4 //COLUMNS NEEDS TO BE AN EVEN NUMBER
#define ROWS 2 
#define EDGEROWS 3 //EDGEROWS IS ALWAYS 3

struct adjListNode
{
    //the id of the node in the graph
    int graph_node_id;

    int row_id;
    
    int col_id;
    
    //vi kan lägga in 2 hyllplatser för varje nod som har hyllor

    //the weight of the edge from this node to another node.
    int weight;
    //pointer points to the next element in an adjacent list, i.e., an adjacent node to the head
    struct adjListNode *next;
};


//declear a structure to present an adjacency list 
//head is the pointer points to the first element in the list, i.e., a node in the graph.
struct adjList {
    struct adjListNode* head;
};

// declare a structure to represent a graph. 
// N is the number of nodes in graph.
// A graph is an array of adjacency lists.
struct graph {
    int N;
    struct adjList* array;
};

//create a graph
//parameters: int, the number of nodes in the graph 
//return: the pointer points to the graph
struct graph* createGraph(int);

struct graph* createGraph(int number_of_nodes);

//display an edge between the source node and the target node
//parameters: graph, the pointer points to the graph
//            cities, the cities referenced by the node id in the graph  
void displayGraph(struct graph *ptr);


//add an edge between the source node and the target node
//parameters: graph, the pointer points to the graph
//            source, the id of the source node
//            target, the id of the target nonde
//            weight, the weight of the edge
void addEdge(struct graph* graph, int source, int target, int weight);

//delete the edge between the source node and the target node
//parameters: graph, the pointer points to the graph
//            source, the id of the source node
//            target, the id of the target node
void deleteEdge(struct graph* graph, int source, int target);

void addEdges(struct graph *graph);


void printTest();

#endif