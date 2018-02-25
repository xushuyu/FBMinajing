//
//  fb.cpp
//  FBMinajing
//
//  Created by Shuyu on 2/3/18.
//  Copyright © 2018 Shuyu. All rights reserved.
//

#include "fb.hpp"
#include "fb.h"


vector<int> FirstOne::findFirstOne(vector<vector<int> > board){
    if(board.empty())
        return {INT_MAX,INT_MAX};
    
    int x = -1, y = -1;
    int m = board.size(), n = board[0].size();
    
    int j, i ;
    for( i = 0; i < m; ++i){
    for( j = 0; j < n; ++j){
            if(board[i][j] == 1)
            {
                x = i; y = j;
                break;
            }
        }
        
        if(board[i][j] == 1) break;
    }
    if( x == -1) return {INT_MAX,INT_MAX};
    
    for( ++i; i < m; ++i){
        
        if(board[i][j] == 0) continue;
        
        while(j-1>=0 && board[i][j-1] == 1){
            --j;
            x=i; y =j;
        }
    }
    
    return {x,y};
}

void FirstOne::test(){
    {
        vector<vector<int>> board = {
            {0,0,0,0,1},
            {0,1,1,1,1},
            {0,0,0,1,1},
            {0,0,1,1,1},
        };
        
        vector<int> res = findFirstOne(board);
        vector<int> exp = {1,1};
        
        if(res != exp)
            cout<<"wrong answer"<<endl;
        else
            cout<<"we good"<<endl;
    }
    
    {
        vector<vector<int>> board = {
            {0,0,0,0,0},
            {0,0,0,0,1},
        };
        
        vector<int> res = findFirstOne(board);
        vector<int> exp = {1,4};
        
        if(res != exp)
            cout<<"wrong answer";
        else
            cout<<"we good"<<endl;
    }
    
    {
        vector<vector<int>> board = {
            {0,0,0,0,0},
            {0,0,1,1,1},
            {1,1,1,1,1}
        };
        
        vector<int> res = findFirstOne(board);
        vector<int> exp = {2,0};
        
        if(res != exp)
            cout<<"wrong answer";
        else
            cout<<"we good"<<endl;
    }
    
    {
        vector<vector<int>> board = {
        };
        
        vector<int> res = findFirstOne(board);
        vector<int> exp = {INT_MAX,INT_MAX};
        
        if(res != exp)
            cout<<"wrong answer";
        else
            cout<<"we good"<<endl;
    }
    
    {
        vector<vector<int>> board = {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        };
        
        vector<int> res = findFirstOne(board);
        vector<int> exp = {INT_MAX,INT_MAX};
        
        if(res != exp)
            cout<<"wrong answer";
        else
            cout<<"we good"<<endl;
    }
}

int Robots::findArea(vector<int> pos){
    set<vector<int>> visited;
    
    dfs({0,0},visited);
    
    return visited.size();
}

void Robots::dfs(vector<int> pos, set<vector<int> > &visited){
    if(visited.count(pos) > 0)
        return;
    
    visited.insert(pos);
    
    if(move(1)){
        dfs({pos[0]+1,pos[1]},visited);
    }
    
    if(move(2)){
        
    }
    
    if(move(3)){
        
    }
    
    if(move(4)){
        
    }
}


ListNode* InsertCycleList::insert(ListNode *node, int n){
    
    ListNode * toAdd = new ListNode(n);
    
    if(!node) {toAdd->next = toAdd; return toAdd;}
    
    ListNode *prev = node, *cur = node->next;
    
    while( prev->next != node){
        if( n >= prev->value && n <= cur->value)
            break;
        
        if(prev->value > cur->value){
            if( n > prev->value || n < cur->value)
                break;
            
        }
        
        prev = prev->next;
        cur = cur->next;
    }
    
    
    prev->next = toAdd;
    toAdd->next = cur;
    
    return toAdd;
}

void InsertCycleList::test(){
    
    {
        
    }
}

