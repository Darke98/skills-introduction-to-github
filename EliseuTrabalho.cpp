#include <iostream>
#include <fstream>
#include <string>
using namespace std;



const int maxrow = 10;

string EmpName [maxrow] = {};
string EmpID [maxrow] ={};




//THIS IS THE PROCEDURE TO CRIATE THE FILE
void OpenFile(){
    string line;
    ifstream myfile("C:\\Users\\Darke7\\Downloads\\Video\\TrabalhoP4\\Employee.txt");
    if(myfile.is_open()){
            int x = 0;
        while(getline(myfile, line)){
            int l = line.length();
            EmpID[x] = line.substr(0,3);
            EmpName[x] = line.substr(4, 1 - 4);

            x++;
        }
    }
        else{
        cout << "Não consiguimos abrir o ficheiro!" << endl;
    }
}


//THIS IS THE PROCEDURE TO ADD EMPLOYEE
void AddEmployee(){
    char name[50];
    char empno[5];


    cin.ignore();

    cout << "Introduza o ID# ";
    cin.getline(empno, 5);
    cout << "Introduza o Nome# ";
    cin.getline(name, 50);


    for(int x= 0; x < maxrow; x++){
        if(EmpID[x] == "\0"){
            EmpID[x] = empno;
            EmpName[x] = name;

            break;
        }
    }
}
//THIS IS THE PROCEDURE TO LIST ALL EMPLOYEE
void ListEmployee(){
        system("CLS");
        cout<< "LISTA DE EMPREGADO(S)" << endl;
        cout << "========================================================================" <<endl;

        int counter = 0;
        cout << "No.    |   ID:    |    Nome:   " << endl << "------------------------------------------------------------------------\n";
        for(int x = 0; x < maxrow; x++){
            if(EmpID[x] != "\0"){
                counter++;
                cout << "   " << counter << "       "<< EmpID[x] <<"          "<<EmpName[x]<< endl;

            }
        }
        if(counter == 0){
            cout << "Nem um dado encontrado" << endl;
        }
        cout<<  "************************************************************************\n" <<endl;
}
//THIS IS THE PROCEDURE TO SEARCH THE EMPLOYEES USING THE ID NUMBER
void SearchEmployee(string search){
    system("CLS");
    cout<< "        RESULTADO DA BUSCA" << endl;
    cout<< ""<<endl;

    int counter = 0;
    for(int x = 0; x < maxrow; x++){
        if(EmpID[x] == search){
            counter++;
            cout << "   " << "N" << "   "<< "ID: " << "     " <<"Nome: " << endl;
            cout << "   " << counter << "   "<< EmpID[x] << "       " <<EmpName[x] << endl;
            break;
        }
    }
    if(counter == 0){
            cout<< "Nem um dado encontrado"<<endl;
    }
    cout << "************************************************************************"<< endl;
}
//THIS IS THE PROCEDURE TO UPDATE THE EMPLOYEES USING THE ID NUMBER
void UpdateEmployee(string search){
    char name[50];
    char empno[5];

    int counter = 0;

    for(int x = 0; x < maxrow; x++){
        if(EmpID[x] == search) {
            counter++;
            cout << "Nome do empregado: ";
            cin.getline(name, 50);

            EmpName[x] = name;
            cout <<"\n"<< "SUCESSO NA ATUALIZAÇÃO: \n" << "************************************************************************" << endl;
            break;
        }
    }
    if(counter == 0){
        cout << "ID Não existe.\n" << "************************************************************************" << endl ;


    }
}
//THIS IS THE PROCEDURE TO DELETE THE EMPLOYEE USING THE ID NUMBER
void DeleteEmployee(string search){

    int counter = 0;
    for(int x=0; x<maxrow; x++){
        if(EmpID[x] == search){

            counter++;

            EmpName[x] = "";
            EmpID[x] = "";
            cout << "************************************************************************"<<endl;
            cout << "Deletado com sucesso" << endl;

            cout << "========================================================================"<<endl;
            cout << "Por favor clique enter para voltar no MENU"<<endl;
            break;
        }
    }
    if(counter == 0){
        cout << "************************************************************************"<<endl;
        cout << "ID Não existe."<<endl;

        cout << "========================================================================"<<endl;
        cout << "Por favor clique enter para voltar no MENU"<<endl;
    }

}

//HERE WE HAS THE FUNCTION TO SAVE THE FILES
void saveFile(){
    ofstream myfile;
    myfile.open("C:\\Users\\Darke7\\Downloads\\Video\\TrabalhoP4\\Employee.txt");

    for(int x = 0; x < maxrow; x++){

        if(EmpID[x] == "\0"){
            break;
        }else{
        myfile <<EmpID[x] + " " + EmpName[x] << endl;

        }
    }
}
//THIS IS THE MAIN FUNCTION WHERE WE USE A SWITCH CASE
int main()
{
    std::cout<<"Menu";
    int option;
    string empID;
    system("CLS");
    //OPENING THE FILE FOR THIS WAY
    OpenFile();
    string password_in = "123admin";
    string user_in = "admin";
    string passwrod, user;

    cout<< "      TELA DE LOGIN" << endl;
    cout << "" <<endl;
    cout<<"usuario# ";
    cin>>user;
    if(user == user_in){
    cout<<"senha# ";

    cin>>passwrod;
    cout<< "\n" << "************************************************************************" << "\n "<<endl;
    }if(passwrod == password_in){

    do{
    cout << "         MENU" <<endl;
    cout << "1 Adicionar empregado" << endl;
    cout << "2 Atualizar empregado" <<endl;
    cout << "3 Deletar registros de empregado" <<endl;
    cout << "4 Procurar empregado" <<endl;
    cout << "5 Lista de Empregados" <<endl;
    cout << "6 sair" <<endl;
    cout << "========================================================================\n";
    cout << "Selecionar# ";
    cin >>option;


    switch(option){
case 1:
    AddEmployee();
    system("CLS");
    break;
case 2:
    cin.ignore();
    cout << "Procurando por ID# ";
    getline(cin, empID);
    UpdateEmployee(empID);
    break;
case 3:
    cin.ignore();
    cout << "insira o ID a deletar# ";
    getline(cin,empID);
    DeleteEmployee(empID);
    cin.ignore();
    system("CLS");
    break;
case 4:
    cin.ignore();
    cout << "Introduza o ID# ";
    getline(cin, empID);
    SearchEmployee(empID);
    break;
case 5:
    ListEmployee();
    break;
    }

    }while(option!=6);
    saveFile();
    cout << "Obrigado..."<<endl;
    return 0;
}else{
    cout<<"FALHA NO LOGIN, POR FAVOR TENTE OUTRA VEZ \n ";

}
}

