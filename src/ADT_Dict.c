/*************************************************************************
|                                                                         |
|   File    : ADT_Dict.c                                                  |
|   Created : 22-Jul-2013                                                 |
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
#include "ADT_List.h"
#include <stdlib.h>
#include <string.h>

Dict* Dict_Create() {
    List *auxL;
    Dict *pDict = (Dict*)malloc(sizeof(Dict));
    if (pDict != NULL) {
        // dict allocated, let's allocate struct elements
        auxL = List_Create();
        if (auxL != NULL) {
            pDict->theKey = auxL;
            auxL = List_Create();
            if (auxL != NULL) {
                pDict->theValue = auxL;
            } else {
                free(pDict->theKey);
                free(pDict);
                pDict = NULL;
            }
        } else {
            free(pDict);
            pDict = NULL;
        }
    }
    return pDict;
}

void Dict_Delete(Dict *pDict) {
    List_Delete(pDict->theKey);
    List_Delete(pDict->theValue);
    free(pDict);
}

char Dict_Insert(Dict *pDict, char *pKey, void *pVal) {
    char okKey = List_PushBack(pDict->theKey, pKey);
    char okVal = List_PushBack(pDict->theValue, pVal);
    char ret = 0;
    if (okKey && okVal) {
        ret = 1;
    }
    return ret;
}

void* Dict_Lookup(Dict *pDict, char *sKey) {
    void *ret = NULL;
    Element *dictKey = List_GetFront(pDict->theKey);
    Element *dictVal = List_GetFront(pDict->theValue);
    if (strcmp(sKey, (char*)List_GetContent(dictKey)) == 0) { // found
        ret = List_GetContent(dictVal);
    } else { // iterate the rest of the entries
        while (List_GetNext(dictKey) != NULL) {
            dictKey = List_GetNext(dictKey);
            dictVal = List_GetNext(dictVal);
            if (strcmp(sKey, (char*)List_GetContent(dictKey)) == 0) {
                ret = List_GetContent(dictVal);
                break;
            }
        }
    }
    return ret;
}

List* Dict_GetKeys(Dict *pDict) {
    return pDict->theKey;
}

