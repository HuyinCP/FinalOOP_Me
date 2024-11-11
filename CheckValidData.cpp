#include <bits/stdc++.h>
using namespace std;

bool isValidDate(string& s) {
    #define all(x) x.begin(), x.end()
    s.erase(remove(all(s), ' '), s.end());
    //kiểm tra ngày có hợp lệ với tháng đó không
    auto valid = [](int day, int month, int year) { 
        if (year < 1 || month < 1 || month > 12) return false;
        int daysInMonth = 31;
        if (month == 4 || month == 6 || month == 9 || month == 11) daysInMonth = 30;
        else if (month == 2) daysInMonth = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;
        return day >= 1 && day <= daysInMonth;
    };

    //kiểm tra nếu tồn tại kí tự là chữ hoặc kí tự đặc biệt (trừ '/')
    auto hasSpecialOrAlphabet = [](const string &S) {
        for (char c : S) if (!isdigit(c) && !isspace(c) && c != '/') return true;
        return false;
    };

    //tách string thành day-month-year và kiểm tra dự liệu
    auto check = [&](const string& S) -> bool { 
        if (count(all(S), '/') != 2 || hasSpecialOrAlphabet(S)) return false;
        vector<string> ret;
        stringstream ss(S);
        string token;
        while (getline(ss, token, '/')) {
            if (token.empty() || !all_of(token.begin(), token.end(), ::isdigit)) return false;
            ret.push_back(token);
        }
        if (ret.size() != 3) return false;
        return valid(stoi(ret[0]), stoi(ret[1]), stoi(ret[2]));
    };
    return (check(s) ? true : false);
}

int main() {
    string s = "21/ 1   0 /1";
    if (isValidDate(s)) cout << "YES";
    else cout << "NO"; 
    return 0;
}