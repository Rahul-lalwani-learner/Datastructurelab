#include <bits/stdc++.h>

using namespace std;
int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else {
        return -1;
    }
}
bool isOperator(char c){
    return (!isalpha(c) && !isdigit(c));
}
string infixToPostfix(string s){
    s='('+s+')';
    stack<char> st;
    string result;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            result+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(st.top()!='('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(isOperator(st.top())){
                if(s[i]=='^'){
                    while(prec(s[i])<=prec(st.top())){
                        result+=st.top();
                        st.pop();
                    }
                }
                else{
                while(prec(s[i])<prec(st.top())){
                    result+=st.top();
                    st.pop();
                }
            }
            st.push(c);
            }
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;
}
string infixToPrefix(string infix){
    int l=infix.size();
    reverse(infix.begin() , infix.end());
    for(int i=0;i<l;i++){
        if(infix[i] == '('){
            infix[i]=')';
            i++;
        }
        else if(infix[i]== ')'){
            infix[i]=='(';
            i++;
        }
    }
    string prefix=infixToPostfix(infix);
    reverse(prefix.begin(),prefix.end());
    return prefix;
}
int main(){
    string user_input;
    cout<<"Enter String: ";
    cin>>user_input;
    cout<<infixToPrefix(user_input)<<endl;
    return 0;
}
