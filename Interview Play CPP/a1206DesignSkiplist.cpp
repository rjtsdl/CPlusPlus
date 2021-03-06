//
//  a1206DesignSkiplist.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Skiplist{
    struct Node{
        int value;
        Node** next;
        Node(int val, short levels) : value(val){
            next = new Node * [levels>0?levels:1];
            fill_n(next, levels, nullptr);
        }
        ~Node(){
            delete[] next;
        }
    };

    Node* head;
    short levels;
    
    public:
    Skiplist() {
        levels = 1;
        head = new Node(INT_MIN, 1);
    }

    bool search(int target) {
        Node* cur = head;
        short i = levels - 1;
        for (; i >= 0; i--){
            while (cur->next[i] != nullptr && cur->next[i]->value < target)
                cur = cur->next[i];
        }
        cur = cur->next[0];
        if (cur != nullptr && cur->value == target)
            return true;
        return false;
    }

    static void seedRandomGenerator();

    short generateRandomLevels(){
        short l = 1;
        seedRandomGenerator();
        while (rand() % 2 == 0) l++;
        return l;
    }

    void add(int num) {
        Node* cur = head;
        short l = generateRandomLevels();
        auto* nodeToInsert = new Node(num, l);

        Node** update = new Node * [levels];
        fill_n(update, levels, nullptr );
        for (short i = levels - 1; i >= 0; i--){
            while (cur->next[i] != nullptr && cur->next[i]->value < num)
                cur = cur->next[i];
            update[i] = cur;
        }
        for (short i = 0; i < (min(levels,l)); i++){
            if (update[i] != nullptr){
                nodeToInsert->next[i] = update[i]->next[i];
                update[i]->next[i] = nodeToInsert;
            }
        }
        if (l > levels){
            cur = new Node(INT_MIN, l);
            fill_n(cur->next, l, nodeToInsert);
            for (short i = 0; i < levels; i++){
                cur->next[i] = head->next[i];
                head->next[i] = nullptr;
            }
            delete head;
            head = cur;
            levels = l;
        }
        delete[] update;
    }

    bool erase(int num) {
        Node* cur = head;
        Node** update = new Node * [levels];
        fill_n(update, levels, nullptr);

        for (short i = levels - 1; i >= 0; i--){
            while (cur->next[i] != nullptr && cur->next[i]->value < num)
                cur = cur->next[i];
            update[i] = cur;
        }
        Node* nodeToDel = cur->next[0];
        if (nodeToDel != nullptr && nodeToDel->value == num){
            for (short i = levels-1; i>=0; i--){
                if (update[i]->next[i] != cur->next[0])
                    continue;
                update[i]->next[i] = update[i]->next[i]->next[i];
                update[i] = nullptr;
                nodeToDel->next[i] = nullptr;
            }
            for (short i = levels - 1; i >= 0; i--){
                if (head->next[i] != nullptr)
                    break;
                levels--;
            }
            delete nodeToDel;
            delete[] update;
            return true;
        }
        delete[] update;
        return false;
    }

    void printAll(){
        for (short i = levels - 1; i >= 0; i--){
            Node* cur = head->next[i];
            while (cur != nullptr){
                cur = cur->next[i];
            }
        }
    }
};

void Skiplist::seedRandomGenerator(){
    static bool isSeeded = false;
    if (!isSeeded){
        isSeeded = true;
        srand(chrono::system_clock::now().time_since_epoch().count());
    }
}
