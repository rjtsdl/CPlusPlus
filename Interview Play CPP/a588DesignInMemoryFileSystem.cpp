//
//  a588DesignInMemoryFileSystem.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class FileSystem {
    class iNode {
    public:
        iNode(string pth) {
            m_path = pth;
            m_isFile = false;
            m_content = "";
            m_children = map<string, iNode*>();
        }
        
        void UpdateFile(bool isFile) {
            m_isFile = isFile;
        }
        
        iNode* EnsureChildPath(string pth) {
            auto i = m_children.find(pth);
            if ( i != m_children.end()) {
                return i->second;
            }
            m_children.emplace(pth, new iNode(pth));
            return m_children[pth];
        }
        
        bool HasChildPath(string pth) {
            return m_children.find(pth) != m_children.end();
        }
        
        vector<string> ListChildPath() {
            if (m_isFile) {
                return {m_path};
            }
            vector<string> res;
            for (auto kv : m_children) {
                res.push_back(kv.first);
            }
            return res;
        }
        
        void AppendContent(string content) {
            m_content += content;
        }
        
        string GetContent() {
            return m_content;
        }
        
    private:
        string m_path;
        bool m_isFile;
        string m_content;
        map<string, iNode*> m_children;
    };
private:
    iNode* m_trieRoot;
public:
    FileSystem() {
        m_trieRoot = new iNode("");
    }
    
    iNode* navigate(string path, bool creatIfNotExist) {
        cout << "navigate: " << path << endl;
        int prev = 0;
        iNode* root = m_trieRoot;
        size_t found = path.find('/', prev);
        while (found != string::npos && root != nullptr) {
            string pth = path.substr(prev, found - prev);
            cout << "pth: " << pth << endl;
            if (pth.size() > 0) {
                if (!creatIfNotExist && !root->HasChildPath(pth)) {
                    return nullptr;
                }
                root = root->EnsureChildPath(pth);
            }
            prev = (int)found + 1;
            found = path.find('/', prev);
        }
        
        if (prev < path.size() && root != nullptr) {
            cout << "remaining pth: " << path.substr(prev) << endl;
            if (!creatIfNotExist && !root->HasChildPath(path.substr(prev))) {
                return nullptr;
            }
            root = root->EnsureChildPath(path.substr(prev));
        }
        return root;
    }
    
    vector<string> ls(string path) {
        iNode* root = navigate(path, false);
        if (root == nullptr) return vector<string>();
        
        return root->ListChildPath();
        
    }
    
    void mkdir(string path) {
        navigate(path, true);
    }
    
    void addContentToFile(string filePath, string content) {
        iNode* root = navigate(filePath, true);
        root->UpdateFile(true);
        root->AppendContent(content);
    }
    
    string readContentFromFile(string filePath) {
        iNode* root = navigate(filePath, false);
        if (root == nullptr) return "";
        return root->GetContent();
    }
};
/*
int main() {
    FileSystem* fs = new FileSystem();
    fs->ls("/");
    fs->mkdir("/a/b/c");
    fs->addContentToFile("/a/b/c/d", "hello");
    fs->ls("/");
    fs->readContentFromFile("/a/b/c/d");
}
 */
