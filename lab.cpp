#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

struct CS
{
    string name;
    int num_workshops;
    vector<int> num_on_workshops;
    string station_class;
};

CS create_cs()
{
    CS cs = {};
    return cs;
}

CS settings_cs(CS& cs)
{
    system("clear");
    cout << "Задайте имя КС:" << endl;
    cin.ignore();
    getline(cin,cs.name);
    int countWorkshops = 0;
    cout << "Задайте кол-во цехов:" << endl;
    cin >> countWorkshops;
    while(countWorkshops <= 0)
    {
        cout << "Ошибка. Задайте осмысленное кол-во цехов:" << endl;
        cin >> cs.num_workshops;
        countWorkshops = cs.num_workshops;
    }
    cout << "Выберите какие цеха в работе:" << endl;

    for (int i = 1; i <= cs.num_workshops; i++)
    {
        cout << "В работе ли " << i << " цех?" << endl;
        cout << "Введите 0 если цех не запущен, введите 1 если цех в работе" << endl;
        int check;
        cin >> check;
        while (check < 0 | check > 1)
        {
            cout << "Ошибка. Введите 0 если цех не запущен, введите 1 если цех в работе" << endl;
            cin >> check;
        }
        if (check == 0)
        {
            cs.num_on_workshops.push_back(0);
        }
        else
        {
            cs.num_on_workshops.push_back(1);
        }

    }
    cout << "Задайте характеристику КС:" << endl;
    cin.ignore();
    getline(cin,cs.station_class);
    return cs;
}
void edit_cs(CS& cs)
{
    system("clear");
    cout << "Выберите, что вы хотите отредактировать?" << endl;
    cout << "1 - Изменить работающие цеха.\n" << "0 - Закончить редактирование." << endl;
    int check;
    cin >> check;
    while (check < 0 | check > 1)
    {
        cout << "Ошибка.\n" << "Выберите, что вы хотите отредактировать?\n" << "1 - изменить работающие цеха\n" << "0 - закончить редактирование" << endl;
        cin >> check;
    }
    switch (check)
    {
    case 1:
        for(int i = 0; i < cs.num_workshops; i++)
        {
            cout << "Работает ли цех " << i+1 <<  "?" << endl;
            cout << "Введите 1 если да, 0 если нет." << endl;
            int isWork;
            cin >> isWork;
            while (isWork < 0 | isWork > 1)
            {
                cout << "Ошибка.\n" << "Работает ли цех " << i+1 <<  "?\n" << "Введите 1 если да, 0 если нет." << endl;
                cin >> isWork;
            }
            if (isWork == 1)
            {
                cs.num_on_workshops[i] = isWork;
            }
            else
            {
                cs.num_on_workshops[i] = isWork;
            }
        }
        break;
    
    default:
        break;
    } 
}

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

PIPE settings_pipe(PIPE& pipe)
{
    cout << "Задайте имя трубы:" << endl;
    cin.ignore();
    getline(cin,pipe.name);

    cout << "Задайте длину трубы:" << endl;
    cin >> pipe.pipe_length;
    while(pipe.pipe_length <= 0)
    {
        cout << "Ошибка.\n" << "Задайте осмысленную длину трубы:" << endl;
        cin >> pipe.pipe_length;
    }

    cout << "Задайте диаметр трубы:" << endl;
    cin >> pipe.pipe_diam;
    while(pipe.pipe_diam <= 0)
    {
        cout << "Ошибка.\n" << "Задайте осмысленный диаметр трубы:" << endl;
        cin >> pipe.pipe_diam;
    }

    cout << "В работе ли труба?" << endl;
    cout << "Выберете 0 - если труба в ремонте, 1 - если труба работоспособна" << endl;
    int isBreak;
    cin >> isBreak;
    while(isBreak < 0 | isBreak > 1)
    {
        cout << "Ошибка.\n" << "В работе ли труба?\n" << "Выберете 0 - если труба в ремонте, 1 - если труба работоспособна." << endl;
        cin >> isBreak;   
    }
    if(isBreak == 1)
    {
        pipe.pipe_tech = 1;
    }
    else
    {
        pipe.pipe_tech = 0;
    }
    system("clear");
    cout << "Труба " << pipe.name << " задана" << endl;
    return pipe;
}
void edit_pipe(PIPE& p)
{
    system("clear");
    bool flag = 1;
    while (flag != 0)
    {
    cout << "Выберите, что вы хотите отредактировать\n" << "1 - в ремонте ли труба\n" <<"0 - закончить редактирование" << endl;
        int check;
        cin >> check;
        while(check < 0 | check > 1)
        {
            cout << "Ошибка.\n" << "Выберите, что вы хотите отредактировать\n" << "1 - в ремонте ли труба\n" <<"0 - закончить редактирование" << endl;
            cin >> check;
        }
        switch (check)
        {
        case 1:
            cout << "Выберете 0 - если труба в ремонте, 1 - если труба работоспособна" << endl;
            int isBreak;
            cin >> isBreak;
            while(isBreak < 0 | isBreak > 1)
            {
                cout << "Ошибка.\n" << "В работе ли труба?\n" << "Выберете 0 - если труба в ремонте, 1 - если труба работоспособна." << endl;
                cin >> isBreak;   
            }
            if(isBreak == 1)
            {
                p.pipe_tech = 1;
            }
            else
            {
                p.pipe_tech = 0;
            }
            break;
        case 0:
            flag = 0;
        
        default: 
            break;
        }
    }
    system("clear");
    cout << "Труба " << p.name << " отредактирована" << endl;
}

