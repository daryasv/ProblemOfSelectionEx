#include "InputHandler.h"
void error()
{
    cout << "input invalid";
    exit(1);
}
Person* getInfo(int& moked)
{
    string input_line, name;
    stringstream ss, so;
    bool flag = false;
    int id, n;

    getline(cin, input_line);
    ss << input_line;
    if (!(ss >> n))
        flag = true;
    Person* people = new Person[n];
    for (int i = 0; i < n; i++)
    {
        if (getline(cin, input_line))
        {
            stringstream sn(input_line);
            if (!(sn >> id >> name))
            {
                flag = true;
                break;
            }
            people[i] = Person(id, name);
        }
        else
            flag = true;
    }
    getline(cin, input_line);
    so << input_line;
    if (so >> moked)
    {
        if (moked < 1 || moked > n)
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