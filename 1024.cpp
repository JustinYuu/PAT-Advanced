#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
long long tonum(string s) {
    long long res = 0;
    for (int i = 0; i < s.length(); i++) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}
string tos(long long num) {
    string res = "";
    do {
        res += '0' + num % 10;
        num /= 10;
    } while (num != 0);
    reverse(res.begin(), res.end());
    return res;
}
string add(string s1, string s2) {
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string s3="";
    int carry = 0;
    int i = 0;
    for (i; i < s1.length() && i < s2.length(); i++) {
        int tmp1 = s1[i] - '0';
        int tmp2 = s2[i] - '0';
        int tmp = tmp1 + tmp2 + carry;
        s3 += tmp % 10 + '0';
        carry = tmp / 10;
    }
    if (s1.length() > s2.length()) {
        while(i<s1.length()){
            if (carry != 0) {
                int tmp1 = s1[i] - '0';
                tmp1 += carry;
                s3 += tmp1 % 10 + '0';
                carry = tmp1 / 10;
                i++;
            }
            else break;
        }
        if (carry != 0) s3 += '0' + carry;
        else if (i < s1.length()) {
            s3 += s1.substr(i, s1.length() - i);
        }
    }
    else if (s1.length() < s2.length()) {
        while (i < s2.length()) {
            if (carry != 0) {
                int tmp1 = s2[i] - '0';
                tmp1 += carry;
                s3 += tmp1 % 10 + '0';
                carry = tmp1 / 10;
                i++;
            }
            else break;
        }
        if (carry != 0) s3 += '0' + carry;
        else if (i < s2.length()) {
            s3 += s2.substr(i, s2.length() - i);
        }
    }
    else if (s1.length() == s2.length()) {
        if (carry != 0) s3 += '0' + carry;
    }
    reverse(s3.begin(), s3.end());

    return s3;
}
bool pali(string s) {
    string s2, s3;
    s2 = s;
    s3 = s;
    reverse(s2.begin(), s2.end());
    if (s2 == s3)return true;
    else return false;
}
int main() {
    string s;
    int k;
    cin >> s >> k;
    int j = 0;
    string s_2;
    s_2 = s;
    if (!pali(s)) {
        for (j = 1; j <= k; j++) {
            s_2 = s;
            reverse(s_2.begin(), s_2.end());
            s = add(s, s_2);
            if (pali(s))break;
        }
    }
    if (j == k + 1)j--;
    cout << s << endl << j;
    system("pause");
}
