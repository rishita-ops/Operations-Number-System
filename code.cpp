#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int choice1;
    cout<<"Menu:\n";
    cout<<"1.Decimal\n";
    cout<<"2.Binary\n";
    cout<<"3.Octal\n";
    cout<<"4.Hexadecimal\n";
    cout<<"Enter your choice: ";
    cin>>choice1;

    switch(choice1)
    {
        case 1:
        {
            cout<<"DECIMAL\n";
            int choice2;
            cout<<"1.Addition\n";
            cout<<"2.Subtraction\n";
            cout<<"3.Multiplication\n";
            cout<<"4.Division\n";   
            cout<<"Enter your choice: ";
            cin>>choice2;
            
            switch(choice2)
            {
                case 1:
                {
                    cout<<"Addition\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Sum: "<<a+b<<endl;
                    break;
                }
                case 2:
                {
                    cout<<"Subtraction\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Difference: "<<a-b<<endl;
                    break;
                }
                case 3:
                {
                    cout<<"Multiplication\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Product: "<<a*b<<endl;
                    break;
                }
                case 4:
                {
                    cout<<"Division\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Quotient: "<<a/b<<endl;
                    break;
                }
                default:
                    cout<<"Invalid choice!"<<endl;
            }
            break;
        }
    
        case 2:
        {
            cout<<"BINARY\n";
            int choice2;
            cout<<"1.Addition\n";
            cout<<"2.Subtraction\n";
            cout<<"3.Multiplication\n";
            cout<<"4.Division\n";   
            cout<<"Enter your choice: ";
            cin>>choice2;
            
            switch(choice2)
            {
                case 1:
                {
                    cout<<"Addition\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Sum: "<<a+b<<endl;
                    break;
                }
                case 2:
                {
                    cout<<"Subtraction\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Difference: "<<a-b<<endl;
                    break;
                }
                case 3:
                {
                    cout<<"Multiplication\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Product: "<<a*b<<endl;
                    break;
                }
                case 4:
                {
                    cout<<"Division\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Quotient: "<<a/b<<endl;
                    break;
                }
                default:
                    cout<<"Invalid choice!"<<endl;
            }
            break;
        }
        case 3:
        {
            cout<<"OCTAL\n";
            int choice2;
            cout<<"1.Addition\n";
            cout<<"2.Subtraction\n";
            cout<<"3.Multiplication\n";
            cout<<"4.Division\n";   
            cout<<"Enter your choice: ";
            cin>>choice2;
            
            switch(choice2)
            {
                case 1:
                {
                    cout<<"Addition\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Sum: "<<a+b<<endl;
                    break;
                }
                case 2:
                {
                    cout<<"Subtraction\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Difference: "<<a-b<<endl;
                    break;
                }
                case 3:
                {
                    cout<<"Multiplication\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Product: "<<a*b<<endl;
                    break;
                }
                case 4:
                {
                    cout<<"Division\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Quotient: "<<a/b<<endl;
                    break;
                }
                default:
                    cout<<"Invalid choice!"<<endl;
            }
            break;
        }
        case 4:
        {
            cout<<"HEXADECIMAL\n";
            int choice2;
            cout<<"1.Addition\n";
            cout<<"2.Subtraction\n";
            cout<<"3.Multiplication\n";
            cout<<"4.Division\n";   
            cout<<"Enter your choice: ";
            cin>>choice2;
            
            switch(choice2)
            {
                case 1:
                {
                    cout<<"Addition\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Sum: "<<a+b<<endl;
                    break;
                }
                case 2:
                {
                    cout<<"Subtraction\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Difference: "<<a-b<<endl;
                    break;
                }
                case 3:
                {
                    cout<<"Multiplication\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Product: "<<a*b<<endl;
                    break;
                }
                case 4:
                {
                    cout<<"Division\n";
                    int a,b;
                    cout<<"Enter two numbers: ";
                    cin>>a>>b;
                    cout<<"Quotient: "<<a/b<<endl;
                    break;
                }
                default:
                    cout<<"Invalid choice!"<<endl;
            }
            break;
        }
        default:
            cout<<"Invalid choice!"<<endl;
    }
    return 0;
}