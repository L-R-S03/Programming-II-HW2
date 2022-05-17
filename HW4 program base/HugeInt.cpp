#include <cctype> //isdigit()
#include <cstring> //strlen
#include <cassert>
#include <math.h> 
#include "HugeInt.h"
using std::endl;
using std::cout;

HugeInt::HugeInt(long value)
{
    cout <<"HugeInt(long) called" << endl;
    number = new char[30];
    //loads in default 0's for number char array
    for(int i = 0; i < 30; i++)
        number[i] = 0;
    int index=29; 
    while(value!=0)
    {
        int digit=value%10; 
        char v=digit+'0'; 
        number[index]=v;  
        index--; 
        value/=10; 
    }
    //Complete the code here to set number[i]
    computeSize();
}

//Set the size of the number of an HugeInt object
void HugeInt::computeSize()
{
    size=0; 
    for(int i=0; i<30; i++)
    {
        //if char isn't null there is a value increase size    
        if(number[i]!=0)
        {
            size++; 
        }
    }
}

HugeInt::HugeInt(const char* string)
{ 
    cout <<"HugeInt(const char*) called" << endl;
    //makes number a char array with space for 30 chars 
    number=new char[30]; 
    for(int i = 0; i < 30; i++)
        number[i] = 0;
    //loop through the string 
    for(int i=strlen(string)-1,n=29; i>=0; i--)
    {
        //if string char isn't 0 
        if(string[i]!='0')
        {
            //add the digit to the number char 
            number[n]=string[i]; 
            //move to next spot in the arr 
            n--; 
        }
    }
    computeSize(); 
}

HugeInt::HugeInt(const HugeInt& copy) 
{
   cout <<"HugeInt(const HugeInt&) called" << endl;
   number = new char[30];
   //pre-loads in 0 
   for(int i = 0; i < 30; i++)
        this->number[i] = 0;
    //copies over size value
    size=copy.size; 
    //copies over arr values using a loop 
    for(int i=0; i<size; i++)
    {
        number[i]=copy.number[i]; 
    }
}
    
        
HugeInt::~HugeInt()
{
    cout <<"~HugeInt() called" << endl;
    delete [] number;     

}

HugeInt& HugeInt::operator=(const HugeInt& right)
{
    cout <<"operator=(const HugeInt&)  called" << endl;
    //uses copy constructor 
    HugeInt obj(right); 
    //sets temp char* to number 
    char* q=this->number; 
    //sets number to the passed object 
    number=obj.number; 
    //object number arr is set to temp arr 
    obj.number=q; 
    //size is set to obj.size 
    size=obj.size; 
    return *this; 
}


HugeInt HugeInt::operator+(const HugeInt& right)
{
    cout << "operator+(const HugeInt&)" << endl;
    HugeInt obj;
    int s,digit1,digit2,result; 
    bool carry=false; 
    char a;
    string num1,num2,r; 
    //determines with arr is larger to make variable for loop size 
    if(size>right.size)
    {
        s=size; 
    } 
    else
    {
        s=right.size; 
    }
    //loops through the size of the largest arr 
    for(int i=29; i>30-s; i--)
    {
        //if there is a digit placed there so value is not 0  
        if(number[i]!=0)
        {
            //set digit1 var to number[i] casted to int and 48 subtracted to remove ascii value 
            digit1=(int)number[i]-48; 
        }
        else 
        {
            //otherwise digit is a 0 
            digit1=0; 
        }
        //repeats the same process with right side for digit2 
        if(right.number[i]!=0)
        {
            digit2=(int)right.number[i]-48; 
        }
        else 
        {
            digit2=0; 
        }
        //if carry is true so the previous digit needed to carry
        if(carry==true)
        {
            //result amount adds to digits together and one for the carry value 
            result=digit1+digit2+1;    
        }
        else 
        {
            //otherwise carry wasn't needed so result is just two digits added together 
            result=digit1+digit2; 
        }
        //if result is greater than or equal to 10 carry is needed for next digit 
        if(result>=10)
        {
            //carry is set to true 
            carry=true; 
            //result has 10 removed for the carry 
            result-=10; 
        }
        //otherwise carry is false 
        else 
        {
            carry=false; 
        }
        //result is converted to a char 
        a=result+'0';
        //string of all results is added to in order to get total num  
        r=a+r;  
    }
    //if carry is true when loop is done a 1 and 0 must be added 
    if(carry==true)
    {
        r="0"+r;
        r="1"+r; 
    }
    //loops through the length of the results string and loads in the chars to the obj number
    for(int i=r.length()-1, j=29; i>=0; i--,j--)
    {
        obj.number[j]=r[i];
    }
    //runs compute size 
    obj.computeSize(); 
    return obj; 
}

