//
//  a1146SnapshotArray.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class SnapshotArray {
    vector<map<int,int>> data;
    int snapId;
public:
    SnapshotArray(int length) {
        data.resize(length);
        snapId=0;
    }
    void set(int index, int val) {
        data[index][snapId]=val;
    }

    int snap() {
        return snapId++;
    }

    int get(int index, int snap_id) {
        auto it = data[index].upper_bound(snap_id);
        if(it== data[index].begin())
            return 0;
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
