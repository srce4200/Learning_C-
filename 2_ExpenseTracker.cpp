#include <iostream>
#include <ctime>
#include <string>

class Expense{
    std::string description;
    double amaunt;
    int IDs;
    time_t date;

    public:
        Expense(std::string d,  int am, time_t t){
            this->amaunt = am;
            this->description = d;
            this->date = t;
        }    
        void LogStats(){
            std::cout<< "\n# " << IDs << "\t" << date << "\t" << description << "\t" << amaunt;
        }
};

void add(std::string description, int amaunt);
void summary();


//add list summary delete
int main(int argc, char *argv[]){
    std::string targetFnct = argv[1];
    if(targetFnct.compare("add")==0){

        add(argv[2], std::stoi(argv[3]));
    }
    else if(targetFnct.compare("summary")==0){

    }
    else if(targetFnct.compare("delete")==0){

    }
    else if(targetFnct.compare("list")==0){

    }
    else{
        std::cout << "Invalid command.";
    }

    return 0;
}

void add(std::string desc, int amaunt){
    time_t curTime;
    Expense exp(desc, amaunt, time(&curTime));
    exp.LogStats();
    std::cout << "\n# Expense added successfully";
}
void list(){
    std::cout << "\n# ID  Date       Description  Amount";

}