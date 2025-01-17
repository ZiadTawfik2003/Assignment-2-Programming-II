#include "BigReal.h"
#include <bits/stdc++.h>
using namespace std;

bool bigreal :: isValid(std::string s) {
    int ctr{};
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '.')
            ctr++;
    }
    if (ctr > 1) {
        return false;
    } else {
        return true;
    }
}
bool bigreal :: operator>( bigreal a) {
    if (!(isValid(number) && isValid(a.number))) {
        not_valid();
        exit(0);
    }
    bool neg1;
    neg1 = a.neg;
    if (neg && !neg1) {
        return false;
    }
    else if (!neg && neg1) {
        return true;
    }
    else if (neg && neg1) {
        int ctr1{},ctr2{},ind1{},ind2{};
        for (int i = 1; i < number.length(); ++i) {
            if (number[i] == '.') {
                ind1 = i;
                break;
            } else {
                ctr1++;
            }
        }
        for (int i = 1; i < a.number.length(); ++i) {
            if (a.number[i] == '.') {
                ind2 = i;
                break;
            } else {
                ctr2++;
            }
        }
        if (ctr1 > ctr2) {return false;}
        else if (ctr1 < ctr2) {return true;}
        else {
            for (int i = 1; i < ind1; ++i) {
                if ((number[i]-'0') > (a.number[i] - '0')) {
                    return false;
                } else if ((number[i]-'0') < (a.number[i] - '0')) {
                    return true;
                }
            }
            int diff1 = number.length()-ind1,diff2 = a.number.length()-ind2;
            if (diff1 <= diff2) {
                for (int i = ind1+1; i < number.length(); ++i) {
                    if ((number[i]-'0') > (a.number[i] - '0')) {
                        return false;
                    } else if ((number[i]-'0') < (a.number[i] - '0')) {
                        return true;
                    }
                }
                return false;
            } else {
                for (int i = ind2+1; i < a.number.length(); ++i) {
                    if ((number[i]-'0') > (a.number[i] - '0')) {
                        return false;
                    } else if ((number[i]-'0') < (a.number[i] - '0')) {
                        return true;
                    }
                }
                return false;
            }
        }
    } else {
        int ctr1{},ctr2{},ind1{},ind2{};
        for (int i = 0; i < number.length(); ++i) {
            if (number[i] == '.') {
                ind1 = i;
                break;
            } else {
                ctr1++;
            }
        }
        for (int i = 0; i < a.number.length(); ++i) {
            if (a.number[i] == '.') {
                ind2 = i;
                break;
            } else {
                ctr2++;
            }
        }
        if (ctr1 > ctr2) {return true;}
        else if (ctr1 < ctr2) {return false;}
        else {
            for (int i = 0; i < ind1; ++i) {
                if ((number[i]-'0') > (a.number[i] - '0')) {
                    return true;
                } else if ((number[i]-'0') < (a.number[i] - '0')) {
                    return false;
                }
            }
            int diff1 = number.length()-ind1,diff2 = a.number.length()-ind2;
            if (diff1 <= diff2) {
                for (int i = ind1+1; i < number.length(); ++i) {
                    if ((number[i]-'0') > (a.number[i] - '0')) {
                        return true;
                    } else if ((number[i]-'0') < (a.number[i] - '0')) {
                        return false;
                    }
                }
                return false;
            } else {
                int k{};
                for (int i = ind2+1; i < a.number.length(); ++i) {
                    if ((number[i]-'0') > (a.number[i] - '0')) {
                        return true;
                    } else if ((number[i]-'0') < (a.number[i] - '0')) {
                        return false;
                    }
                    k = i;
                }
                for (int i = k+1; i < number.length(); ++i) {
                    if (number[i] - '0' > 0) {
                        return true;
                    }
                }
                return false;
            }
        }
    }
}
bool bigreal :: operator<(bigreal a) {
    if (!(isValid(number) && isValid(a.number))) {
        not_valid();
        exit(0);
    }
    bool neg1;
    neg1 = a.neg;
    if (neg && !neg1) {
        return true;
    }
    else if (!neg && neg1) {
        return false;
    }
    else if (neg && neg1) {
        int ctr1{},ctr2{},ind1{},ind2{};
        for (int i = 1; i < number.length(); ++i) {
            if (number[i] == '.') {
                ind1 = i;
                break;
            } else {
                ctr1++;
            }
        }
        for (int i = 1; i < a.number.length(); ++i) {
            if (a.number[i] == '.') {
                ind2 = i;
                break;
            } else {
                ctr2++;
            }
        }
        if (ctr1 > ctr2) {return true;}
        else if (ctr1 < ctr2) {return false;}
        else {
            for (int i = 1; i < ind1; ++i) {
                if ((number[i]-'0') > (a.number[i] - '0')) {
                    return true;
                } else if ((number[i]-'0') < (a.number[i] - '0')) {
                    return false;
                }
            }
            int diff1 = number.length()-ind1,diff2 = a.number.length()-ind2;
            if (diff1 <= diff2) {
                int k{};
                for (int i = ind1+1; i < number.length(); ++i) {
                    if ((number[i]-'0') > (a.number[i] - '0')) {
                        return true;
                    } else if ((number[i]-'0') < (a.number[i] - '0')) {
                        return false;
                    }
                    k = i;
                }
                for (int i = k+1; i < a.number.length(); ++i) {
                    if (a.number[i] - '0' > 0) {
                        return true;
                    }
                }
                return false;
            } else {
                for (int i = ind2+1; i < a.number.length(); ++i) {
                    if ((number[i]-'0') > (a.number[i] - '0')) {
                        return false;
                    } else if ((number[i]-'0') < (a.number[i] - '0')) {
                        return true;
                    }
                }
                return false;
            }
        }
    } else {
        int ctr1{},ctr2{},ind1{},ind2{};
        for (int i = 0; i < number.length(); ++i) {
            if (number[i] == '.') {
                ind1 = i;
                break;
            } else {
                ctr1++;
            }
        }
        for (int i = 0; i < a.number.length(); ++i) {
            if (a.number[i] == '.') {
                ind2 = i;
                break;
            } else {
                ctr2++;
            }
        }
        if (ctr1 > ctr2) {return false;}
        else if (ctr1 < ctr2) {return true;}
        else {
            for (int i = 0; i < ind1; ++i) {
                if ((number[i]-'0') > (a.number[i] - '0')) {
                    return false;
                } else if ((number[i]-'0') < (a.number[i] - '0')) {
                    return true;
                }
            }
            int diff1 = number.length()-ind1,diff2 = a.number.length()-ind2;
            if (diff1 <= diff2) {
                int k {};
                for (int i = ind1+1; i < number.length(); ++i) {
                    if ((number[i]-'0') > (a.number[i] - '0')) {
                        return false;
                    } else if ((number[i]-'0') < (a.number[i] - '0')) {
                        return true;
                    }
                    k = i;
                }
                for (int i = k+1; i < a.number.length(); ++i) {
                    if (a.number[i] - '0' > 0) {
                        return true;
                    }
                }
                return false;
            } else {
                for (int i = ind2+1; i < a.number.length(); ++i) {
                    if ((number[i]-'0') > (a.number[i] - '0')) {
                        return true;
                    } else if ((number[i]-'0') < (a.number[i] - '0')) {
                        return false;
                    }
                }
                return false;
            }
        }
    }
}
bool bigreal :: operator==(bigreal a) {
    if (!(isValid(number) && isValid(a.number))) {
        not_valid();
        exit(0);
    }
    if (!(*this > a) && !(*this < a)) {
        return true;
    } else {
        return false;
    }
}
bigreal bigreal :: operator+(bigreal a) {
    if (!(isValid(number) && isValid(a.number))) {
        not_valid();
        exit(0);
    }
    bigreal c;
    if (!neg && !neg) {
        int ind1{},ind2{};
        for (int i = 0; i < number.length(); ++i) {
            if (number[i] == '.') {
                ind1 = i;
                break;
            }
        }
        for (int i = 0; i < a.number.length(); ++i) {
            if (a.number[i] == '.') {
                ind2 = i;
                break;
            }
        }
        if (!ind1 && ind2) {
            int car{};
            if (ind2 <= number.length()) {
                for (int i = a.number.length()-1; i >= ind2; --i) {
                    c.number += a.number[i];
                }
                string n_num (number.length()-ind2,'0');
                for (int i = 0; i < ind2; ++i) {
                    n_num += a.number[i];
                }
                for (int i = number.length()-1; i >= 0; i--) {
                    int sum = (number[i] - '0')+(n_num[i] - '0');
                    sum += car;
                    if (sum < 10) {
                        c.number += (sum + '0');
                        car = 0;
                    } else {
                        string ch = to_string(sum);
                        c.number += ch[1];
                        car = 1;
                    }
                }
            } else {
                for (int i = a.number.length()-1; i >= ind2; --i) {
                    c.number += a.number[i];
                }
                string n_num (ind2-number.length(),'0');
                for (int i = 0; i < number.length(); ++i) {
                    n_num += number[i];
                }
                for (int i = n_num.length()-1; i >= 0; i--) {
                    int sum = (n_num[i] - '0')+(a.number[i] - '0');
                    sum += car;
                    if (sum < 10) {
                        c.number += (sum + '0');
                        car = 0;
                    } else {
                        string ch = to_string(sum);
                        c.number += ch[1];
                        car = 1;
                    }
                }
            }
            if (car) {
                c.number += (car + '0');
            }
            reverse(c.number.begin(),c.number.end());
            return c;
        } else if (ind1 && !ind2) {
            int car{};
            string temp1 = number,temp2 = a.number;
            number = temp2;
            a.number = temp1;
            int temp3 = ind1,temp4 = ind2;
            ind1 = temp4;
            ind2 = temp3;
            if (ind2 <= number.length()) {
                for (int i = a.number.length()-1; i >= ind2; --i) {
                    c.number += a.number[i];
                }
                string n_num (number.length()-ind2,'0');
                for (int i = 0; i < ind2; ++i) {
                    n_num += a.number[i];
                }
                for (int i = number.length()-1; i >= 0; i--) {
                    int sum = (number[i] - '0')+(n_num[i] - '0');
                    sum += car;
                    if (sum < 10) {
                        c.number += (sum + '0');
                        car = 0;
                    } else {
                        string ch = to_string(sum);
                        c.number += ch[1];
                        car = 1;
                    }
                }
            } else {
                for (int i = a.number.length()-1; i >= ind2; --i) {
                    c.number += a.number[i];
                }
                string n_num (ind2-number.length(),'0');
                for (int i = 0; i < number.length(); ++i) {
                    n_num += number[i];
                }
                for (int i = n_num.length()-1; i >= 0; i--) {
                    int sum = (n_num[i] - '0')+(a.number[i] - '0');
                    sum += car;
                    if (sum < 10) {
                        c.number += (sum + '0');
                        car = 0;
                    } else {
                        string ch = to_string(sum);
                        c.number += ch[1];
                        car = 1;
                    }
                }
            }
            if (car) {
                c.number += ('1');
            }
            number = temp1;
            a.number = temp2;
            reverse(c.number.begin(),c.number.end());
            return c;
        } else if (!ind1 && !ind2) {
            if (number.length() >= a.number.length()) {
                string n_num(number.length()-a.number.length(),'0');
                for (int i = 0; i < a.number.length(); ++i) {
                    n_num += a.number[i];
                }
                int car{};
                for (int i = number.length()-1; i >= 0;i--) {
                    int sum = (n_num[i] - '0')+(number[i] - '0');
                    sum += car;
                    if (sum < 10) {
                        c.number += (sum + '0');
                        car = 0;
                    } else {
                        string ch = to_string(sum);
                        c.number += ch[1];
                        car = 1;
                    }
                }
                if (car) {
                    c.number += '1';
                }
                reverse(c.number.begin(),c.number.end());
                return c;
            } else if (number.length() < a.number.length()) {
                string n_num(a.number.length()-number.length(),'0');
                for (int i = 0; i < number.length(); ++i) {
                    n_num += number[i];
                }
                int car{};
                for (int i = a.number.length()-1; i >= 0;i--) {
                    int sum = (n_num[i] - '0')+(a.number[i] - '0');
                    sum += car;
                    if (sum < 10) {
                        c.number += (sum + '0');
                        car = 0;
                    } else {
                        string ch = to_string(sum);
                        c.number += ch[1];
                        car = 1;
                    }
                }
                if (car) {
                    c.number += '1';
                }
                reverse(c.number.begin(),c.number.end());
                return c;
            }
        }
        else if (ind1 >= ind2) {
            int h = ind1-ind2;
            string n_num(h,'0');
            for (int i = 0; i < a.number.length(); ++i) {
                n_num += a.number[i];
            }
            int car{};
            int k = number.length();
            if (number.length() > n_num.length()) {
                for (int i = number.length()-1; i >= n_num.length() ; i--) {
                    c.number += number[i];
                    k = i;
                }
            } else {
                for (int i = n_num.length()-1; i >= number.length() ; i--) {
                    c.number += n_num[i];
                    k = i;
                }
            }

            for (int i = k-1; i >= 0; i--) {
                if (number[i] == '.') {
                    c.number += '.';
                    continue;
                }
                int sum = (number[i] - '0')+(n_num[i] - '0');
                sum += car;
                if (sum < 10) {
                    c.number += (sum + '0');
                    car = 0;
                } else {
                    string ch = to_string(sum);
                    c.number += ch[1];
                    car = 1;
                }
            }
            if (car) {
                c.number += (car + '0');
            }
            reverse(c.number.begin(),c.number.end());
            return c;
        } else if (ind2 > ind1) {
            int h = ind2-ind1;
            string n_num(h,'0');
            string temp1 = a.number,temp2 = number;
            number = temp1;
            a.number = temp2;
            for (int i = 0; i < a.number.length(); ++i) {
                n_num += a.number[i];
            }

            int car{};
            int k = number.length();
            if (number.length() > n_num.length()) {
                for (int i = number.length()-1; i >= n_num.length() ; i--) {
                    c.number += number[i];
                    k = i;
                }
            } else {
                for (int i = n_num.length()-1; i >= number.length() ; i--) {
                    c.number += n_num[i];
                    k = i;
                }
            }

            for (int i = k-1; i >= 0; i--) {
                if (number[i] == '.') {
                    c.number += '.';
                    continue;
                }
                int sum = (number[i] - '0')+(n_num[i] - '0');
                sum += car;
                if (sum < 10) {
                    c.number += (sum + '0');
                    car = 0;
                } else {
                    string ch = to_string(sum);
                    c.number += ch[1];
                    car = 1;
                }
            }
            if (car) {
                c.number += (car + '0');
            }
            reverse(c.number.begin(),c.number.end());
            number = temp2;
            a.number = temp1;
            return c;
        }
    }
}

