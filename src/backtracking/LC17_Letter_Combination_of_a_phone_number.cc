#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> letter_map = {
    "",     //0
    "",     //1
    "abc",  //2
    "edf",   //3
    "ghi",     //4
    "jkl",     //5
    "mno",  //6
    "pqrs",   //7
    "tuv",     //8
    "wxyz",     //9
};

vector<string> res;
string path;

void back_tracking( string& digits, int digits_ind) {
    //选择结束的条件
    if (path.size() == digits.size()) {
        res.push_back(path);
        return;
    }

    //确定待选择的字母集合
    int ind =  digits[digits_ind] -'0';
    string letters = letter_map.at(ind);
    int letters_size = letters.size();
    
    //针对不同选择项进行选择
    for (int i = 0; i < letters_size; i++) {
        path.push_back( letters.at(i));
        back_tracking(digits, digits_ind + 1);
        path.pop_back();
    }
}


int main(){
    string digits ="";
    back_tracking(digits,0);

    for (int i = 0 ; i < res.size(); i++) {
        for (int j = 0; j < (res.at(i)).size(); j++) {
            cout << res[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}