int PowMo::powMod(int base, int exp, int md){
    int res = 1;
    int tmp = base%md;
    
    while(exp>0){
        if( exp & 1 )
            res = (res*tmp)%md;
        
        tmp = (tmp*tmp)%md;
        
        exp >>= 1;
    }
    
    return res;
}

void BSTShap::printBst(TreeNode *root){
    if(!root) return;
    
    cout<<" "<<root->val;
    
    
    printLeftEdge(root->left);
    
    printLeaves(root->left);
    printLeaves(root->right);
    
    printRightEdge(root->right);
    
}

void BSTShap::printLeaves(TreeNode *root){
    if(!root) return;
    
    printLeaves(root->left);
    
    if(!root->left && !root->right)
        cout<<" "<<root->val;
    
    printLeaves(root->right);
}

void BSTShap::printLeftEdge(TreeNode *root){
    if(!root) return;
    
    if(root->left){
        cout<<" "<<root->val;
        printLeftEdge(root->left);
    }else if(root->right){
        cout<<" "<<root->val;
        printLeftEdge(root->right);
    }
}

void BSTShap::printRightEdge(TreeNode *root){
    if(!root) return;
    
    if(root->right){
        printRightEdge(root->right);
        cout<<" "<<root->val;
    }else if(root->left){
        printRightEdge(root->left);
        cout<<" "<<root->val;
    }
}

int BinarySearch::search(vector<int> nums, int target){
    if( nums.empty()) return -1;
    
    for(size_t left = 0, right = nums.size()-1; left < right; ){
        size_t mid = (left+right) >> 1;
        
        if(nums[mid] > target){
            right = mid - 1;
        }else if(nums[mid] < target){
            left = mid + 1 ;
        }else{
            return mid;
        }
    }
    
    return -1;
}

int BinarySearch::upper(vector<int> nums, int target){
    if(nums.empty()) return -1;
    
    int left, right;
    for(left = 0, right = (int)nums.size()-1; left < right; ){
        int mid = left + (right-left+1)/2;
        
        if(nums[mid] > target){
            right = mid - 1;
        }else if(nums[mid] < target){
            left = mid + 1;
        }else{
            left = mid;
        }
    }
    
    return left;
}

int BinarySearch::lower(vector<int> nums, int target){
    int n = nums.size();
    int left = 0, right = n-1;
    
    while( left < right ){
        int mid = (left+right+1)/2;
        
        if( nums[mid] > target)
            left = mid + 1;
        else
            right = mid;
    }
    
    return left;
}

void BinarySearch::test(){
    {
        vector<int> nums = {1,1,2,2,4,4,4,5,5,6};
        int target = 6;
        int idx = lower(nums, target);
        
        cout<<idx<<endl;
    }
}

void PathString::dfs(vector<string> board, string path, int x, int y, vector<string> &res){
    int m = board.size();
    int n = board[0].size();
    
    if( x >= m || y >= n) return;
    
    if( x == m-1 && y == n-1){
        path.push_back(board[x][y]);
        res.push_back(path);
        return;
    }
    
    dfs(board,path+board[x][y],x,y+1,res);
   // path.pop_back();
    
    dfs(board,path+board[x][y],x+1,y,res);
    
}

vector<string> PathString::find(vector<string> board){
    vector<string> res;
    if(board.empty()) return res;
    
    
    dfs(board,"",0,0,res);
    return res;
}

void PathString::test(){
    vector<string> board = {
        "abc",
        "edf",
        "xyz"
    };
    
    cout<<"this is board"<<endl;
    
    for(auto str : board){
        for(auto c : str)
            cout<<c;
        cout<<endl;
    }
    
    cout<<endl;
    cout<<endl;

    
    vector<string> res = find(board);
    
    cout<<"this is answer"<<endl;

    for(auto str : res){
        for(auto c : str)
            cout<<c;
        cout<<endl;
    }
}

