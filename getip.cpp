#include<iostream>
#include<fstream>
#include<string>
using namespace std ;
int main () {
    string line ;
    ifstream myfile("maininfo.txt");
    if(myfile.is_open()){
        int count = 0 ;
        while(getline(myfile,line)){
            int i = 0;
            for(i = 0 ; i < line.length() ; i++){
                if(line[i]=='\"')
                break;
            }
            int staindex = i ; 
            i ++;
            int endindex = 0;
            for (endindex = i ; endindex < line.length() ; endindex++ ){
                if(line[endindex]=='\"')
                break ;
            }

            string que = line.substr(staindex,endindex - staindex);
            if(que == "\"IPAddress"){
                break ;
            }
            count++;
        }
        myfile.close();

        myfile.open("maininfo.txt");
        string ip ;
        for (int i = 0 ; i != count+1 ; i++){
            getline(myfile,ip);
        }
        string ipmain ;
        count = 0 ;
        int staindex , endindex ;
        for(int i = 0 ; i < ip.length() ; i++){
            if(ip[i] == '\"')
            {
                count++;
            }
            if(count == 2)
            staindex = i ;
            if(count == 4)
            endindex = i ;
        }
        ipmain = ip.substr(staindex,endindex-staindex);
        cout<<ipmain<<'\n' ;
    }
    return 0;
}
