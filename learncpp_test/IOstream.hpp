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
    std::cout << 27 << '\n';
    std::cout.setf(std::ios::dec, std::ios::basefield);
    std::cout << 27 << '\n';
    std::cout.setf(std::ios::oct, std::ios::basefield);
    std::cout << 27 << '\n';
    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << 27 << '\n';
    std::cout << std::dec << 27 << '\n';
    std::cout << std::oct << 27 << '\n';
    std::cout << std::hex << 27 << '\n';
    cout << "-----------------------\n";
    std::cout << std::fixed << '\n';
    std::cout << std::setprecision(3) << 123.456 << '\n';
    std::cout << std::setprecision(4) << 123.456 << '\n';
    std::cout << std::setprecision(5) << 123.456 << '\n';
    std::cout << std::setprecision(6) << 123.456 << '\n';
    std::cout << std::setprecision(7) << 123.456 << '\n';
    cout << "-----------------------\n";
    std::cout << std::scientific << '\n';
    std::cout << std::setprecision(3) << 123.456 << '\n';
    std::cout << std::setprecision(4) << 123.456 << '\n';
    std::cout << std::setprecision(5) << 123.456 << '\n';
    std::cout << std::setprecision(6) << 123.456 << '\n';
    std::cout << std::setprecision(7) << 123.456 << '\n';
    cout << "-----------------------\n";
    std::cout << std::setprecision(3) << 123.456 << '\n';
    std::cout << std::setprecision(4) << 123.456 << '\n';
    std::cout << std::setprecision(5) << 123.456 << '\n';
    std::cout << std::setprecision(6) << 123.456 << '\n';
    std::cout << std::setprecision(7) << 123.456 << '\n';
    cout << "-----------------------\n";
    std::cout << std::showpoint << '\n';
    std::cout << std::setprecision(3) << 123.456 << '\n';
    std::cout << std::setprecision(4) << 123.456 << '\n';
    std::cout << std::setprecision(5) << 123.456 << '\n';
    std::cout << std::setprecision(6) << 123.456 << '\n';
    std::cout << std::setprecision(7) << 123.456 << '\n';
    cout << "-----------------------\n";
    std::cout << std::dec << '\n';
    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
    std::cout << std::setw(10) << left << -12345 << '\n'; // print left justified
    std::cout << std::setw(10) << right << -12345 << '\n'; // print right justified
    std::cout << std::setw(10) << internal << -12345 << '\n'; // print internally justified
    cout << "-----------------------\n";
    std::cout.fill('*');
    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
    std::cout << std::setw(10) << left << -12345 << '\n'; // print left justified
    std::cout << std::setw(10) << right << -12345 << '\n'; // print right justified
    std::cout << std::setw(10) << internal << -12345 << '\n'; // print internally justified

}

//4
void test180401()
{
    stringstream os;
    os << "12345 67.89"; // insert a string of numbers into the stream
    int nValue;
    double dValue;
    os >> nValue >> dValue;
    cout << nValue << " " << dValue << endl;
}

void test180402()
{
    stringstream os;
    os << "Hello ";
    
    os.str(""); // erase the buffer  
    //os.str(std::string()); // erase the buffer
    os.clear(); // reset error flags
    os << "World!";
    cout << os.str();
}

//5
void test180501()
{
    while (1)
	{
		// Get user's name
		std::cout << "Enter your name: ";
		std::string strName;
		std::getline(cin, strName); // get the entire line, including spaces
 
		bool bRejected = false; // has strName been rejected?
 
								// Step through each character in the string until we either hit
								// the end of the string, or we rejected a character
		for (unsigned int nIndex = 0; nIndex < strName.length() && !bRejected; ++nIndex)
		{
			// If the current character is an alpha character, that's fine
			if (isalpha(strName[nIndex]))
				continue;
 
			// If it's a space, that's fine too
			if (strName[nIndex] == ' ')
				continue;
 
			// Otherwise we're rejecting this input
			bRejected = true;
		}
 
		// If the input has been accepted, exit the while loop
		// otherwise we're going to loop again
		if (!bRejected)
			break;
	}
}

