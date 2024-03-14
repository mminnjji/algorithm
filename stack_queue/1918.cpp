#include <iostream>
#include <stack>

using namespace std;

int priority(char ch) { // 연산자 우선순위 반환
    switch(ch) {
        case '(': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
}

string cal(string str)
{
    string res;
    char c;
    stack<char> s;

    res = "";
    for (int i = 0; i < str.size(); i++)
    {
        c = str[i];
        switch(c) {
            // 여는 괄호 push
            case '(':
                s.push(c);
                break;

            // 여는 괄호를 만날 때까지 pop
            case ')':
                while(!s.empty() && s.top() != '(') {
                    res += s.top();
                    s.pop();
                }
                s.pop(); // 여는 괄호 제거
                break;

            // 스택에 들어있는 연산자와 우선순위 비교
            case '+': case '-': case '*': case '/':
                // 스택에 현재 연산자보다 우선순위가 높은 연산자가 있는 경우 pop
                while(!s.empty() && priority(s.top()) >= priority(c)) {
                    res += s.top();
                    s.pop();
                }
                s.push(c); // 현재 연산자 push
                break;

            // 피연산자는 바로 결과에 추가
            default:
                res += c;
        }
    }

    // 스택에 남아있는 연산자 결과에 추가
    while(!s.empty()) {
        res += s.top();
        s.pop();
    }
    return (res);
}

/*
    중위표기식 -> 후위 표기식
    - 숫자의 경우 순서가 바뀌지 않음 -> 바로 출력
    - 연산자의 우선순위에 따라 순서 변화 -> 스택에 저장
    - 스택의 top의 연산자는 우선순위가 높아야 함 -> 현재 연산자와 비교
    - 괄호의 경우 여는 괄호-> 스택에 저장해두고, 닫는 괄호가 나올 때 연산자 추가
*/

int main()
{
    string str; // 입력 스트림

    cin >> str; 
    cout << cal(str); //연산 && 출력
}