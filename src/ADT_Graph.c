/*************************************************************************
|                                                                         |
|   File    : ADT_Graph.c                                                 |
|   Created : 15-Aug-2013                                                 |
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

#include "ADT_Graph.h"
#include "ADT_List.h"
#include <stdlib.h>
#include <string.h>

Graph* Graph_Create(){
    Graph *pG = Dict_Create();
    return pG;
}

void Graph_Delete(Graph *pGraph) {
    List *nodeKeys = Dict_GetKeys(pGraph);
    Element *keyIter = List_GetFront(nodeKeys);
    char *key;
    Node *node;
    while (keyIter != NULL) {
        key = (char*)List_GetContent(keyIter);
        keyIter = List_GetNext(keyIter);
        node = (Node*)Dict_Lookup(pGraph, key);
        List_Delete(node->theEdge);
    }
    Dict_Delete(pGraph);
}

char Graph_Adjacent(Graph *pGraph, char *nodeX, char *nodeY) {
    List *edges = Graph_Neighbors(pGraph, nodeX);
    Element *e = List_GetFront(edges);
    char *nodeID;
    char adjFlag = 0;
    while (e != NULL) {
        nodeID = (char*)List_GetContent(e);
        e = List_GetNext(e);
        if (strcmp(nodeY, nodeID) == 0) {
            adjFlag = 1;
            break;
        }
    }
    List_Delete(edges);
    return adjFlag;
}

List* Graph_Neighbors(Graph *pGraph, char *nodeX) {
    List *neighs = List_Create();
    Node *node = (Node*)Dict_Lookup(pGraph, nodeX);
    Element *iter = List_GetFront(node->theEdge);
    Edge *aux;
    char *copyID, *id;
    while (iter != NULL) {
        aux = (Edge*)List_GetContent(iter);
        id = aux->pointedNodeID;
        copyID = (char*)malloc(strlen(id)*sizeof(char)+1);
        strcpy(copyID, id);
        List_PushBack(neighs, copyID);
        iter = List_GetNext(iter);
    }
    return neighs;
}

char Graph_AddNode(Graph *pGraph, char *nodeX) {
    char retOK;
    Node *newNode = (Node*)malloc(sizeof(Node));
    List *newList = List_Create();
    if ((newNode != NULL) && (newList != NULL)) {
        newNode->theValue = -1;
        newNode->theEdge = newList;
        retOK = Dict_Insert(pGraph, nodeX, newNode);
    } else {
        retOK = 0;
    }
    return retOK;
}

char Graph_AddEdge(Graph *pGraph, char *nodeX, char *nodeY) {
    char retOK;
    Node *nX = (Node*)Dict_Lookup(pGraph, nodeX);
    Edge *newEdge = (Edge*)malloc(sizeof(Edge));
    if (newEdge != NULL) {
        newEdge->theValue = -1;
        newEdge->pointedNodeID = nodeY;
        retOK = List_PushBack(nX->theEdge, newEdge);
    } else {
        retOK = 0;
    }
    return retOK;
}

void Graph_SetNodeValue(Graph *pGraph, char *nodeX, float nodeVal) {
    Node *nX = (Node*)Dict_Lookup(pGraph, nodeX);
    nX->theValue = nodeVal;
}

float Graph_GetNodeValue(Graph *pGraph, char *nodeX) {
    Node *nX = (Node*)Dict_Lookup(pGraph, nodeX);
    return nX->theValue;
}

void Graph_SetEdgeValue(Graph *pGraph, char *nodeX, char *nodeY, 
     float edgeVal)  {
    Node *nX = (Node*)Dict_Lookup(pGraph, nodeX);
    Edge *aux;
    Element *iter = List_GetFront(nX->theEdge);
    while (iter != NULL) {
        aux = (Edge*)List_GetContent(iter);
        if (strcmp(aux->pointedNodeID, nodeY) == 0) {
            aux->theValue = edgeVal;
            break;
        }
        iter = List_GetNext(iter);
    }
}

float Graph_GetEdgeValue(Graph *pGraph, char *nodeX, char *nodeY) {
    float edgeVal = -1;
    Node *nX = (Node*)Dict_Lookup(pGraph, nodeX);
    Edge *aux;
    Element *iter = List_GetFront(nX->theEdge);
    while (iter != NULL) {
        aux = (Edge*)List_GetContent(iter);
        if (strcmp(aux->pointedNodeID, nodeY) == 0) {
            edgeVal = aux->theValue;
            break;
        }
        iter = List_GetNext(iter);
    }
    return edgeVal;
}

