#include <fstream>
#include <vector>
#include <iostream>
#include <thread>
#include <unordered_map>
#include <mutex>
#include <string>
using namespace std;
mutex mtx;

void avl(vector<string>& vect){
    int ctr = 0;
    double sum = 0;
    double avg;
    string msg;
    for (const auto& wrd : vect){
        sum+= wrd.length();
        ++ctr;
    }
    avg = sum / ctr;
    msg = "Average word length: " + to_string(avg);
    lock_guard<mutex> lock(mtx);
    cout << msg << endl;

}

void lngl(vector<string>& vect){
    int longest = 0;
    string msg;
    for (const auto& wrd : vect){
        if ((int)wrd.length() > longest){
            longest = wrd.length();
        }
    }

    msg = "The longest word length: " + to_string(longest);
    lock_guard<mutex> lock(mtx);
    cout << msg << endl;

}

void mfl(vector<string>& vect){
    unordered_map<char, int> freq;
    char mfc;
    int max_freq = 0;
    string msg;


    for (const string& word : vect) {
        for (char ch : word) {
        ++freq[ch];
        }
    }

    for (auto& pair : freq){
        if(pair.second > max_freq){
            max_freq = pair.second;
            mfc = pair.first;
        }
    }


    lock_guard<mutex> lock(mtx);
    cout << "The most frequent character in the file is: " << mfc << endl;

}


int main(int argc, char* argv[]){
    string filename;
    filename = ;
    ifstream infile(filename);


    if (!infile.good()){
        cout << "file not found" << endl;
        return -1;}

    vector<string> eng_wrds;
    string wrd;
    while(getline(infile,wrd)){
        eng_wrds.push_back(wrd);
    }

    thread trd1(avl, ref(eng_wrds));
    thread trd2(lngl, ref(eng_wrds));
    thread trd3(mfl, ref(eng_wrds));

    trd1.join();
    trd2.join();
    trd3.join();





infile.close();
return 0;
}
