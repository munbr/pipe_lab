#include <iostream>
using namespace std;

struct PIPE
{   
    string name;
    double pipe_length;
    double pipe_diam;
    bool pipe_tech;
};

PIPE create_pipe()
{
    PIPE pipe = {};
    return pipe;
}
void edit_pipe(PIPE& p)
{
    bool flag = 1;
    while (flag != 0)
    {
    cout << "Выберите, что вы хотите отредактировать\n" << "1 - имя трубы\n" << "2 - длину трубы\n" << "3 - диаметр трубы\n" << "4 - в ремонте ли труба\n" <<"5 - закончить редактирование" << endl;
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "Введите новое имя" << endl;
            cin >> p.name;
            break;
        case 2:
            cout << "Введите новую длину" << endl;
            cin >> p.pipe_length;
            break;
        case 3:
            cout << "Введите новый диаметр" << endl;
            cin >> p.pipe_diam;
            break;
        case 4:
            cout << "Выберете 0 - если труба в ремонте, 1 - если труба работоспособна" << endl;
            int z;
            cin >> z;
            if(z == 1)
            {
                p.pipe_tech = 1;
            }
            else
            {
                p.pipe_tech = 0;
            }
            break;
        case 5:
            flag = 0;
        
        default: 
            break;
        }
    }
}

int main()
{
    bool flag = 1;
    while (flag != 0)
    {
        cout << "Выберите опцию\n" << "1 - создать трубу\n"  << "2 - редактировать трубу\n" << "3 - просмотреть все элементы\n"<< "4 - выход из программы" << endl;
        int option;
        cin >> option;
        PIPE pipe;
        switch (option)
        {
        case 1:
            pipe = create_pipe();
            break;
        case 2:
            edit_pipe(pipe);
                break;
        case 3:
            cout << "Название трубы - " << pipe.name << endl;
            cout << "Диаметр трубы - " << pipe.pipe_length << endl;
            cout << "Длина трубы - " << pipe.pipe_diam << endl;
            if (pipe.pipe_tech == 1)
            {
                cout << "Труба в работе" << endl;    
            }
            else
            {
                cout << "Труба не работает" << endl;
            }
            break;
        case 4:
            flag = 0;
            break;

        default:
            break;
        }
    }
    return 0;
    

    


}