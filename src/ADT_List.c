/*************************************************************************
|                                                                         |
|   File    : ADT_List.c                                                  |
|   Created : 13-Jun-2013                                                 |
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
#include <stdlib.h>

List* List_Create() {
    List *pList = (List*)malloc(sizeof(List));
    if (pList != NULL) {
        pList->theFront = NULL;
        pList->theBack = NULL;
    }
    return pList;
}

void List_Delete(List *pList) {
    Element *auxElem;
    void *auxCont;
    while(!List_Empty(pList)) {
        auxElem = List_Pop(pList);
        auxCont = List_GetContent(auxElem);
        free(auxCont);
        free(auxElem);
    }
    free(pList);
}

char List_Empty(List *pList) {
    char opRes = 1;
    if (pList->theFront != NULL) {
        opRes = 0;
    }
    return opRes;
}

char List_PushBack(List *pList, void *pCont) {
    char retOK = 1;
    Element *aux = (Element*)malloc(sizeof(Element));
    if (aux != NULL) {
        aux->theNext = NULL;
        aux->theContent = pCont;
        if (List_Empty(pList)) {
            pList->theFront = aux;
            pList->theBack = aux;
        } else {
            pList->theBack->theNext = aux;
            pList->theBack = aux;
        }
    } else {
        retOK = 0;
    }
    return retOK;
}

char List_PushFront(List *pList, void *pCont) {
    char retOK = 1;
    Element *aux = (Element*)malloc(sizeof(Element));
    if (aux != NULL) {
        aux->theContent = pCont;
        aux->theNext = NULL;
        if (List_Empty(pList)) {
            pList->theFront = aux;
            pList->theBack = aux;
        } else {
            aux->theNext = pList->theFront;
            pList->theFront = aux;
        }
    } else {
        retOK = 0;
    }
    return retOK;
}

Element* List_Pop(List *pList) {
    Element *poppedElem = pList->theFront;
    pList->theFront = poppedElem->theNext;
    if (poppedElem->theNext == NULL) {
        pList->theBack = NULL;
    }
    return poppedElem;
}

Element* List_GetFront(List *pList) {
    return pList->theFront;
}

Element* List_GetBack(List *pList) {
    return pList->theBack;
}

void* List_GetContent(Element *pElem) {
    return pElem->theContent;
}

Element* List_GetNext(Element *pElem) {
    return pElem->theNext;
}