void save_pipe_cs(const CS& ks, const PIPE& pipe)
{
    ofstream file("save.txt");
    if (file.is_open())
    {

        file << ks.name << endl;
        file << ks.num_workshops << endl;
        file << ks.station_class << endl;
        file << ks.num_on_workshops.size() << endl;
        for (int val : ks.num_on_workshops)
        {
            file << val << " ";
        }

        file << endl;
        file << pipe.pipe_diam << endl;
        file << pipe.pipe_length << endl;
        file << pipe.name << endl;
        file << pipe.pipe_tech << endl;
        file.close(); 
        cout << "Успешное сохранение" << endl;

    }
    else
    {
        cout << "Ошибка открытия файла для записи" << endl;
    }

}

void load_cs_pipe(CS& cs, PIPE& pipe)
{
    ifstream file("save.txt");

    if (file.is_open())
    {
        getline(file, cs.name);
        file >> cs.num_workshops;
        file.ignore();
        getline(file,cs.station_class);

        size_t cs_num_on_workshops_size = 0;
        file >> cs_num_on_workshops_size;
        cs.num_on_workshops.resize(cs_num_on_workshops_size);
        for (size_t i = 0; i < cs_num_on_workshops_size; i++)
        {
            file >> cs.num_on_workshops[i];
        }
        file >> pipe.pipe_diam;
        file >> pipe.pipe_length;
        file.ignore();
        getline(file, pipe.name);
        file >> pipe.pipe_tech;
        file.close();

        cout << "Данные успешно загружены" << endl;

    }
    else
    {
        cout << "При загрузке данных произошла ошибка" << endl;
    }

}
int main()
{
    bool flag = 1;
    PIPE pipe;
    CS cs;
    while (flag != 0)
    {
        cout << "Выберите опцию\n" << "1 - Создать трубу\n"  << "2 - Редактировать трубу\n" << "3 - Создать КС\n" << "4 - Редактировать КС\n" << "5 - Посмотреть все элементы\n" << "6 - Сохранить элементы\n"  << "7 - Загрузить элементы\n" << "0 - Выйти из программы" << endl;
        int option;
        cin >> option;
        while(option < 0 | option > 7)
        {
            cout << "Ошибка.\n" << "Выберите опцию\n" << "1 - Создать трубу\n"  << "2 - Редактировать трубу\n" << "3 - Создать КС\n" << "4 - Редактировать КС\n" << "5 - Посмотреть все элементы\n" << "6 - Сохранить элементы\n"  << "7 - Загрузить элементы\n" << "0 - Выйти из программы" << endl;
            cin >> option;
        }
        switch (option)
        {
        case 1:
            pipe = create_pipe();
            pipe = settings_pipe(pipe);
            break;
        case 2:
            edit_pipe(pipe);
            break;
        case 3:
            cs = create_cs();
            cs = settings_cs(cs);
            break;
        case 4:
            edit_cs(cs);
            break;
        case 5:
            system("clear");
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
            cout << "Название КС - " << cs.name << endl;
            cout << "Кол-во цехов - " << cs.num_workshops << endl;
            cout << "Кол-во цехов в работе - " << count(cs.num_on_workshops.begin(), cs.num_on_workshops.end(), 1) << endl;
            cout << "Характеристика КС - " << cs.station_class << endl;
            break;
        case 6:
            system("clear");
            save_pipe_cs(cs, pipe);
            break;
        case 7:
            system("clear");
            load_cs_pipe(cs, pipe);
            break;
        case 0:
            flag = 0;
            break;

        default:
            break;
        }
        
    }
    return 0;
    

    


}