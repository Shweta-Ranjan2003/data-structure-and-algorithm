#include <iostream>
using namespace std;
/*
Order of operation:-
1. Parantheses () {} []
2. Exponents (right to left)
3. Multiplication and divisioon (left to right)
4. Addition and Subtraction (left to right)

Infix = <operand><operator><operand> 
Prefix(Polish notation) = <operator><operand><operand>
Postfix(Revese polish notation) = <operand><operand><operator>
                     Infix       Prefix     Postfix
                     2+3          +2 3        2 3+
                     p-q          -pq        pq-
                     a+b*c        +a*bc      abc*+
Postfix= {(A*B)+(C*D)}-e => {(AB*)+(CD*)}-e => {(AB*)(CD*)+}-e => {(AB*)(CD*)+}e- => AB*CD*+e-
Algorithm to Postfix:-
{
    create a stack S
    for i<-0 to length(exp)-1{
        if(exp[i] is operand)
        push(exp[i])
    
    else if(exp[i]) is operator{
        op2<- pop()
        op1<- pop()
        res<- perform(exp[i]),op1,op2)
        push(res)
    }
}
return top of stack }

Prefix = {(2*3)+(5*4)}-9 => {(*23)+(*54)}-9 => {+(*23)(*54)}9 => -+*23*549

Infix to Postfix:- A+B*C-D*E => ABC*+DE*-
Algo(exp){
    Create a stack S
    res<- empty string
    for i<-0 to length(exp)-1{
      if exp[i] is operand
      res<-res+exp[i]
      else if exp[i] is operator{
        while(!s.empty()&&HasHigherPrec(s.top(),exp[i]){
        res<- res+s.top()
        s.pop()
      }
      s.push(exp[i])
    }
    }
    while(!s.empty()){
        res<- res+s.top()
        s.pop()
    }
    return res
}
If we also have Paranthese the this change will be maded to the previous algo
Create a stack S
    res<- empty string
for i<-0 to length(exp)-1{
      if exp[i] is operand
      res<-res+exp[i]
      else if exp[i] is operator{
        while(!s.empty()&&!IsOpeningParentheses(s.top())
        &&HasHigherPrec(s.top(),exp[i]){
        res<- res+s.top()
        s.pop()
      }
      s.push(exp[i])
    }
    else if IsOpeningParentheses(exp[i])
    s.push(exp[i])
    else if IsclosingParenthese(exp[i]){
        while(!s.empty()&&!IsOpeningParentheses(s.top())){
            res<-res+s.top()
            s.pop()
        }
        s.pop()
    }
    }
     while(!s.empty()){
        res<- res+s.top()
        s.pop()
    }
    return res
}
*/
int main()
{ 
 
 return 0;
}