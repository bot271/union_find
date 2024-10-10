//
//  union_find_chain.cpp
//  union_find
//
//  Created by Mingze Lee on 2024/10/10.
//

#ifndef __UNION_FIND_CHAIN_H__
#define __UNION_FIND_CHAIN_H__

namespace ufc {
struct equivNode
{
    int equivClass;
    int next;
    int size;
};

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

equivNode * node;
int n;

void initialize(int num)
{
    n = num;
    node = new equivNode [num + 1];
    for (int i = 1; i < num + 1; ++i)
    {
        node[i].next = 0;
        node[i].size = 1;
        node[i].equivClass = i;
    }
}

void unite(int class_A, int class_B)
{
    if (node[class_A].size > node[class_B].size)
        swap(class_A, class_B);
    int k;
    for (k = class_A; node[k].next != 0; k = node[k].next)
        node[k].equivClass = class_B;
    node[k].equivClass = class_B;
    node[class_B].size += node[class_A].size;
    node[class_A].next = node[class_B].next;
    node[class_B].next = class_A;
}

int find(int element)
{
    return node[element].equivClass;
}


}

#endif
