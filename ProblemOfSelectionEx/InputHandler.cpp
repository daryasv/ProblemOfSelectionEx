#include "InputHandler.h"
void error()
{
    cout << "invalid input";
    exit(1);
}
Person* getInfo(int& moked, int& size,int& seed)
{
    string input_line, name, last_name, full_name;
    stringstream ss, so,sd;
    bool flag = false;
    int id;
    char temp;

    getline(cin, input_line);
    sd << input_line;
    if (!(sd >> seed) || seed < 0 )
        error();

    getline(cin, input_line);
    ss << input_line;
    if (!(ss >> size) || size < 0 || ss >> temp)
        error();
    Person* people = new Person[size];
    for (int i = 0; i < size; i++)
    {
        if (getline(cin, input_line))
        {
            stringstream sn(input_line);
            if (!(sn >> id >> name >> last_name))
            {
                flag = true;
            }
            for(int j=i-1;j>0;j--){
                if (people[j].getId() == id) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
            full_name = name + " " + last_name;
            people[i] = Person(id, full_name);
        }
        else
            flag = true;
    }
    if (flag)//checks throw out after invalid name
    {
        delete[] people;
        error();
    }
    getline(cin, input_line);
    so << input_line;
    if (so >> moked)
    {
        if (moked < 1 || moked > size)
            flag = true;
    }
    else
        flag = true;
    if (so >> temp)
        flag = true;
    if (flag)
    {
        delete[] people;
        error();
    }
    return people;
}