ostream & operator << (ostream& out, bigreal a) {
    return out << a.number << endl;
}
bigreal bigreal::operator-(bigreal a) {
    if (number > a.number) {
        if (!(isValid(number) && isValid(a.number))) {
            not_valid();
            exit(0);
        }
        bigreal c;

        int ind1 = number.find('.');
        int ind2 = a.number.find('.');

        if (ind1 == std::string::npos) {
            ind1 = number.length();
        }
        if (ind2 == std::string::npos) {
            ind2 = a.number.length();
        }

        while (number.length() - ind1 < a.number.length() - ind2) {
            number += '0';
        }
        while (a.number.length() - ind2 < number.length() - ind1) {
            a.number += '0';
        }

        int borrow = 0;
        int diff;

        for (int i = number.length() - 1; i >= 0; i--) {
            if (number[i] == '.') {
                c.number = '.' + c.number;
                continue;
            }

            int num1 = (number[i] - '0');
            int num2 = (a.number[i] - '0');

            diff = num1 - num2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            c.number = char(diff + '0') + c.number;
        }
// when the rersult = 0 it prints more than zero:
        while (c.number.length() > 1 && c.number[0] == '0' && c.number[1] != '.') {
            c.number = c.number.substr(1);
        }

        return c;
    }
    else if (number < a.number) {
        string temp ;
        temp=a.number;
        a.number=number;
        number=temp;
        if (!(isValid(number) && isValid(a.number))) {
            not_valid();
            exit(0);
        }
        bigreal c;

        int ind1 = number.find('.');
        int ind2 = a.number.find('.');

        if (ind1 == std::string::npos) {
            ind1 = number.length();
        }
        if (ind2 == std::string::npos) {
            ind2 = a.number.length();
        }

        while (number.length() - ind1 < a.number.length() - ind2) {
            number += '0';
        }
        while (a.number.length() - ind2 < number.length() - ind1) {
            a.number += '0';
        }

        int borrow = 0;
        int diff;

        for (int i = number.length() - 1; i >= 0; i--) {
            if (number[i] == '.') {
                c.number = '.' + c.number;
                continue;
            }

            int num1 = (number[i] - '0');
            int num2 = (a.number[i] - '0');

            diff = num1 - num2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            c.number = char(diff + '0') + c.number;

        }
// when the rersult = 0 it prints more than zero:
        while (c.number.length() > 1 && c.number[0] == '0' && c.number[1] != '.') {
            c.number = c.number.substr(1);
        }
        c.number = "-"+c.number;
        return c;

    }
}
