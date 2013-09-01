/*************************************************************************
|                                                                         |
|   File    : TestGraph.c                                                 |
|   Created : 01-Sep-2013                                                 |
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *key1, *key2, *key3, *key4, *key5, *key6;
    char okFlag;
    List *aux;
    Element *iter;
    // Create graph as is shown in Wikipedia entry: 
    //     Graph_(abstract_data_type)
    Graph *theG = Graph_Create();
    if (theG != NULL) {
        printf("Graph_Create OK\n");
    } else {
        printf("Graph_Create KO!!!\n");
        return 0;
    }
    // Test insertion
    key1 = (char*)malloc(10*sizeof(char));
    strcpy(key1, "one");
    okFlag = Graph_AddNode(theG, key1);
    if (okFlag) {
        Graph_SetNodeValue(theG, key1, 1);
        if (Graph_GetNodeValue(theG, key1) == 1) {
            printf("Graph_AddNode, Graph_SetNodeValue and Graph_GetNodeValue OK\n");
        }
    } else {
        printf("Graph_AddNode KO!!!\n");
        return 0;
    }
    key2 = (char*)malloc(10*sizeof(char));
    strcpy(key2, "two");
    Graph_AddNode(theG, key2);
    key3 = (char*)malloc(10*sizeof(char));
    strcpy(key3, "three");
    Graph_AddNode(theG, key3);
    key4 = (char*)malloc(10*sizeof(char));
    strcpy(key4, "four");
    Graph_AddNode(theG, key4);
    key5 = (char*)malloc(10*sizeof(char));
    strcpy(key5, "five");
    Graph_AddNode(theG, key5);
    key6 = (char*)malloc(10*sizeof(char));
    strcpy(key6, "six");
    Graph_AddNode(theG, key6);
    okFlag = Graph_AddEdge(theG, key1, key2);
    if (okFlag) {
        Graph_SetEdgeValue(theG, key1, key2, 1);
        if (Graph_GetEdgeValue(theG, key1, key2) == 1) {
            printf("Graph_AddEdge, Graph_SetEdgeValue and Graph_GetEdgeValue OK\n");
        }
    } else {
        printf("Graph_AddEdge KO!!!\n");
        return 0;
    }
    okFlag = Graph_AddEdge(theG, key1, key2);
    okFlag = Graph_AddEdge(theG, key1, key5);
    okFlag = Graph_AddEdge(theG, key2, key5);
    okFlag = Graph_AddEdge(theG, key2, key3);
    okFlag = Graph_AddEdge(theG, key3, key4);
    okFlag = Graph_AddEdge(theG, key4, key5);
    okFlag = Graph_AddEdge(theG, key4, key6);
    //
    aux = Graph_Neighbors(theG, key2);
    iter = List_GetFront(aux);
    printf("Now, three and five should be printed:\n");
    while (iter != NULL) {
        printf("%s\n", (char*)List_GetContent(iter));
        iter = List_GetNext(iter);
    }
    List_Delete(aux);
    //
    if (Graph_Adjacent(theG, key4, key5)) {
        printf("Graph_Adjacent OK\n");
    } else {
        printf("Graph_Adjacent KO!!!\n");
        return 0;
    }
    //
    Graph_Delete(theG);
    return 1;
}

