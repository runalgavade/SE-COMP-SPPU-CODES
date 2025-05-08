#include <iostream>
using namespace std;
class Complex
{
    float real,img;
    public:
    Complex()
    {
        real=0;
        img=0;
    }
    Complex operator + (Complex);
    Complex operator * (Complex);
    friend istream &operator >>(istream &input, Complex &t)
    {
        cout<<"Enter real part of Complex Number ";
        input>>t.real;
        cout<<"Enter imaginary part of Complex Number ";
        input>>t.img;
    }
    friend ostream &operator <<(ostream &output, Complex &t)
    {
        output<<t.real<<"+"<<t.img<<"i"<<endl;
    }
};
Complex Complex::operator + (Complex C)
{
    Complex temp;
    temp.real=real+C.real;
    temp.img=img+C.img;
    return temp;
}
Complex Complex::operator * (Complex C)
{
    Complex temp1;
    temp1.real=(real*C.real)-(img*C.img);
    temp1.img=(real*C.img)+(img*C.real);
    return temp1;
}
int main()
{
    int ch;
    Complex c1,c2,c3,c4;
    while (true)
    {
        cout<<"Enter your choice\n";
        cout<<"1.Insert Complex Numbers\t2.Display Complex Numbers\n3.Addition\t4.Multiplication\n5.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"Enter 1st Complex Number\n";
                cin>>c1;
                cout<<"Enter 2nd Complex Number\n";
                cin>>c2;
                break;
            }
            case 2:
            {
                cout<<"1st Complex Number is ";
                cout<<c1;
                cout<<"2nd Complex Number is ";
                cout<<c2;
                break;
            }
            case 3:
            {
                c3=c1+c2;
                cout<<"The Addition of"<<c1<<" & "<<c2<<"is "<<c3;
                break;
            }
            case 4:
            {
                c4=c1*c2;
                cout<<"The Multiplication of"<<c1<<" & "<<c2<<"is "<<c4;
                break;
            }
            case 5:
            {
                exit(0);
            }
            }
        }
        return 0;
}
