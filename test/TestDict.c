/*************************************************************************
|                                                                         |
|   File    : TestDict.c                                                  |
|   Created : 29-Jun-2013                                                 |
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

#include "ADT_Dict.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *key1, *key2;
    char *n1, *n2;
    char s1, s2;
    // Create dict
    Dict *theD = Dict_Create();
    if (theD != NULL) {
        printf("Dict_Create OK\n");
    } else {
        printf("Dict_Create KO!!!\n");
        return 0;
    }
    // Test insertion and lookup
    key1 = (char*)malloc(10*sizeof(char));
    key2 = (char*)malloc(10*sizeof(char));
    strcpy(key1, "one");
    strcpy(key2, "two");
    n1 = (char*)malloc(sizeof(char));
    n2 = (char*)malloc(sizeof(char));
    (*n1) = 1;
    (*n2) = 2;
    Dict_Insert(theD, key1, n1);
    Dict_Insert(theD, key2, n2);
    s1 = (*(char*)Dict_Lookup(theD, "one"));
    s2 = (*(char*)Dict_Lookup(theD, key2));
    if (s1 == 1) {
        printf("1st Dict_Insert and Dict_Lookup OK\n");
    } else {
        printf("1st Dict_Insert and Dict_Lookup KO!!!\n");
        return 0;
    }
    if (s2 == 2) {
        printf("2nd Dict_Insert and Dict_Lookup OK\n");
    } else {
        printf("2nd Dict_Insert and Dict_Lookup KO!!!\n");
        return 0;
    }
    // deletion
    Dict_Delete(theD);
    return 1;
}

