#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<string>> board;

map<double, vector<int>> pending = {
    {0, {}},
    {1, {}},
    {2, {}},
    {3, {}},
    {4, {}},
    {5, {}},
    {6, {}},
    {7, {}},
    {8, {}},
    {9, {}},

};
map<int, vector<int>> column_map  = {
    {0, {}},
    {1, {}},
    {2, {}},
    {3, {}},
    {4, {}},
    {5, {}},
    {6, {}},
    {7, {}},
    {8, {}},
    {9, {}},

};
map<int, vector<int>> row_map = {
    {0, {}},
    {1, {}},
    {2, {}},
    {3, {}},
    {4, {}},
    {5, {}},
    {6, {}},
    {7, {}},
    {8, {}},
    {9, {}},
};


int main() {
    board = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
    //记录baord上的数据

    
    vector<int> temp = (column_map.find(0)->second);
    temp.push_back(7);
    temp.push_back(9);
    column_map.find(0)->second = temp;
    int size = temp.size();
    for (int i = 0; i < size; i++) {
        cout << temp.at(i);
    }

    return 0;
}