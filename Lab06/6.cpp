#include <iostream>
#include <string>
using namespace std;

#define MAX 256

bool isNum(char c){
    return (c >= '0' && c <= '9');
}
bool isOp(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}
int prec(char op){
    if(op=='^')return 3;
    if(op=='*' || op=='/')return 2;
    if(op=='+' || op=='-')return 1;
    return 0;
}
bool rightAssoc(char op){
    return (op=='^');
}
int ipow(int a,int b){
    if(b<0)return 0;
    int r=1;
    while(b--)r*=a;
    return r;
}

//reverse string manually
string rev(const string&s){
    string r="";
    for(int i=s.size()-1;i>=0;i--)r+=s[i];
    return r;
}

string toPrefix(const string&s){
    char opStk[MAX];
    int top=-1;
    string out="";

    string exp=rev(s);
    for(int i=0;i<exp.size();i++){
        if(exp[i]=='(')exp[i]=')';
        else if(exp[i]==')')exp[i]='(';
    }

    for(int i=0;i<exp.size();){
        char ch=exp[i];
        if(ch==' '){i++;continue;}
        if(isNum(ch)){
            int start=i;
            while(i<exp.size() && isNum(exp[i]))i++;
            out+=exp.substr(start,i-start);
            out+=' ';
            continue;
        }
        else if(ch=='('){
            opStk[++top]=ch;
            i++;
        }
        else if(ch==')'){
            while(top>=0 && opStk[top]!='('){
                out+=opStk[top--];
                out+=' ';
            }
            if(top>=0 && opStk[top]=='(')top--;
            i++;
        }
        else if(isOp(ch)){
            while(top>=0 && opStk[top]!='(' &&
                  (prec(opStk[top])>prec(ch) ||
                  (prec(opStk[top])==prec(ch) && rightAssoc(opStk[top])))){
                out+=opStk[top--];
                out+=' ';
            }
            opStk[++top]=ch;
            i++;
        }else i++;
    }

    while(top>=0){
        if(opStk[top]!='(' && opStk[top]!=')'){
            out+=opStk[top];
            out+=' ';
        }
        top--;
    }

    out=rev(out);
    return out;
}

int evalPrefix(const string&p){
    int st[MAX];
    int t=-1;

    for(int i=p.size()-1;i>=0;){
        if(p[i]==' '){i--;continue;}
        if(isNum(p[i])){
            int base=1,num=0;
            while(i>=0 && isNum(p[i])){
                num+=(p[i]-'0')*base;
                base*=10;
                i--;
            }
            st[++t]=num;
        }
        else if(isOp(p[i])){
            if(t<1)return 0;
            char op=p[i--];
            int a=st[t--];
            int b=st[t--];
            int r=0;
            if(op=='+')r=a+b;
            else if(op=='-')r=a-b;
            else if(op=='*')r=a*b;
            else if(op=='/')r=(b==0)?0:a/b;
            else if(op=='^')r=ipow(a,b);
            st[++t]=r;
        }else i--;
    }
    return (t>=0)?st[t]:0;
}

int main(){
    string infix;
    cout<<"enter infix:"<<endl;
    getline(cin,infix);

    string prefix=toPrefix(infix);
    cout<<"prefix: "<<prefix<<endl;

    int val=evalPrefix(prefix);
    cout<<"value: "<<val<<endl;

    return 0;
}
