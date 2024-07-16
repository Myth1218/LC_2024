#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;

void back_tracking(int n, int k, int start_index) {
    if (path.size() == k) {
        res.push_back(path);
        return;
    }

    if ((n - start_index + 1) < k) { //¼ôÖ¦ÓÅ»¯
        return;
    }

    for(int i = start_index; i <= n; i++) {
        path.push_back(i);
        back_tracking(n, k, i + 1);
        path.pop_back();
    }

}

int  main() {
    
    back_tracking(5, 2, 1);
    
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < (res[i]).size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

