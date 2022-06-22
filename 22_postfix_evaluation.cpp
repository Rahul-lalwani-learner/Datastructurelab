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
string infixToPostfix(string s){
    stack<char> st;
    string result;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            result+=c;
        }
        else if(c==' '){
            continue;
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
            while(!st.empty() && prec(s[i])<=prec(st.top())){
                if(c=='^' && st.top()=='^'){
                    break;
                }
                else{
                    result+=st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;
}
int postEvaluation(string post){
    stack <int> st;
    for(int i=0;i<post.length();i++){
        char c=post[i];
        if(isdigit(c)){
            st.push(c-'0');
        }
        else{
            int val1=st.top();
            st.pop();
            int val2=st.top();
            st.pop();
            switch(c){
                case '+':st.push(val2+val1);break;
                case '-':st.push(val2-val1);break;
                case '*':st.push(val2*val1);break;
                case '/':st.push(val2/val1);break;
            }
        }
    }
    return st.top();
}
int main(){
    string infix;
    cout<<"Enter Any Infix Expression: ";
    cin>>infix;
    int result = postEvaluation(infixToPostfix(infix));
    cout<<"The Evaluation of this Expression is: "<<result<<endl;
    return 0;
}