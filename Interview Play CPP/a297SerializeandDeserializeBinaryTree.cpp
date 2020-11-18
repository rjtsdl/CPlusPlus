//
//  a297SerializeandDeserializeBinaryTree.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "[]";
        string ret = "[" + to_string(root->val);
        ret += serialize(root->left);
        ret += serialize(root->right);
        ret += "]";
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0;
        return deserializeHelper(data, start);
    }
    
    TreeNode* deserializeHelper(string& data, int& start) {
        if (start == data.size()) return nullptr;
        if (data[start] == '[') start++;
        string val = "";
        while (data[start] != '[' && data[start] != ']') {
            val += data[start++];
        }
        if (val.empty()) {
            start++;
            return nullptr;
        }
        
        
        TreeNode* p = new TreeNode(stoi(val));
        p->left = deserializeHelper(data, start);
        p->right = deserializeHelper(data, start);
        start++;
        return p;
    }
    
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
