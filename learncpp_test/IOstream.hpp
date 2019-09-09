#ifndef IOSTREAM_H
#define IOSTREAM_H

#include "header.h"
//2
void test180201()
{
    char str[10];
    cout<<"cin test: "<<endl;  
    cin>>str;  
    cout<<str<<endl;  
    cin.sync();  
    cin>>str;  
    cout<<str<<endl; 
}

void test180202()
{
    char strBuf[11];
    cout<<"cin.getline test: "<<endl;  
    // Read up to 10 characters
    cin.getline(strBuf, 11);
    cout << strBuf << endl;
}

void test180203()
{
    cout<<"getline test: "<<endl;  
    string strBuf;
    getline(cin, strBuf);
    cout << strBuf << endl;
}

void test180204()
{
    char strBuf[11];
    // Read up to 10 characters
    cout<<"getline test: "<<endl;  
    cin.get(strBuf, 11);
    cout << strBuf << endl;
    cin.get();
    // Read up to 10 more characters
    cin.get(strBuf, 6);
    cout << strBuf << endl;
}

//3
void test180301()
{
    cout << "-----------------------\n";
    std::cout.setf(std::ios::showpos); // turn on the std::ios::showpos flag
    std::cout << 27 << '\n';
    std::cout.unsetf(std::ios::showpos); // turn off the std::ios::showpos flag
    std::cout << 28 << '\n';
    cout << "-----------------------\n";
    std::cout.unsetf(std::ios::dec); // turn off decimal output
    std::cout.setf(std::ios::hex); // turn on hexadecimal output
    std::cout << 27 << '\n';
    cout << "-----------------------\n";
    std::cout << std::hex << 27 << '\n'; // print 27 in hex
    std::cout << 28 << '\n'; // we're still in hex
    std::cout << std::dec << 29 << '\n'; // back to decimal
    cout << "-----------------------\n";
    std::cout << true << " " << false << '\n';
    std::cout.setf(std::ios::boolalpha);
    std::cout << true << " " << false << '\n';
    std::cout << std::noboolalpha << true << " " << false << '\n';
    std::cout << std::boolalpha << true << " " << false << '\n';
    cout << "-----------------------\n";
    std::cout << 5 << '\n';
    std::cout.setf(std::ios::showpos);
    std::cout << 5 << '\n';   
    std::cout << std::noshowpos << -5 << '\n';  
    std::cout << std::showpos << -5 << '\n';
    cout << "-----------------------\n";
    std::cout << 12345678.9 << '\n';    
    std::cout.setf(std::ios::uppercase);
    std::cout << 12345678.9 << '\n';
    std::cout << std::nouppercase << 12345678.9 << '\n';
    std::cout << std::uppercase << 12345678.9 << '\n';
    cout << "-----------------------\n";
}

#endif