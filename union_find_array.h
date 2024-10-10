//
//  bind_find_array.h
//  union_find
//
//  Created by Mingze Lee on 2024/10/10.
//

#ifndef __UNION_FIND_ARRAY_H__
#define __UNION_FIND_ARRAY_H__

namespace ufa {

int * equivClass;
int n;

void initialize(int num)
{
    n = num;
    equivClass = new int [n + 1];
    for (int i = 1; i < n + 1; ++i)
        equivClass[i] = 0;
}

void unite(int class_A, int class_B)
{
    for (int i = 1; i < n + 1; ++i)
        if (equivClass[i] == class_A)
            equivClass[i] = class_B;
}

int find(int element)
{
    return equivClass[element];
}

}

#endif
