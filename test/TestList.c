/*************************************************************************
|                                                                         |
|   File    : TestList.c                                                  |
|   Created : 20-Jun-2013                                                 |
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

#include "ADT_List.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *i = (int*)malloc(sizeof(int));
    char *c = (char*)malloc(sizeof(char));
    int *j = (int*)malloc(sizeof(int));
    // Create list
    List *theL = List_Create();
    if (theL != NULL) {
        printf("List_Create OK\n");
    } else {
        printf("List_Create KO!!!\n");
        return 0;
    }
    // Check emptiness
    if (List_Empty(theL)) {
        printf("List_Empty OK\n");
    } else {
        printf("List_Empty KO!!!\n");
        return 0;
    }
    // Check push back
    (*i) = 44;
    (*c) = 'a';
    List_PushBack(theL, i);
    List_PushBack(theL, c);
    if (!List_Empty(theL)) {
        printf("Non List_Empty OK\n");
    } else {
        printf("Non List_Empty KO!!!\n");
        return 0;
    }
    // Check element retrieval: get front and back
    if (*(int*)List_GetContent(List_GetFront(theL)) == 44) {
        printf("List_PushBack, List_GetFront and List_GetContent OK\n");
    } else {
        printf("List_PushBack, List_GetFront and List_GetContent KO!!!\n");
        return 0;
    }
    if (*(char*)List_GetContent(List_GetBack(theL)) == 'a') {
        printf("List_PushBack, List_GetBack and List_GetContent OK\n");
    } else {
        printf("List_PushBack, List_GetBack and List_GetContent KO!!!\n");
        return 0;
    }
    // Check push front
    (*j) = 100;
    List_PushFront(theL, j);
    if (*(int*)List_GetContent(List_GetFront(theL)) == 100) {
        printf("List_PushFront OK\n");
    } else {
        printf("List_PushFront KO!!!\n");
        return 0;
    }
    // Check get next
    if (*(int*)List_GetContent(List_GetNext(List_GetFront(theL))) == 44) {
        printf("List_GetNext OK\n");
    } else {
        printf("List_GetNext KO!!!\n");
        return 0;
    }
    List_Delete(theL);
    return 1;
}

