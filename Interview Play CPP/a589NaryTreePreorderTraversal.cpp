//
//  a589NaryTreePreorderTraversal.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/2/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
            Node* temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            for(int i=temp->children.size()-1;i>=0;i--)
            {
                if(temp->children[i]!=nullptr)
                    st.push(temp->children[i]);
            }
        }
        return ans;
    }
};
