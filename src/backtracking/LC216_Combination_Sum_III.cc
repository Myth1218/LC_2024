#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;


void back_tracking(int n, int k, int current_sum, int start_index) {
    if (current_sum > n) {  //剪枝操作1：在选择的个数未满足条件前，已选择数的和就已经>n了，剪枝优化掉
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

    for (int i = start_index; i <= 9 - (k - path.size()) + 1; i++) { //剪枝操作2：剩下的数不够选择了，剪枝
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