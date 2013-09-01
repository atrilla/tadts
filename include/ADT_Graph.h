/*************************************************************************
|                                                                         |
|   File    : ADT_Graph.h                                                 |
|   Created : 31-Jul-2013                                                 |
|   By      : atrilla                                                     |
|                                                                         |
|   TADTs - Typical Abstract Data Types                                   |
|                                                                         |
|   Copyright (c) 2013 Alexandre Trilla                                   |
|                                                                         |
|   -------------------------------------------------------------------   |
|                                                                         |
|   This file is part of TADTs.                                           |
|                                                                         |
|   TADTs is free software: you can redistribute it and/or modify it under|
|   the terms of the MIT/X11 License as published by the Massachusetts    |
|   Institute of Technology. See the MIT/X11 License for more details.    | 
|                                                                         |
|   You should have received a copy of the MIT/X11 License along with     |
|   this source code distribution of TADTs (see the COPYING file in the   |
|   root directory).                                                      |
|   If not, see <http://www.opensource.org/licenses/mit-license>.         |
|                                                                         |
 *************************************************************************/

/**
 * @brief An graph abstract data type.
 *
 * @author Alexandre Trilla (atrilla)
 */

#ifndef ADT_GRAPH_H
#define ADT_GRAPH_H

#include "ADT_Dict.h"
#include "ADT_List.h"

typedef struct {
    float theValue;
    List *theEdge;
} Node;

typedef struct {
    float theValue;
    char *pointedNodeID;
} Edge;

typedef Dict Graph;

/**
 * @post A new empty graph is created and a pointer to its structure is
 *       returned if construction was successful. A NULL pointer is
 *       returned otherwise.
 */
Graph* Graph_Create();

/**
 * @pre  An initialized graph struct pointer (pGraph) must be given.
 * @post The given graph struct is removed from the heap.
 *       All nodes are deallocated.
 */
void Graph_Delete(Graph *pGraph);

/**
 * @pre  An initialized graph struct pointer (pGraph) must be given.
 *       A valid node ID string key (nodeX) must be given.
 *       A valid node ID string key (nodeY) must be given.
 * @post Tests whether if there is an edge from nodeX to nodeY. Returns
 *       1 if true, 0 otherwise.
 */
char Graph_Adjacent(Graph *pGraph, char *nodeX, char *nodeY);

/**
 * @pre  An initialized graph struct pointer (pGraph) must be given.
 *       A valid node ID string key (nodeX) must be given.
 * @post Lists all the neighbors (node string ID copies) adjacent to nodeX.
 *       User must deallocate returned list. 
 */
List* Graph_Neighbors(Graph *pGraph, char *nodeX);

/**
 * @pre  An initialized graph struct pointer (pGraph) must be given.
 *       A valid dynamically allocated new node ID string key (nodeX) 
 *       must be given.
 * @post Adds new node (with node ID nodeX) to the given graph. Returns
 *       1 if process completed successfully, 0 otherwise.
 */
char Graph_AddNode(Graph *pGraph, char *nodeX);

/**
 * @pre  An initialized graph struct pointer (pGraph) must be given.
 *       A valid node ID string key (nodeX) must be given.
 *       A valid node ID string key (nodeY) must be given.
 * @post Adds new edge from nodeX-nodeY to the given graph. Returns 1 
 *       if process completed successfully, 0 otherwise.
 */
char Graph_AddEdge(Graph *pGraph, char *nodeX, char *nodeY);

/**
 * @pre  An initialized graph struct pointer (pGraph) must be given.
 *       A valid node ID string key (nodeX) must be given.
 *       A float value (nodeVal) must be given.
 * @post Sets the value associated with nodeX to nodeVal.
 */
void Graph_SetNodeValue(Graph *pGraph, char *nodeX, float nodeVal);

/**
 * @pre  An initialized graph struct pointer (pGraph) must be given.
 *       A valid node ID string key (nodeX) must be given.
 * @post Returns the value associated with nodeX.
 */
float Graph_GetNodeValue(Graph *pGraph, char *nodeX);

/**
 * @pre  An initialized graph struct pointer (pGraph) must be given.
 *       A valid node ID string key (nodeX) must be given.
 *       A valid node ID string key (nodeY) must be given.
 *       A float value (edgeVal) must be given.
 * @post Sets the value associated with edge nodeX-nodeY to edgeVal.
 */
void Graph_SetEdgeValue(Graph *pGraph, char *nodeX, char *nodeY, 
     float edgeVal);

/**
 * @pre  An initialized graph struct pointer (pGraph) must be given.
 *       A valid node ID string key (nodeX) must be given.
 *       A valid node ID string key (nodeY) must be given.
 * @post Returns the value associated with edge nodeX-nodeY.
 */
float Graph_GetEdgeValue(Graph *pGraph, char *nodeX, char *nodeY);

#endif