bool InputMatches(string strUserInput, string strTemplate)
{
    if (strTemplate.length() != strUserInput.length())
        return false;
 
    // Step through the user input to see if it matches
    for (unsigned int nIndex=0; nIndex < strTemplate.length(); nIndex++)
    {
        switch (strTemplate[nIndex])
        {
            case '#': // match a digit
                if (!isdigit(strUserInput[nIndex]))
                    return false;
                break;
            case '_': // match a whitespace
                if (!isspace(strUserInput[nIndex]))
                    return false;
                break;
            case '@': // match a letter
                if (!isalpha(strUserInput[nIndex]))
                    return false;
                break;
            case '?': // match anything
                break;
            default: // match the exact character
                if (strUserInput[nIndex] != strTemplate[nIndex])
                    return false;
        }
    }
 
    return true;
}

void test180502()
{
    string strValue;
 
    while (1)
    {
        cout << "Enter a phone number ###-###-####: ";
        getline(cin, strValue); // get the entire line, including spaces
        if (InputMatches(strValue, "###-###-####"))
            break;
    }
 
    cout << "You entered: " << strValue << endl;
}

void test180503()
{
    int nAge;
 
    while (1)
    {
        cout << "Enter your age: ";
        string strAge;
        cin >> strAge;
 
        // Check to make sure each character is a digit
        bool bValid = true;
        for (unsigned int nIndex=0; nIndex < strAge.length(); nIndex++)
            if (!isdigit(strAge[nIndex]))
            {
                bValid = false;
                break;
            }
        if (!bValid)
            continue;
 
        // At this point, we have something that can be converted to a number
        // So we'll use stringstream to do that conversion
        stringstream strStream;
        strStream << strAge;
        strStream >> nAge;
 
        if (nAge <= 0) // make sure nAge is positive
            continue;
		
	break;
    }
 
    cout << "You entered: " << nAge << endl;
}

//6
void test180601()
{
    ofstream fout("Sample.dat");

    if(!fout)
    {
        cerr << "Data file no found\n";
        exit(1);
    }

    fout << "Line 1\n";
    fout << "Line 2\n";
}
void test180602()
{
    ifstream fin("Sample.dat");

    if(!fin)
    {
        cerr << "Data file no found\n";
        exit(1);
    }

   while(fin)
   {
       string str;
       getline(fin,str);
       cout << str << '\n';
   }
}
void test180603()
{
    ofstream fout("Sample.dat",ios::app);

    if(!fout)
    {
        cerr << "File No Found\n";
        exit(1);
    }
    fout << "Line 3\n";
    fout << "Line 4\n";

    fout.close();
    fout.open("Sample.dat",ios::app);
    fout << "Line 5\n";
    fout.close();
}

//7

void test180701()
{
    ifstream inf("Sample.dat");
 
    // If we couldn't open the input file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
        exit(1);
    }
 
    string strData;
 
    inf.seekg(5); // move to 5th character
    // Get the rest of the line and print it
    getline(inf, strData);
    cout << strData << endl;
 
    inf.seekg(8, ios::cur); // move 8 more bytes into file
    // Get rest of the line and print it
    getline(inf, strData);
    cout << strData << endl;
 
    inf.seekg(-15, ios::end); // move 15 bytes before end of file
    // Get rest of the line and print it
    getline(inf, strData);
    cout << strData << endl;
}

void test180702()
{
    fstream iofile("Sample.dat",ios::in|ios::out);

    if(!iofile)
    {
        cerr << "DAT FILE NOT FOUND\n";
        exit(1);
    }

    char ch;

    while(iofile.get(ch))
    {
        switch(ch)
        { // If we find a vowel
            //case 'a':
            case 'e':
            //case 'i':
            //case 'o':
            //case 'u':
            //case 'A':
            //case 'E':
            //case 'I':
            //case 'O':
            //case 'U':
            iofile.seekg(-1,ios::cur);
            iofile << '#';
            iofile.seekg(iofile.tellg(),ios::beg);

            break;
        }
    }

}
#endif