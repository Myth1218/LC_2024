#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;


void back_tracking(int n, int k, int current_sum, int start_index) {
    if (current_sum > n) {  //��֦����1����ѡ��ĸ���δ��������ǰ����ѡ�����ĺ;��Ѿ�>n�ˣ���֦�Ż���
        return;
    }
    
    if (path.size() == k) {
        if (current_sum == n) {
            res.push_back(path);
            return;
        }else{
            return;
        }   
    }

    for (int i = start_index; i <= 9 - (k - path.size()) + 1; i++) { //��֦����2��ʣ�µ�������ѡ���ˣ���֦
        path.push_back(i);
        back_tracking(n, k, current_sum + i, i + 1);
        path.pop_back();
    }
}

int main() {
    back_tracking(9, 3, 0, 1);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}