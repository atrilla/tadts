/*************************************************************************
|                                                                         |
|   File    : ADT_List.h                                                  |
|   Created : 13-Jun-2013                                                 |
|   By      : atrilla                                                     |
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
 * @brief A generic list container with stack/queue functions.
 *
 * @author Alexandre Trilla (atrilla)
 */

#ifndef ADT_LIST_H
#define ADT_LIST_H

typedef struct Element {
    void *theContent;
    struct Element *theNext;
} Element;

typedef struct {
    Element *theFront;
    Element *theBack;
} List;

/**
 * @post A new list is created and a pointer to its structure is
 *       returned if construction was successful. A NULL pointer is
 *       returned otherwise.
 */
List* List_Create();

/**
 * @pre  An initialized list pointer (pList) must be given.
 * @post The given list struct is removed from the heap.
 *       All contents are deallocated.
 */
void List_Delete(List *pList);

/**
 * @pre  An initialized list pointer (pList) must be given.
 * @post Returns 1 if list is empty. 0 otherwise.
 */
char List_Empty(List *pList);

/**
 * @pre  An initialized list pointer (pList) must be given.
 *       Dynamically allocated content (pCont) must be given.
 * @post Appends a new element with the given content to the given list.
 *       Returns 1 if the process concluded successfully. 0 otherwise.
 *       FIFO enqueue.
 */
char List_PushBack(List *pList, void *pCont);

/**
 * @pre  An initialized list pointer (pList) must be given.
 *       Dynamically allocated content (pCont) must be given.
 * @post Prepends a new element with the given content to the given list.
 *       Returns 1 if the process concluded successfully. 0 otherwise.
 *       LIFO push.
 */
char List_PushFront(List *pList, void *pCont);

/**
 * @pre  An initialized list pointer (pList) must be given.
 *       Non empty list is required.
 * @post The head element of the list is returned and deleted from the
 *       list container. It must be explicitly deallocated later.
 *       LIFO pop, FIFO dequeue.
 */
Element* List_Pop(List *pList);

/**
 * @pre  An initialized list pointer (pList) must be given.
 * 
 * @post The front element of the list is returned.
 */
Element* List_GetFront(List *pList);

/**
 * @pre  An initialized list pointer (pList) must be given.
 * 
 * @post The back element of the list is returned.
 */
Element* List_GetBack(List *pList);

/**
 * @pre  An initialized element pointer (pElem) must be given.
 * @post The content of the element is returned. It must be cast to the
 *       actual type of content.
 */
void* List_GetContent(Element *pElem);

/**
 * @pre  An initialized element pointer (pElem) must be given.
 * @post The next element is returned. NULL if last.
 */
Element* List_GetNext(Element *pElem);

#endif

