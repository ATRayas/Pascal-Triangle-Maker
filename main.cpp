#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Alejandro Rayas
//this will handle making the next row in line for construction
vector<int> rowsMake(vector <vector<int>> tempTree, int levelCount){
    vector<int> temp;
    temp.push_back(1);
    for(int i = 0; i < tempTree[levelCount - 1].size() - 1; i++){
        temp.push_back(tempTree[levelCount - 1][i] + tempTree[levelCount - 1][i + 1]);
    }
    temp.push_back(1);
    return temp;
}
int main() {
    string line;
    vector <vector<int>> tree;
    vector<int> rows;
    while (getline(cin, line)) {
        //cout << line << endl;
        int depth = stoi(line);
        int levelCounter = 0;
        if(depth == 0){
            cout << "0";
            return 0;
        }
        if(depth == 1){
            cout << "1";
            return 0;
        }
        if(depth == 2){
            cout << "1 1 1";
            return 0;
        }
        //initial construction of tree that would't make sense with
        //rowMake method
        rows.push_back(1);
        tree.push_back(rows);
        rows.pop_back();
        levelCounter++;
        rows.push_back(1);
        rows.push_back(1);
        tree.push_back(rows);
        rows.pop_back();
        rows.pop_back();
        levelCounter++;

        //we keep making rows until our levelCounter reaches the depth
        //that was specified from our input
        while(levelCounter < depth){
            rows = rowsMake(tree, levelCounter);
            tree.push_back(rows);
            levelCounter++;

        }
        for (int i = 0; i < tree.size(); i++)
        {
            for (int j = 0; j < tree[i].size(); j++)
            {
                cout << tree[i][j] << " ";
            }
        }

    }
    return 0;
}