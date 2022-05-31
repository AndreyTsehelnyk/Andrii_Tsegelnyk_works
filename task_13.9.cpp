#include <iostream>
#include <string>
#include <sstream>
#define N 100
using namespace std;


void separate_by_commas(string& str,string sentences[N], int& sentences_number){
    int j, i=0;

    while ((j = str.find(",", i)) != -1) {
        j = str.find(",", i);
        sentences[sentences_number] = str.substr(i, j - i);
        sentences_number+=1;
        i = j + 1;
    }
    sentences[sentences_number] = str.substr(i);
    sentences_number+=1;


}

void separate_by_spaces(string sentence,int& words_number, string words[N], char symbol){
    stringstream ss;
    string word;

    ss<<sentence;

    while (ss.good()) {
        ss >> words[words_number];
        words_number+=1;
        if (ss.fail())
            break;
        if ((word = words[words_number-1]).back()==symbol){
            cout<<word<<endl;
        }
    }

}

void get_all_words(string sentences[N], int sentences_number,string words[N],int& words_number,char symbol){

    cout<<endl<<"Words ending with: "<<symbol<<endl;

    for (int i=0;i<sentences_number;i++){
        separate_by_spaces(sentences[i],words_number,words,symbol);
    }
}

void print_all_words(string words[N], int& words_number){
    cout<<endl<<"All words: "<<endl;
    for (int i=0;i<words_number;i++){
        cout<<words[i]<<endl;
    }
}


int main(){
    string s;
    cout<<"Input any string: ";
    getline(cin,s);
    char symbol;
    cout<<"Input a symbol: ";
    cin>>symbol;

    string* words = new string[N];
    int words_number = 0;

    int sentences_number = 0;
    string* sentences = new string[N];

    separate_by_commas(s,sentences,sentences_number);
    get_all_words(sentences,sentences_number,words,words_number,symbol);
    print_all_words(words,words_number);


    delete[] sentences;
    delete[] words;

    return 0;
}
