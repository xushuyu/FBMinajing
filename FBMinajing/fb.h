//
//  fb.h
//  FBMinajing
//
//  Created by Shuyu on 2/3/18.
//  Copyright © 2018 Shuyu. All rights reserved.
//

#include <vector>
#include <string>
#include <map>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <algorithm> // std::find
#include <set>
#include <queue>
#include <sstream>      // std::istringstream

#ifndef fb_h
#define fb_h

#endif /* fb_h */

class Vertex{
public:
    int name;
    Vertex(int n):name(n){}
};

class Edge{
public:
    Vertex start,end;
    Edge(Vertex s, Vertex e):start(s),end(e){}
};
using namespace std;
struct ListNode{
    ListNode* next;
    int value;
    ListNode(int v):value(v),next(nullptr){}
};

class TreeNode{
public:
    int val;
    TreeNode* left, *right;
    TreeNode(int v):val(v),left(nullptr),right(nullptr){}
};

class TNode{
public:
    int val;
    TNode(int v){ val = v;}
    vector<TNode*> children;
};


class  FirstOne{
public:
    vector<int> findFirstOne(vector<vector<int>> board);
    void test();
};

class Robots{
public:
    bool move(int dir){return true;}
    int findArea(vector<int> pos);
    void dfs(vector<int> pos, set<vector<int>>& visited);
};

class InsertCycleList{
public:
    ListNode* insert(ListNode *node,int n);
    void test();
};

class PowMo{
public:
    int powMod(int base,int exp,int md);
};
               
class Endian{
public:
    bool isBigEndian(){
        unsigned int num = 1;
        char* first = (char*)(&num);
        
        return *first == 1;
    }
};

class BSTShap{
public:
    void printBst(TreeNode* root);
    void printLeftEdge(TreeNode* root);
    void printRightEdge(TreeNode* root);
    void printLeaves(TreeNode* root);
    void test();
};

class BinarySearch{
public:
    int search(vector<int> nums,int target);
    int upper(vector<int> nums,int target);
    int lower(vector<int> nums, int target);
    
    void test();
};

class PathString{
public:
    vector<string> find(vector<string> board);
    void dfs(vector<string> board,string path,int x, int y,vector<string>& res);
    void test();
};

class AirPort{
public:
    void test();
    vector<string> findPath(vector<pair<string, string>> pairs);
};

class RmoveKthLast{
public:
    void test();
    void removeLastKth(ListNode* root, int k);
    void removeLastKth2(ListNode* root, int k);
};


class Biparite{
public:
    void test();    
    bool isBiparite(vector<vector<int>> graph);
};

class PerimeterShap{
public:
    int findPerimeter(vector<vector<int>> board, vector<int> pos);
    void test();
    bool isShape(vector<int> pos,vector<vector<int>> board);
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
};


class DistanceTwoTreeNodes{
public:
    int findDistance(TreeNode* a, TreeNode* b);
};

class AbsSor{
public:
    vector<int> sortAbs(vector<int> nums);
    void test();
};

class CommonLCA{
public:
    TNode* LCA(TNode* root);
    TNode* dfs(TNode* root, int& depth);
    void test();
};

class TreetoDDL{
public:
    TreeNode* toDDL(TreeNode* root);
    void test();
    void link(TreeNode* root, TreeNode* & prev, TreeNode* & head);
};

class RandomKNumbersFromStream{
    vector<int> getRandom(int k , int stream[],int n);
};

class KthLarget{
    //10:32
public:
    int findKthLargest(TreeNode* root,int k);
    void test();
};

class AbletoBuildTree{
public:
    bool ableToBuild(vector<TreeNode*> nodes);
    void test();
};

class LongestSubstringKDistinct{
public:
    int lengthOfLongestSubstringKDistinct(char str[],int k);
};

class RainDrop{
public:
    //10:11
    void mergeInterval(){
        
    }
};

class RemoveSubtreeSumZero{
public:
    void removeSubtree(TreeNode* root){
            
    }
    
};
//
//class MazeExit{
//public:
//    vector<vector<int>> dirs = {{0,-1},{1,0},{0,1},{-1,0}};
//    bool moveForward();
//    void turnRight();
//    bool findExit();
//    
//    bool dfs(vector<int> cur, set<vector<int>>& visited, vector<int> exit,int d);
//};

class Evalueation{
public:
    int evaluate(string str);
};