vector<string> AirPort::findPath(vector<pair<string, string>> pairs){
    vector<string> res;

    if(pairs.empty()) res;
    
    
    unordered_map<string, string> table;
    set<string> check;
    
    for(auto pair : pairs){
        table[pair.first] = pair.second;
        
        check.insert(pair.first);
        
        if(check.count(pair.second) > 0)
            check.erase(pair.second);
    }
    
    if(check.size() == 0) return {};
    
    string start = *check.begin();
    
    while(table.count(start)){
        res.push_back(start);
        start = table[start];
    }
    
    res.push_back(start);
    
    return res;
}

void RmoveKthLast::removeLastKth(ListNode *root, int k){
    if( k < 1 || !root) return;
    ListNode *cur = root;
    
    int i;
    
    for(i = 1; !cur ; ++i ){
        cur = cur->next;
    }
    
    if( k > i) return;
    
    k = i - k + 1;
    
    for( i = 1, cur = root; i < k; ++i){
        cur = cur->next;
    }
    
    ListNode* next = cur->next;
    
    *cur = *next;
    delete next;
    next = nullptr;
}

void RmoveKthLast::removeLastKth2(ListNode *root, int k){
    if( k < 1 || !root) return;
    ListNode *cur = root;
    
    ListNode dummy(-1);
    dummy.next = root;
    
    ListNode* slow = &dummy, *fast = &dummy;
    
    for(int i = 0; i < k && fast; ++i)
        fast = fast->next;
    
    if(!fast) return;
    
    while(fast->next){
        slow =slow->next;
        fast = fast->next;
    }
    
    ListNode* next= slow->next;
    
    if(next){
        slow->next = next->next;
        delete next;
        next = nullptr;
    }
    
    dummy.next = nullptr;
}//1102

void RmoveKthLast::test(){
    ListNode* a1 = new ListNode(1);
    a1->next = new ListNode(2);
    a1->next->next = new ListNode(3);
    a1->next->next->next = new ListNode(4);
    a1->next->next->next->next = new ListNode(5);
    
    ListNode* a2 = a1;

    cout<<"before action"<<endl;
    while(a2){
        cout<<a2->value<<endl;
        a2 = a2->next;
    }
    
    removeLastKth2(a1,5);
    
    cout<<"after action"<<endl;

    while(a1){
        cout<<a1->value<<endl;
        a1 = a1->next;
    }

}

void AirPort::test(){
//    {
//        vector<pair<string, string>> pairs = {
//            {"b","c"},
//            {"d","e"},
//            {"e","f"},
//            {"c","d"},
//            {"a","b"},
//            {"f","g"}
//        };
//
//        vector<string> res = findPath(pairs);
//
//        for(auto city : res)
//            cout<<city<<endl;
//
//    }
    
    {
        vector<pair<string, string>> pairs = {};
        
        vector<string> res = findPath(pairs);
        
        if(res.empty()) cout<<"no anwser";
        
        for(auto city : res)
            cout<<city<<endl;
    }
}

bool Biparite::isBiparite(vector<vector<int>> graph){
    if(graph.empty()) return true;
    
    if(graph.size() != graph[0].size()) return false;
    
    int n = graph.size();
    
    vector<int> color(n,-1); // -1 havn't been visited, 0 type 0, 1 type 1
    
    queue<int> next;
    
    for(int i = 0; i < n; ++i){
        if(color[i] != -1 ) continue;
        
        next.push(i);
        color[i] = 0;
        while (!next.empty()) {
            int cur = next.front();
            next.pop();
            
            if(graph[cur][cur] == 1) return  false;
            
            for(int j = 0; j < n; ++j){
                if(graph[i][j] == 0) continue;
                
                if(color[j] == -1){
                    color[j] = color[cur] == 0 ? 1 : 0;
                    next.push(j);
                }else{
                    if(color[cur] == color[j])
                        return false;
                }
            }
            
        }
    }
    
    return true;
}


void Biparite::test(){
    
}

