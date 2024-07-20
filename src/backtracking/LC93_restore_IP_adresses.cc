#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<string> res;
string path;

void back_tracking(string path, int ip_num, int left, string& s) {

    //��ֹ����
    if (ip_num >= 4) {
        if (left > s.size()-1) { //�ؼ���1 
            res.push_back(path);
        }
        return;
    }
    //ȷ��ÿ��ѡ���ѡ�񼯺� +
    for (int i = left ; i <= min<int>(s.size() - 1,left + 2); i++) { //�ؼ���2�����鴰�ڵ��ұ߽紦��:min<int>(�����ұ߽磬left + �������䳤��)
        if (s.at(left) == '0' && (s.at(i)) != '0') {  //�ؼ���3��ǰ����0��IP�Ĵ���
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
            path.pop_back();                    //�ؼ���4��push_back���پ�Ҫpop_back����
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