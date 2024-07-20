#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<string> res;
string path;

void back_tracking(string path, int ip_num, int left, string& s) {

    //中止条件
    if (ip_num >= 4) {
        if (left > s.size()-1) { //关键点1 
            res.push_back(path);
        }
        return;
    }
    //确定每个选择的选择集合 +
    for (int i = left ; i <= min<int>(s.size() - 1,left + 2); i++) { //关键点2：数组窗口的右边界处理:min<int>(数组右边界，left + 窗口区间长度)
        if (s.at(left) == '0' && (s.at(i)) != '0') {  //关键点3：前导‘0’IP的处理
            return;
        }   
        string select_str =  s.substr(left, i - left + 1);
        int selected = stoi(select_str);
        if (selected > 255) {
            return;
        }

        path.append(s.substr(left, i - left + 1));
        int push_num;

        if (ip_num <3) {
            path.push_back('.');
            push_num = i - left + 1 + 1;
        }else {
            push_num = i - left + 1;
        }
        
        
        back_tracking(path, ip_num + 1, i + 1, s);

        for (int i = 0; i < push_num; i++) {
            path.pop_back();                    //关键点4：push_back多少就要pop_back多少
        }
        
    }

}

int main() {
    string s_test = "101023";

    back_tracking(path, 0, 0, s_test); 

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < (res.at(i)).size(); j++) {
            cout << res[i][j];
        }

        cout << endl;
    }
    return 0;
}