int PerimeterShap::findPerimeter(vector<vector<int>> board, vector<int> pos){
    int res= 0;
    if(board.empty()) return res;
    
    int m = board.size(), n = board[0].size();
    
    if(board[pos[0]][pos[1]] == 0) return res;
    
    vector<vector<int>> visited(m,vector<int>(n,0));
    queue<vector<int>> next;
    next.push(pos);
    visited[pos[0]][pos[1]] = 1;
    
    while (!next.empty()) {
        auto cur = next.front();
        next.pop();
        
        if(isShape(cur, board))
            ++res;
        
        for(auto dir : dirs){
            int x = pos[0]+dir[0], y = pos[1] + dir[1];
            
            if(visited[x][y])
                continue;
            
            visited[x][y] = 1;
            next.push({x,y});
        }
    }
    
    return res;
}

bool PerimeterShap::isShape(vector<int> pos,vector<vector<int>> board){
    for(auto dir : dirs){
        int x = pos[0] + dir[0], y = pos[1] + dir[1];
        
        if( x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == 0 )
            return true;
    }
    
    return false;
}

int DistanceTwoTreeNodes::findDistance(TreeNode *a, TreeNode *b){
    
    
    return 0;
}

vector<int> AbsSor::sortAbs(vector<int> nums){
    vector<int> res;
    if(nums.empty()) return res;
    
    int low = 0, up = nums.size()-1;
    
    while(low <= up ){
        if(nums[low] < 0){
            int val = -nums[low] > nums[up] ? nums[low++] : nums[up--];
            res.push_back(val);
        }else{
            res.push_back(nums[up--]);
        }
    }
    
    reverse(res.begin(), res.end());
    
    return res;
}

void AbsSor::test(){
    
    vector<int> nums = {-5,-3,-2,-1};
    vector<int> res = sortAbs(nums);

    for( auto num : res)
        cout<<num<<" ";

    cout<<endl;
    
    {
        vector<int> nums = {-15,-13,-8,-1,0,1, 8};
        vector<int> res = sortAbs(nums);

        for( auto num : res)
            cout<<num<<" ";

        cout<<endl;
    }

    {
        vector<int> nums = {1,3,5,9,13};
        vector<int> res = sortAbs(nums);

        for( auto num : res)
            cout<<num<<" ";

        cout<<endl;
    }
    
}

TNode* CommonLCA::LCA(TNode* root){
    int depth = 0;
    TNode* res = dfs(root, depth);
    
    return res;
}

TNode* CommonLCA::dfs(TNode* root, int& depth){
    if(root && root->children.empty() ) {
        depth = 1;
        return root;
    }
    
//    if(!root  ) {
//        depth = 0;
//        return root;
//    }
    
    int maxDepth = 0, cnt = 0, tmpDepth = 0;
    TNode* res = nullptr;
    
    for(auto child : root->children){
        TNode* lca = dfs(child, tmpDepth);
        
        if(tmpDepth + 1 > maxDepth){
            maxDepth = tmpDepth + 1;
            cnt = 1;
            
            res = maxDepth > 2 ? lca : root;
        }else if(tmpDepth + 1 == maxDepth){
            ++cnt;
        }
    }
    
    depth = maxDepth;
    
    if(cnt > 1)
        return root;
    else {
        return res;
    }
}

