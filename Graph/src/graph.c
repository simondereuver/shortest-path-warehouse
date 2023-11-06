#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

//create a graph
//parameters: int, the number of nodes in the graph 
//return:     a pointer to the graph
struct graph *createGraph(int number_of_nodes)
{
    struct graph *graph;
    graph = malloc(sizeof(struct graph));
    graph->array = malloc(sizeof(struct adjList)*number_of_nodes);
    graph->N = number_of_nodes;
    
    //Initialize each adjacency list
    for (int i = 0; i < number_of_nodes; i++){

        struct adjListNode *head = (struct adjListNode*)malloc(sizeof(struct adjListNode));
            head->graph_node_id = i;
        
        head->weight = 0;
        head->next = NULL;
        graph->array[i].head = head;
    }
    return graph;
}

//print connections between nodes
//parameters: graph
void displayGraph(struct graph *ptr)
{
    int num_nodes = ptr->N;

    //we can also print the array as a matrice once shelf numbers has been added
    for (size_t i = 0; i < num_nodes ; i++)
    {
        struct adjListNode *head = ptr->array[i].head;
        printf("Node: %d is connected to: \n", head->graph_node_id);
        struct adjListNode *adjacent_node = head;
        while(adjacent_node != NULL)
        {
            printf("Node %d has a direct connection to node ->  %d \n", head->graph_node_id, adjacent_node->graph_node_id);
            adjacent_node = adjacent_node->next;
        }
        printf("%s", "\n");
    }
}

//add an edge between the source node and the target node
//parameters: graph, the pointer points to the graph
//            source, the id of the source node
//            target, the id of the target node
//            weight, the weight of the edge
void addEdge(struct graph *graph, int source, int target, int weight)
{
    //create target node
    struct adjListNode *new_adjListNode, *ptr;
    new_adjListNode = (struct adjListNode*) malloc(sizeof(struct adjListNode));
    new_adjListNode->graph_node_id = target; 
    new_adjListNode->weight = weight;
    new_adjListNode->next = NULL;

    ptr = graph->array[source].head; 

    //Link togheter source node (shelve numbers) with adjacent nodes (adjacent shelves)
    if(ptr->next == NULL)
    {
        ptr->next = new_adjListNode;
    }
    else
    {
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_adjListNode; 
    }
}


void addEdges(struct graph *graph)
{
    //algorithm for adding edges   
    for (int i = 0; i < COLS / 2; i++)
    {
        //MyaddEdge(struct graph* graph, int source, int target, int weight)
        for (int j = 0; j < (ROWS + EDGEROWS); j++)
        {   
            //edgecase when we are at top, dont want to add above
            if (j == 0)
            {
                //always add one below
                addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) + 1, 1);

                //link togheter column only to the right
                if (i == 0)
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) + (ROWS + EDGEROWS), 100);
                else if (i == (COLS / 2) - 1)
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) - (ROWS + EDGEROWS), 100);
                else
                //link togheter both left and right
                {
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) + (ROWS + EDGEROWS), 100);
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) - (ROWS + EDGEROWS), 100);
                }
            }
            //edgecase when we are at bottom, only add nodes "above" and link nodes
            else if (j == (ROWS + EDGEROWS) - 1)
            {
                //always add one above
                addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) - 1, 1);

                //link togheter only to the left
                if (i == 0)
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) + (ROWS + EDGEROWS), 100);
                else if (i == (COLS / 2) - 1)
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) - (ROWS + EDGEROWS), 100);
                else
                //link togheter both left and right
                {
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) + (ROWS + EDGEROWS), 100);
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) - (ROWS + EDGEROWS), 100);
                }
            }
            //edgecase middle of graph
            else if (j == ((ROWS + EDGEROWS) - 1) / 2)
            {
                if (i == 0)
                {
                    //add above, below and to the right
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) + (ROWS + EDGEROWS), 100);
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) + 1, 1);
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) - 1, 1);
                }
                else if (i == (COLS / 2) - 1)
                {
                    //add above, below and to the left
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) - (ROWS + EDGEROWS), 100);
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) + 1, 1);
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) - 1, 1);
                }
                else
                {
                    //add above, below and left/right
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) - (ROWS + EDGEROWS), 100);
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) + (ROWS + EDGEROWS), 100);
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) + 1, 1);
                    addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) - 1, 1);
                }
            }
            else
            {
                addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) + 1, 1);
                addEdge(graph, j + ( (ROWS + EDGEROWS) * i), j + ( (ROWS + EDGEROWS) * i) - 1, 1);
                // FÖR ATT LÄGGA TILL HYLLNUMMER SÅ JOBBA LÄGG TILL PÅ INDEX i och i + 1
            }
        }
    }
}

/*
//delete the edge between the source node and the target node
//parameters: graph, the pointer points to the graph
//            source, the id of the source node
//            target, the id of the target node
void deleteEdge(struct graph* graph, int source, int target)
{
    if (graph->array[source].head->next == NULL)
        return;
    
    else
    {
        struct adjListNode* prev = graph->array[source].head;
        struct adjListNode* temp = graph->array[source].head->next;

        while( temp != NULL && temp->graph_node_id != target){
            prev = temp;
            temp = temp->next;
        }

        // If target is not present in the adjacent list
        if (temp == NULL)
             return;
 
        // Unlink the node from the adjacent list
        prev->next = temp->next;
 
        free(temp); // Free memory
    }
}
*/