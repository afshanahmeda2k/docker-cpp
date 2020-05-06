#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std ;
int main(){
    system("clear");
    int choice_number ;
    cout<<"LAUNCH SERVER IN DOCKER"<<endl;
    cout<<"========================\n";
    cout<<"ENTER REQUIRED CHOICE NUMBER ";
    cout<<"\n 1. ENTER SETUP WIZARD\n 2. CLOSE ALL SERVERS \n 3. EXIT"<<endl;
    cout<<"=========================\n";
    cout<<"ENTER CHOICE :";
    cin>>choice_number;
    if (choice_number == 3)
    {
        system("exit");
    }
    else if(choice_number == 2){
        int delchoice ;
        system("clear");
        cout<<"===================================================================================="<<endl;
        cout<<"IF YOU HAVE OTHER CONTAINERS OTHER THAN CREATED BY THIS WIZARD THEN DON'T PROCEED\n";
        cout<<"===================================================================================="<<endl;
        cout<<"\n TO PROCEED PRESS 1 ";
        cout<<"\n TO EXIT PRESS 2 ";
        cout<<"\nINPUT : ";
        cin>>delchoice;
        if(delchoice == 2){
            system("clear");
            system("exit");
        }
        else{
            system("sudo docker rm -f $(sudo docker ps -aq)");
            system("clear");
            cout<<"ALL SERVERS REMOVED SUCCESSFULLY !"<<endl;
        }
    }
    else if(choice_number == 1){
        system("clear");
        system("rm -rf server_files");
        system("./server_files.sh");    
        cout<<"========================================================================\n";
        cout<<"COPY YOUR SERVER FILES TO \"server_files\" FOLDER IN CURRENT DIRECTORY"<<endl;
        cout<<"========================================================================\n";
        cout<<"\n WHEN DONE ,"<<endl;
        cout<<"\nPRESS 1 TO PROCEED \nIF YOU WANT TO EXIT OUT OF THIS SETUP WIZARD PRESS 2\n";
        int inner_choice;
        cout<<"INPUT : ";
        cin>>inner_choice;
        
        if(inner_choice == 3)
        system("exit");

        else if(inner_choice == 1 ){
            system("clear");
            int internal_choice ;
            cout<<"\nENTER NO OF SERVER YOU WANT TO SETUP"<<endl;
            cout<<"INPUT :";
            cin>>internal_choice;
            cout<<"\n THE IP OF DIFFERENT SERVERS ARE "<<endl;
            for(int i = 0 ; i < internal_choice ; i++){
                system("rm info.txt");
                system("rm maininfo.txt");
                system("echo $(sudo docker run -dit -v $(pwd)/server_files:/var/www/html/ afshan2001/webserver:v2) > info.txt");
                system("sudo docker inspect $(cat info.txt) > $(pwd)/maininfo.txt");
                system("./getip");
                //cout<<'\n';
            }
            cout<<"\n\n GIVE THESE IP TO OTHER CLIENT SO THAT EXCESSIVE LOAD DOES NOT FALLS ON ONE SERVER"<<endl;
        }
    }
    return 0;
}