void CommonLCA::test(){
    TNode* root1 = new TNode(1);
    TNode* root2 = new TNode(2);
    TNode* root3 = new TNode(3);
    TNode* root4 = new TNode(4);
    TNode* root5 = new TNode(5);
    TNode* root6 = new TNode(6);
    TNode* root7 = new TNode(7);
    TNode* root8 = new TNode(8);
    TNode* root9 = new TNode(9);
    TNode* root10 = new TNode(10);
    TNode* root11 = new TNode(11);

    root1->children = {root2,root3,root4};
    root2->children = {root5,root6};
    root3->children = {root9};
    root5->children = {root7};
    root6->children = {root8};
    root7->children = {root10};
    root8->children = {root11};

    TNode* res = LCA(root1);

    if(res)
        cout<<res->val;
    else
        cout<<"NULL!!!!!";

    cout<<endl;

    {
        TNode* root1 = new TNode(1);
        TNode* root2 = new TNode(2);


        root1->children = {root2};

        TNode* res = LCA(root1);

        if(res)
            cout<<res->val;
        else
            cout<<"NULL!!!!!";
        cout<<endl;
        cout<<endl;


    }

    {
        TNode* root1 = new TNode(1);



        TNode* res = LCA(root1);

        if(res)
            cout<<res->val;
        else
            cout<<"NULL!!!!!";
        cout<<endl;
        cout<<endl;

    }
    
    
    {
        TNode* root1 = new TNode(1);
        TNode* root2 = new TNode(2);
        TNode* root3 = new TNode(3);
        TNode* root4 = new TNode(4);
        TNode* root5 = new TNode(5);



        root1->children = {root2};
        root2->children = {root3};
        root3->children = {root4};
        root4->children = {root5};


        TNode* res = LCA(root1);

        if(res)
            cout<<res->val;
        else
            cout<<"NULL!!!!!";

        cout<<endl;
    }
}

TreeNode* TreetoDDL::toDDL(TreeNode* root){
    if(!root) return nullptr;
    TreeNode* prev = nullptr, *head = nullptr;
    link(root, prev, head);
    
    return head;
}

void TreetoDDL::test(){
    
    vector<TreeNode*> nodes;
    
    for(int i = 0; i < 5; ++i){
        
    }
    
}
void TreetoDDL::link(TreeNode* root, TreeNode* & prev, TreeNode* & head){
    if(!root) return;
    
    link(root->left, prev, head);
    
    root->left = prev;
    
    if(prev)
        prev->right = root;
    else
        head = root;
    
    TreeNode* right = root->right;
    root->right = head;
    head->left = root;
    
    prev = root;
    
    link(right, prev, head);
}

vector<int> RandomKNumbersFromStream::getRandom(int k, int stream[],int n){
    vector<int> res;
    
    int i;
    for( i = 0; i < k; ++i)
        res.push_back(stream[i]);
    
    srand(time(nullptr));
    
    for( ;i < n; ++i){
        int j = rand()%(i+1);
        
        if(j <= k)
            res[j] = stream[i];
    }
    
    return res;
}

int KthLarget::findKthLargest(TreeNode* root,int k){
    if(!root) return INT_MAX;
    
    int cnt = 0;
    
    stack<TreeNode*> next;
    while(!next.empty() || root){
        if(root){
            next.push(root);
            root = root->right;
        }else{
             root = next.top();
            next.pop();
            
            if(++cnt == k)
                return root->val;
            
            root = root->left;
        }
    }
    
    return INT_MAX;
}

void KthLarget::test(){
    vector<TreeNode*> nodes;
    for(int i = 0; i < 5; ++i)
        nodes.push_back(new TreeNode(i+1));
    
    nodes[3]->left = nodes[1];
    nodes[3]->right = nodes[4];
    
    nodes[1]->left = nodes[0];
    nodes[1]->right = nodes[2];
    
    int res = findKthLargest(nodes[3],2);
    
    cout<<res;
}

bool AbletoBuildTree::ableToBuild(vector<TreeNode*> nodes){
    int n = nodes.size();
    
    if( n < 2) return false;
    
    unordered_map<TreeNode*, int> degree;
    
    for(auto node : nodes){
        if(node->left)
            ++degree[node->left];
        
        if(node->right)
            ++degree[node->right];
    }
    
    int cnt = 0;
    for(auto node : nodes){
        if(degree[node] == 0)
            ++cnt;
        
        if(cnt == 2) return false;
        
        if(node->left && degree.count(node->left) <= 0)
            return false;
            
        if(node->right && degree.count(node->right) <= 0)
            return false;
    }
    
    return true;
}

