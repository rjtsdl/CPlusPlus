//
//  a428SerializeAndDeserializeNaryTree.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

/*
class Codec {
public:
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
    // Encodes a tree to a single string.
    string serialize(Node* root)
    {
        if(root==nullptr)
            return "";
        string serializedString= "["+to_string(root->val);
        
        for(int i=0;i< root->children.size();i++ )
            serializedString+= serialize( root->children[i] );
        
        serializedString.push_back( ']' );
        return serializedString;
    }
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data)
    {
        if( !data.size() )
            return nullptr;
        int index=0;
        return deserializeHelper(index, data );
    }
    Node *deserializeHelper( int &index, string &data )
    {
        string valueOfNode="";
        index++;
        while( data[index]!=']' && data[index]!='[' )
        {
            valueOfNode.push_back( data[index] );
            index++;
        }
        Node *current=new Node( stoi( valueOfNode ) );
        while( data[index]!=']'  )
        {
            current->children.push_back( deserializeHelper(index,data)) ;
        }
        index++;
        return current;
    }
};
 */