HugeInt HugeInt::operator-(const HugeInt& right)
{
    cout << "operator-(const HugeInt&)" << endl;
    HugeInt obj;
    char a; 
    int s,digit1,digit2,result; 
    bool carry=false; 
    string num1,num2,r; 
    //same algorithm as above 
    if(size>=right.size)
    { 
        s=size; 
    } 
    else
    {
        s=right.size; 
    } 
    for(int i=29; i>30-s-1; i--)
    {
        if(number[i]!=0)
        {
            digit1=(int)number[i]-48; 
        }
        else 
        {
            digit1=0; 
        }
        if(right.number[i]!=0)
        {
            digit2=(int)right.number[i]-48; 
        }
        else 
        {
            digit2=0; 
        }
        //if carry is true it adds 10 to the difference of the digits 
        if(carry==true)
        {
            result=digit1-digit2+10;    
        }
        //otherwise just subtracts the digits 
        else 
        {
            result=digit1-digit2; 
        }
        //if result less than 0 
        if(result<0)
        {
            //carry must be true 
            carry=true; 
            //result gets 10 added to it 
            result=+10; 
        }
        //otherwise carry is false 
        else 
        {
            carry=false; 
        }
        //convert result to a char and add it to the result string 
        a=result+'0';
        r=a+r;  
    }
    //loads in arr 
    for(int i=r.length()-1, j=29; i>=0; i--,j--)
    {
        obj.number[j]=r[i];
    }
    obj.computeSize(); 
    return obj; 
}
//same algorithim as addition except multiplication instead of addition 
HugeInt HugeInt::operator*(const HugeInt& right)
{
    cout << "operator*(const HugeInt&)" << endl;
    HugeInt obj;
    int s,digit1,digit2,result; 
    bool carry=false; 
    char a;
    string num1,num2,r; 
    if(size>right.size)
    {
        s=size; 
    } 
    else
    {
        s=right.size; 
    }
    for(int i=29; i>30-s; i--)
    {
        if(number[i]!=0)
        {
            digit1=(int)number[i]-48; 
        }
        else 
        {
            digit1=0; 
        }
        if(right.number[i]!=0)
        {
            digit2=(int)right.number[i]-48; 
        }
        else 
        {
            digit2=0; 
        }
        if(carry==true)
        {
            result=digit1+digit2+1;    
        }
        else 
        {
            result=digit1+digit2; 
        }
        if(result>=10)
        {
            carry=true; 
            result-=10; 
        }
        else 
        {
            carry=false; 
        }
        a=result+'0';
        r=a+r;  
    }
    if(carry==true)
    {
        r="0"+r;
        r="1"+r; 
    }
    for(int i=r.length()-1, j=29; i>=0; i--,j--)
    {
        obj.number[j]=r[i];
    }
    obj.computeSize(); 
    return obj; 
}


HugeInt HugeInt::operator/(const HugeInt& right)
{
    cout << "operator/(const HugeInt&)" << endl;
    HugeInt obj; 
    return obj; 
}

HugeInt HugeInt::operator%(const HugeInt& right)
{   
    cout << "operator%(const HugeInt&)" << endl;
    HugeInt obj; 
    return obj; 
    
}

HugeInt& HugeInt::operator++()
{
     cout << "operator++()" << endl;
     //converts number at last index to an int   
     int v=(int)(number[29]-48); 
     //increments value 
     v++; 
     //converts the value back to a char 
     number[29]=v+'0';
     //returns *this
     return *this;

}

HugeInt HugeInt::operator++(int)
{
    cout << "operator++(int)" << endl;
    //makes temp var and sets it 
    HugeInt t=*this; 
    //verifys that the number needing incremented isn't 0
    if(number[29]!=0)
    {
        //converts v 
        int v=(int)(number[29]-48); 
        v++; 
        number[29]=v+'0';
    }
    else 
    {
        //otherwise it is 0 so after increment it is 1 
        number[29]=1;
    }
    //returns t 
    return t;
}
char& HugeInt::operator[](int pos)
{
    cout << "operator[](int)" << endl;
    //checks that index is in range 
    assert(pos <= 29);
    //returns the address of the index 
    return *(number+pos); 
}

HugeInt::operator long double()
{ 
    cout << "operator long double()" << endl;
    long double a=0;
    long double b=0; 
    for(int i=30-size,z=size-1; i<30; i++,z--)
    {
        b=(long double)(number[i]-48);
        a+=b*pow(10,z); 
    }
    return a; 
    
}

bool HugeInt::operator<=(const HugeInt& right) {

    cout << "operator<=(const HugeInt& )" << endl;
    int digit1=0, digit2=0; 
    //first compares by sizes  of arrs  
    if(size>right.size)
    {
        return false; 
    }
    else if(size<right.size)
    {
        return true; 
    }
    else 
    {
        int i=30-size; 
        //otherwise loop through and compare the numbers that come out of the conversions 
        while(digit1==digit2||i<29)
        {
            digit1=number[i]; 
            digit2=right.number[i]; 
            i++; 
        } 
        return digit1<=digit2; 
    }

     
}

ostream& operator<<(ostream& out, const HugeInt& n)
{
    cout << "operator<<(ostream&, const HugeInt& )" << endl;
    if(n.size!=0)
    {
        out << "value : "; 
        for(int i=30-n.size; i<30; i++)
        {  
            out << n.number[i]; 
        }       
        out << " || size = " << n.size; 
    }
    else 
    {
        out<< "value : 0 || size = 1";  
    }
    return out; 
} 

istream& operator>>(istream& in, HugeInt& n)
{
    cout << "operator>>(istream&, HugeInt& )" << endl;
    string a; 
    in >> a; 
    char* b; 
    b=const_cast<char*>(a.c_str());
    for(int i=30-strlen(b),j=0; i<30; i++,j++)
    {
        n.number[i]=b[j];  
    }
    n.computeSize();
    return in; 
    //Converting a string to char* can be done with c_str() member function of string type

}
