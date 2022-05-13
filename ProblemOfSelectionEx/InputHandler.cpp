#include "InputHandler.h"
void error()
{
    cout << "input invalid";
    exit(1);
}
Person* getInfo(int& moked, int& size)
{
    string input_line, name, last_name, full_name;
    stringstream ss, so;
    bool flag = false;
    int id;

    getline(cin, input_line);
    ss << input_line;
    if (!(ss >> size))
        flag = true;
    Person* people = new Person[size];
    for (int i = 0; i < size; i++)
    {
        if (getline(cin, input_line))
        {
            stringstream sn(input_line);
            if (!(sn >> id >> name >> last_name))
            {
                flag = true;
                break;
            }
            full_name = name + " " + last_name;
            people[i] = Person(id, full_name);
        }
        else
            flag = true;
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
    if (flag)
    {
        delete[] people;
        error();
    }
    return people;
}