#include <vector>
#include <iostream>
#include <unordered_set>
#include <fstream>

using namespace std;

struct TreeNode{
    int index;  // 节点索引
    unordered_set<int> label;   // 节点标签
    vector<TreeNode*> children;  // 节点

    TreeNode(int index):index(index){}
};

void dealLabel(TreeNode* node, int label){
    node->label.insert(label);

    for(auto c: node->children){
         dealLabel(c, label);
    }
   
    return;
}

int LabelSum(TreeNode* node){
    int count = 0;
    
    for(auto l : node->label){
        count += l;
    }

    for(auto c: node->children){
        count += LabelSum(c);
    }

    return count;
}

void buildTree(TreeNode* node, int NodeNum, vector<bool>& isUsed_vec, unordered_map<int, TreeNode*>& indexTreeNode_map, vector<vector<int>> input){
    
    int index = node->index;

    for(int i = 1; i < NodeNum; ++i){
        if(isUsed_vec[i-1] == true){
            continue;
        }

        int f = input[i][0];
        int c = input[i][1];

        if(f != index && c != index){
            continue;
        }else if(c == index){
            swap(f,c);
        }

        TreeNode* fnode = indexTreeNode_map[f];
        TreeNode* cnode = new TreeNode(c);

        fnode->children.push_back(cnode);

        indexTreeNode_map[c] = cnode;
        isUsed_vec[i-1] = true;
    }

    for(auto c : node->children){
        buildTree(c, NodeNum, isUsed_vec, indexTreeNode_map, input);
    }
}

int calSumLable(vector<vector<int>> input){

    // 参数检验
    if(input.empty()){
        return 0;
    }
    
    vector<int> NodeNumAndLabelNum = input[0];
    
    int NodeNum = NodeNumAndLabelNum[0];
    int LabelNum = NodeNumAndLabelNum[1];

    // 构建树
    TreeNode* root = new TreeNode(1);

    unordered_map<int, TreeNode*> indexTreeNode_map;
    indexTreeNode_map[1] = root;

    vector<bool> isUsed_vec(NodeNum-1, false);

    buildTree(root, NodeNum, isUsed_vec, indexTreeNode_map, input);

    // 打标签，递归
    for(int i = NodeNum; i < input.size(); ++i){
        vector<int> numOfLabel = input[i];
        TreeNode* node = indexTreeNode_map[numOfLabel[0]];
        dealLabel(node, numOfLabel[1]);
    }

    // 计算总和
    return LabelSum(root);

}

int main(){

    ifstream fin("./input.txt");
    if (!fin.is_open()) {
        cerr << "无法打开输入文件！" << endl;
        return -1;
    }

    vector<vector<int>> input;

    int M, N;
    char comma; // 用于读取逗号
    fin >> M >> comma >> N; // 读入节点数和操作数
    input.push_back({M,N});

    for(int i = 0; i < M-1+N ; i++){
        int a, b;
        fin >> a >> comma >> b;
        input.push_back({a,b});
    }
    cout << "hello world:" <<  calSumLable(input) << endl;
    return 0;
}


