#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main(){
    try {
    string infilename;
    string outfilename;
    cout << "Please enter the name of the input file: ";
    cin >> infilename;
    cout << endl;
    ifstream infile (infilename);
    if (!infile.good())
        throw string ("file was not found!");
    cout << "Please enter a name for an output file: ";
    cin >> outfilename;
    cout << endl;
    ofstream outfile (outfilename);

    char ch;
    int badchar = 0;
    int lnct = 0;
    while ((ch = infile.get()) != char_traits<char>::eof()){
        if (isascii(ch))
            outfile << ch;
        else {
            ++badchar;
            cout << ch << " ";
        }
        if (ch == '\n')
            ++lnct;


    }
    cout << endl << badchar;
    outfile << endl << lnct << " lines were processed with " << badchar << " non-ascii characters stripped." << endl;

    infile.close();
    outfile.close();
    return 0;
}

catch (string msg){
cerr << msg << endl;
exit(1);
}

}
