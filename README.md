# OpenPro-C-
รายงานตัว01

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string textfile,vector<string> &names,vector<int> &scores,vector<char> &grades)
{
    ifstream source(textfile);
    string a;
    int S1=0,S2=0,S3=0,Sum=0;
    char format[] = "%[^:]: %d %d %d";
    char N[100];
    while(getline(source,a)){
        sscanf(a.c_str(),format,N,&S1,&S2,&S3);
        Sum = S1+S2+S3;
        names.push_back(N);
        scores.push_back(Sum);
        grades.push_back(score2grade(Sum));
        
    }
}

void getCommand(string &command, string &key){
    
    string A;
    char format[] = "%s %[^/0]/0",a[99],b[99];
    cout<<"Please input your command:\n";
    getline(cin,A);
    sscanf(A.c_str(),format,a,b);
    command = a;
    key = b;
    
}

void searchName(vector<string> &names, vector<int> &scores, vector<char> &grades, string key){
    bool a=false;
    cout<<"---------------------------------\n";
    for(long unsigned int i=0;i<names.size();i++){
        if(toUpperStr(names[i])==toUpperStr(key)){
            cout<<names[i]<<"'s score = "<<scores[i]<<'\n';
            cout<<names[i]<<"'s grade = "<<grades[i]<<'\n';
            a = true;
        }
    }
    if(!a) cout<<"Cannot found.\n";
    cout<<"---------------------------------\n";


}

void searchGrade(vector<string> &names, vector<int> &scores, vector<char> &grades, string key){
    
    bool a=false;
    cout<<"---------------------------------\n";
    for(long unsigned int i=0;i<grades.size();i++){
        if(grades[i]==key[0]){
            cout<<names[i]<<" ("<<scores[i]<<")\n";
            a = true;
        }
    }
    if(!a) cout<<"Cannot found.\n";
    cout<<"---------------------------------\n";

}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
