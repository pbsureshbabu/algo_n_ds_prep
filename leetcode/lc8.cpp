#include <fstream>
#include <iostream>
using namespace std;

ifstream myin("input.txt");
ofstream myout("output.txt");

int validate_limits( string str, int s, int e, int sign )
{
    string min_value = "2147483648";
    string max_value = "2147483647";
    int incre=0;

    while(s<e)
    {
        if(str[s]>min_value[incre])
        {
            if(sign==1)
                return 1;
            else if(sign==-1)
                return -1;
        }
        else if(str[s]<min_value[incre])
            return 0;
        s++;
        incre++;
    }
    if(sign==1 && str[s]>max_value[incre])
        return 1;
    else if(sign==-1 && str[s]>min_value[incre])
        return -1;
    else 
        return 0;
    
}

int my_atoi( string str )
{
    int out_limits=0; // -1 is <INT_MIN, 0 is valid, 1 is >INT_MAX
    int sign=1; // 1 is +ve and -1 is -ve

    unsigned int i=0;
    int s=-1;
    int e=-1;
    
    while(str[i]==' ')
    {
        i++;
    }
    if(str[i]=='-')
        sign=-1;
    else if(str[i]=='+')
        sign=1;
    else if(str[i]>='0' && str[i]<='9')
    {
        s=i;
        e=i;
    }
    else
        return 0;

    i++;
    while(i<str.length())
    {
        if(str[i]>='0' && str[i]<='9')
        {
            if(s==-1)
                s=i;
            e=i;
        }
        else 
        {
            e=i-1;
            break;
        }
        i++;
    }

    if(!(str[s]>='0' && str[s]<='9'))
        return 0;

    while(str[s]=='0')
        s++;

    if(e-s+1>10)
    {
        if(sign==1)
            return INT_MAX;
        else
            return INT_MIN;
    }
    else if(e-s+1==10)
    {
        out_limits=validate_limits(str, s, e, sign);
        if(out_limits==1)
            return INT_MAX;
        else if(out_limits==-1)
            return INT_MIN;
    }

    unsigned int j=1; 
    int integer=0;
    while(e>=s)
    {
        integer=integer + ((str[e]-'0') * j);
        j*=10;
        e--;
    }
    return sign*integer;
}

int main()
{
    string str1 = "1095502006p8";
    //string str2;
    //string str3;
    //string str4;
    //string str5;
    //myin >> str1;
    //myin >> str2;
    //myin >> str3;
    //myin >> str4;
    //myin >> str5;
    int result;

    result = my_atoi(str1);
    cout << result << endl;
#if 0
    result = my_atoi(str2);
    myout << result << endl;
    result = my_atoi(str3);
    myout << result << endl;
    result = my_atoi(str4);
    myout << result << endl;
    result = my_atoi(str5);
    myout << result << endl;
#endif

    return 0;
}