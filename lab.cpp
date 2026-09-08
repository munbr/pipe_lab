#include <iostream>
using namespace std;

struct PIPE
{   
    string name;
    double pipe_length;
    double pipe_diam;
    bool pipe_tech;
};

void create_pipe()
{
    PIPE pipe = {};
}
void edit_pipe(PIPE p)
{
    while (true)
    {
    cout << "Выберите, что вы хотите отредактировать\n" << "1 - имя трубы\n" << "2 - длину трубы\n" << "3 - диаметр трубы\n" << "4 - в ремонте ли труба" << endl;
        int x;
        switch (x)
        {
        case 1:
            cout << "Введите новое имя" << endl;
            cin >> p.name;
            break;
        case 2:
            cout << "Введите новую длину" << endl;
            break;
        case 3:
            cout << "Введите новый диаметр" << endl;
            break;
        case 4:
            cout << "Выберете 1 - если труба в ремонте, 2 - если труба работоспосбна " << endl;
            break;
        
        default: 
            break;
        }
    }
    
    
}

int main()
{
    cout << "Выберите опцию\n" << "1 - создать трубу\n" << endl;
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
        create_pipe;
        break;
    
    default:
        break;
    }
    

    


}