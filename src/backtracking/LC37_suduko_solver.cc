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
    //��¼baord�ϵ�����

    double k = 0;
    
    
    for (int i = 0; i < board.size(); i++) {
        
        for (int j = 0; j < (board.at(i)).size(); j++) {
            cout << board[i][j] << " ****";
            if (board[i][j] != ".") {
                vector<int> temp1;
                if(column_map.count(j) != 0) {
                    cout << "yes";    
                }

                auto iter =  column_map.find(j);
                temp1 = iter->second;
                int temp1_size = temp1.size();
                for (int a = 0; a < temp1_size; a++) {
                    cout << temp1.at(a) << " ";
                }
                temp1.push_back(stoi(board[i][j]));
                
                cout  << endl;
                iter->second = (j, temp1);
                //���¼�ֵ =(key, value);����ʹ��{key, value}������ʹ��pair<type ,type>
                //insert(pair<type, type>(key,value)) ���� insert.({key, value})

                    /*                 insert���������鷽��������

                    Insert�������ܸ��ǣ�������Ѿ����ڣ������ʧ��

                    ���鷽����������Ѿ����ڣ�ʹ�����鷽��������ֱ�Ӹ��¼���Ӧ��ֵ�� */

                    /* 4   �������ݺ��޸����� 
                        (1)   string  value   =    PeopleMap[333]; 
                                PeopleMap[333]  =   string(��lilei��); 
                        
                        (2)     mapPeopleType  ::iterator  Itr; 
                                Itr = PeopleMap.find("b");  //find(key)
                                value  =   my_Itr->second; 
                                Itr->second   =   new value; */

                
                vector<int> temp2; //qw
                 temp2 = (row_map.find(i))->second;
                temp2.push_back(stoi(board[i][j]));

                
                row_map.insert({i, temp2});
            }else {
                vector<int> temp3 = {i,j}; 
                pending[k] = temp3;
                //pending.insert(pair<double, vector<int>>(k, temp3));
                k++;               
            }
        }
    }

    map<int, vector<int>>::iterator iter;  
  
    for(iter = column_map.begin(); iter != column_map.end(); iter++)  {
        cout<<iter->first << " ";
        int size = (iter->second).size();
        for (int i = 0; i < size ; i++) {
            cout << (iter->second).at(i)<< " "; 
        }
        cout << endl;
    }
  
       
    return 0;
}