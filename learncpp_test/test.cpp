#include "header.h"
#include "IOstream.hpp"

int main()
{
    Timer t;

    fstream iofile("../learncpp_test/Sample.dat",ios::in|ios::out);

    // If we couldn't open iofile, print an error
    if (!iofile)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened!" << endl;
        exit(1);
    }
 
    char chChar; // we're going to do this character by character

    // While there's still data to process
    while (iofile.get(chChar))
    {
        cout<<"vox:"<<chChar<<endl;
        cout<<"pos:"<<iofile.tellg()<<endl;
        switch (chChar)
        {
            // If we find a vowel
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
                
                // Back up one character
                
                iofile.seekg(-1, ios::cur);
                 cout<<"pos:"<<iofile.tellg()<<endl;
                // Because we did a seek, we can now safely do a write, so
                // let's write a # over the vowel
                iofile << '#';
 
                // Now we want to go back to read mode so the next call
                // to get() will perform correctly.  We'll seekg() to the current
                // location because we don't want to move the file pointer.
                iofile.seekg(iofile.tellg(), ios::beg);
 
                break;
        }
    }

    return 0;
}
