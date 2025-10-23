#include <iostream>
#include <string>
using namespace std;

#define MAX 256 


bool isNum(char c){ 
    return (c >= '0' && c <= '9'); 
}
bool isOp(char c) { 
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^'); 
}

int prec(char op) {
    if(op == '^') 
        return 3;
    if(op=='*' || op=='/') 
        return 2;
    if(op=='+' || op=='-') 
        return 1;
    return 0;
}


bool rightAssoc(char op) { 
    return (op=='^'); 
}

//no negtive powers
int ipow(int a, int b) {
    if(b < 0) return 0; 
    int r = 1;
    while(b--){
        r *= a;
    } 
    return r;
}


string toPostfix(const string &s) {
    char opStk[MAX];
    int top = -1;
    string out = "";

    for(int i = 0; i < s.size(); ) {
        char ch = s[i];

        if(ch == ' ') { 
            i++; continue; 
        } 

        if(isNum(ch)) {
            int start = i;
            while(i < s.size() && isNum(s[i])) {
                i++;
            } 
            out += s.substr(start, i - start);
            out += ' ';
            continue;
        }
        else if(ch == '(') {
            opStk[++top] = ch;
            i++;
        }
        else if(ch == ')') {
            while(top >= 0 && opStk[top] != '(') {
                out += opStk[top--];
                out += ' ';
            }
            if(top >= 0 && opStk[top] == '(') top--; 
            i++;
        }
        else if(isOp(ch)) {
            while(top >= 0 && opStk[top] != '(' &&(prec(opStk[top]) > prec(ch) ||(prec(opStk[top]) == prec(ch) && !rightAssoc(ch)))) {
                out += opStk[top--];
                out += ' ';
            }
            opStk[++top] = ch; 
            i++;
        }
        else {
            i++;
        }
    }

    while(top >= 0) {
        if(opStk[top] != '(' && opStk[top] != ')') {
            out += opStk[top];
            out += ' ';
        }
        top--;
    }

    return out;
}

int evalPostfix(const string &p) {
    int st[MAX];
    int t = -1;

    for(size_t i = 0; i < p.size(); ) {
        if(p[i] == ' ') { i++; continue; }

        if(isNum(p[i])) {
            int num = 0;
            while(i < p.size() && isNum(p[i])) {
                num = num * 10 + (p[i] - '0');
                i++;
            }
            st[++t] = num;
        }
        else if(isOp(p[i])) {
            if(t < 1) return 0; 
            char op = p[i++];
            int b = st[t--];
            int a = st[t--];
            int r = 0;

            if(op == '+') r = a + b;
            else if(op == '-') r = a - b;
            else if(op == '*') r = a * b;
            else if(op == '/') r = (b == 0) ? 0 : (a / b);
            else if(op == '^') r = ipow(a, b);

            st[++t] = r;
        }
        else {
            i++;
        }
    }

    return (t >= 0) ? st[t] : 0;
}

int main() {
    //only + - * / ^ and parentheses
    string infix;
    cout << "enter infix:" << endl;
    getline(cin, infix);

    string post = toPostfix(infix);
    cout << "postfix: " << post << endl;

    int val = evalPostfix(post);
    cout << "value: " << val << endl;

    return 0;
}