#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> res;

vector<string> path;

void back_tracking(int n, int last_index, vector<int>& selected_arr) {
    if (path.size() == n) {
        res.push_back(path);
        return;
    }

    string temp(n,'.');
    

    for (int i = 0; i < n; i++) {
        if (selected_arr.at(i) == 1) {
            continue;
        }

        if ((last_index == 0) && (i == last_index + 1) ) {
            continue;
        }

        if ((last_index == (n-1))  && (i == last_index - 1)) {
            continue;
        }

        if ((i == last_index + 1) || (i == last_index - 1)) {
            continue;
        }
        
        selected_arr.at(i) = 1;
        temp.at(i) = 'Q';
        path.push_back(temp);
        back_tracking(n, i, selected_arr);
        path.pop_back();
        selected_arr.at(i) = 0;
        temp.at(i) = '.';
    }
}

int main() {

    int n_test = 1;
    vector<int> select_arr(n_test, 0);
    back_tracking(n_test,10000, select_arr);
    for (int i = 0; i < res.size(); i++) {
        for(int j = 0; j < (res[i]).size(); j++) {
            for (int k = 0; k < (res[i][j]).size(); k++) {
                cout << res[i][j][k];
            }

            cout << endl;
        }

        cout << "=========" <<endl;
    }

    

    return 0;
}