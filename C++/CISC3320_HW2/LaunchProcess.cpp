#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
    string filename;
    cout << "Please enter the name of the file you wish to analyze: ";
    cin >> filename;
    cout << endl;

    string commandLine = "C:\\Users\\danic\\Desktop\\CISC3320\\HW2\\CISC3320_HW2\\AnalyzeWords.exe " + filename;


    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    /*allocate memory*/
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    DWORD startTime = GetTickCount(); // Record the start time
    /*create child process*/
    if(!CreateProcess(NULL,
                  const_cast<char*>(commandLine.c_str()),
                  NULL,
                  NULL,
                  FALSE,
                  0,
                  NULL,
                  NULL,
                  &si,
                  &pi))
                  {
                      fprintf(stderr, "Create Process Failed");
                      return -1;
                  }
    // Wait for the child process to finish
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Calculate and display the elapsed time in seconds
    DWORD endTime = GetTickCount();
    float elapsedTime = (endTime - startTime);
    cout << "AnalyzeWords finished in " << elapsedTime << " milliseconds." << endl;





    return 0;
}

