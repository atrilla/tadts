/*************************************************************************
|                                                                         |
|   File    : ADT_Dict.h                                                  |
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

/**
 * @brief An associative array abstract data type. It is based on a
 *        parallel unordered array structure. A hash table should be used 
 *        to boost its search performance O(N) vs O(1).
 *
 * @author Alexandre Trilla (atrilla)
 */

#ifndef ADT_DICT_H
#define ADT_DICT_H

#include "ADT_List.h"

typedef struct {
    List *theKey;
    List *theValue;
} Dict;

/**
 * @post A new dictionary is created and a pointer to its structure is
 *       returned if construction was successful. A NULL pointer is
 *       returned otherwise.
 */
Dict* Dict_Create();

/**
 * @pre  An initialized dict pointer (pDict) must be given.
 * @post The given dict struct is removed from the heap.
 *       All contents are deallocated.
 */
void Dict_Delete(Dict *pDict);

/**
 * @pre  An initialized dict pointer (pDict) must be given.
 *       Dynamically allocated new string key (pKey) must be given.
 *       Dynamically allocated content/value (pVal) must be given.
 * @post Inserts a new binding to the given dictionary.
 *       Returns 1 if the process concluded successfully. 0 otherwise.
 */
char Dict_Insert(Dict *pDict, char *pKey, void *pVal);

/**
 * @pre  An initialized dict pointer (pDict) must be given.
 *       A string key (sKey) must be given.
 * @post Returns the content pointer corresponding to the given key.
 *       If given key is not found, NULL is returned.
 */
void* Dict_Lookup(Dict *pDict, char *sKey);

/**
 * @pre  An initialized dict pointer (pDict) must be given.
 * @post Returns the list of keys.
 */
List* Dict_GetKeys(Dict *pDict);

#endif