void AbletoBuildTree::test(){

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
//    TreeNode* node1 = new TreeNode(1);
//    TreeNode* node1 = new TreeNode(1);
//    TreeNode* node1 = new TreeNode(1);
//    TreeNode* node1 = new TreeNode(1);
    
    node1->left = node2;
    node1->right = node3;
    
    node2->left = node4;
    node3->right = node5;
    
    node6->left = node7;
    
    vector<TreeNode*> nodes = {node4,node3,node2,node1,node6};
    
    if(ableToBuild(nodes))
        cout<<" Yes";
    else
        cout<< " nO";
    
    cout<<endl;
}

template<typename ForwardIterator, typename T>
ForwardIterator lower_bound (ForwardIterator first,
                             ForwardIterator last, T value) {
    while (first != last) {
        auto mid = next(first, distance(first, last) / 2);
        if (value > *mid)   first = ++mid;
        else                last = mid;
    }
    return first;
}


template<typename ForwardIterator, typename T>
ForwardIterator upper_bound (ForwardIterator first,
                             ForwardIterator last, T value) {
    while (first != last) {
        auto mid = next(first, distance (first, last) / 2);
        if (value >= *mid) first = ++mid; // 与 lower_bound 仅此不同
        else                 last = mid;
    }
    return first;
}

int LongestSubstringKDistinct::lengthOfLongestSubstringKDistinct(char str[],int k){
//    int i = 0, j = 0, res = 0;
//
//    //unordered_map<char, int> freq;
//
//    char c = str[i];
//
//    if(freq[c]++ == 0)
//        --k;
//
//    if( k >= 0){
//        res = max(res,i-j+1);
//    }else{
//        while( j <= j){
//
//        }
//    }
    
    return 1;
}
//
//bool MazeExit::findExit(){
////    set<vector<int>> visited;
////    vector<int> exit;
////
////    return dfs({0,0},visited,exit,0);
//    return false;
//}
//
////    vector<vector<int>> dirs = {{0,-1},{1,0},{0,1},{-1,0}};  all for directions 0=up, 1=right 2=down, 3=left
//bool MazeExit::dfs(vector<int> cur, set<vector<int>>& visited, vector<int> exit,int d/*idx for directions*/){
//    if(cur == exit)
//        return true;
//    
//    for(int i = 0; i < 4; ++i){
//        turnRight();
//        d = d+1 > 3 ? 0 : d+1;
//        
//        if(moveForward()){
//            vector<int> newPos = {cur[0]+dirs[d][0],cur[1]+dirs[d][1]};
//            if(visited.count(newPos) <= 0){
//                visited.insert(newPos);
//                dfs(newPos,visited,exit,d);
//            }
//            
//            //set to previous state
//            turnRight();
//            turnRight();
//            moveForward();
//            turnRight();
//            turnRight();
//        }
//    }
//    
//    return false;
//}

int Evalueation::evaluate(string str){
    int res = 0;
    if(str.empty()) return res;
    
    stringstream ss(str);
    string cur;
    
    stack<string> next;
//    (- (+ 2 4) (+ 5 5)) 返回 -4
//    (+ 1 2 3) 返回 6
//    (+ 1 2 4 (+ (+ (- 1 3) 3) 4 (+ 5 4 5 6)) 返回。
    
    while(getline(ss,cur,' ')){
        if(!(!isdigit(cur[0]) && cur.size() == 1)){ // num
            next.push(cur);
        }else{ // + - ( )
            if(cur[0] == ')' ){
                vector<string> nums;
                
                while( !next.empty() && next.top()[0] != '('){
                    nums.push_back(next.top());
                    next.pop();
                }
                
                next.pop();
                
                int sign = nums.back()[0] == '+' ? 1 : -1;
                nums.pop_back();
                
                int sum = stoi(nums.back());
                
                for(int i = 0; i < nums.size()-1; ++i)
                    sum += sign*stoi(nums[i]);
                
                next.push(to_string(sum));
            }else{
                next.push(cur);
            }
        }
    }
    
    if(!next.empty()){
        string tmp = next.top();
        return stoi(tmp);
    }
    else
        return INT_MAX;
}






