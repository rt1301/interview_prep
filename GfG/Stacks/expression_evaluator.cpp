/****
 * Evaluate an expression represented by a String
 ****/
#include<bits/stdc++.h>
using namespace std;
int precendence(char op){
    if(op == '+' || op == '-'){
        return 1;
    }
    if(op == '*' || op == '/'){
        return 2;
    }
    return 0;
}
int arithmeticOp(int a, int b, char op){
    switch (op)
    {
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        return a/b;
        break;
    default:
        break;
    }
    return 0;
}
int expEvaluate(string tokens){
    int n = tokens.size();
    stack<int>vals;
    stack<char>ops;

    for(int i=0;i<n;i++){
        if(tokens[i] == ' '){
            continue;
        }
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }else if(isdigit(tokens[i])){
            int val = 0;
            while(i<n && isdigit(tokens[i])){
                val = val*10 + (tokens[i]-'0');
                i++;
            }
            vals.push(val);
            i--;
        }else if(tokens[i] == ')'){
            while(!ops.empty() && ops.top() != '('){
                int val2 = vals.top();
                vals.pop();
                int val1 = vals.top();
                vals.pop();
                char op = ops.top();
                ops.pop();
                vals.push(arithmeticOp(val1,val2,op));
            }
            if(!ops.empty()){
                ops.pop();
            }
        }else{
            while(!ops.empty() && precendence(ops.top())>=precendence(tokens[i])){
                int val2 = vals.top();
                vals.pop();
                int val1 = vals.top();
                vals.pop();
                char op = ops.top();
                ops.pop();
                vals.push(arithmeticOp(val1, val2, op));
            }

            ops.push(tokens[i]);
        }
    }
    while(!ops.empty()){
        int val2 = vals.top();
        vals.pop();
        int val1 = vals.top();
        vals.pop();
        char op = ops.top();
        ops.pop();
        vals.push(arithmeticOp(val1, val2, op));
    }

    return vals.top();
}

int main(){
    cout << expEvaluate("10 + 2 * 6") << "\n";
    cout << expEvaluate("100 * 2 + 12") << "\n";
    cout << expEvaluate("100 * ( 2 + 12 )") << "\n";
    cout << expEvaluate("100 * ( 2 + 12 ) / 14");
    return 0;
}