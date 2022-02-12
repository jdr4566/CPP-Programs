/*  Programmer : John-David Rodriguez
    Course: COSC-2436
    Date: 2/3/2022
    IDE: Microsoft Visual Studio
    Description:   Your objective is to Write a (Java or C++) program to convert an infix to postfix expression and postfix to an infix expression using the stack concept.
*/

#include <iostream>
#include <stack>
using namespace std;

//boolean for checking operator
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

//boolean for checking operand
bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//create function to check precedence
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}


//create function to convert infix to postfix
string InfixToPostfix(stack<char> s, string infix)
{
    string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z')
            || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((s.top() != '(') && (!s.empty()))
            {
                char temp = s.top();
                postfix += temp;
                s.pop();
            }
            if (s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (s.empty())
            {
                s.push(infix[i]);
            }
            else
            {
                if (precedence(infix[i]) > precedence(s.top()))
                {
                    s.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^'))
                {
                    s.push(infix[i]);
                }
                else
                {
                    while ((!s.empty()) && (precedence(infix[i]) <= precedence(s.top())))
                    {
                        postfix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

//create function to convert postfix to infix
string PostfixToInfix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            string op(1, postfix[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }
    return s.top();
}


int main() {

    //to convert infix to postfix
    string infix_exp, postfix_exp;
    cout << "Enter a Infix Expression: \n" << endl;
    cin >> infix_exp;
    stack <char> stack;
    cout << "\nInfix Expression: \n" << infix_exp << endl;
    postfix_exp = InfixToPostfix(stack, infix_exp);
    cout << endl << "\nPostfix Expression: \n" << postfix_exp;


    //to convert postfix to infix
    string infix, postfix;
    cout << "\nEnter a Postfix expression : \n" << endl;
    cin >> postfix;
    cout << "\nPostifx expression: \n" << postfix << "\n" << endl;
    infix = PostfixToInfix(postfix);
    cout << endl << "\nInfix Expression : \n" << infix;

    return 0;
}

