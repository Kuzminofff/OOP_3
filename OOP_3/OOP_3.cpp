// OOP_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale.h>
using namespace std;

void MainMenu();
void proceed_action(char command);


struct Point
{
    double x, y;
};

class Shape
{
public:
    virtual ~Shape() = default;
    virtual void AddPoints() {};
    virtual double S() = 0;
    virtual Point Center() = 0;
    virtual void info() {};
};

class Square : public Shape
{
private:
    Point point1;
    Point point2;
    Point point3;
    Point point4;
public:
    Square()
    {
        cout << "������ ����� ����� Square:" << endl;
    };
    void AddPoints() override
    {
        cout << "��������� ���������� 4-� �����:" << endl;
        cout << "1-� �����:" << endl;
        cin >> point1.x >> point1.y;
        cout << "2-� �����:" << endl;
        cin >> point2.x >> point2.y;
        cout << "3-� �����:" << endl;
        cin >> point3.x >> point3.y;
        cout << "4-� �����:" << endl;
        cin >> point4.x >> point4.y;
    };
    double S() override
    {
        double res = 0;
        res = abs(point2.y - point1.y) * abs(point2.y - point1.y); //abs - �������, �� ���� ������
        return res;
    };
    Point Center() override
    {
        Point res;
        res.x = (point1.x + point2.x + point3.x + point4.x)/4;
        res.y = (point1.y + point2.y + point3.y + point4.y)/4;
        return res;
    };
    void info() override
    {
        double s = S();
        cout << "�������:" << s << endl;

        Point c = Center();
        cout << "�����:" << c.x <<"x"<<c.y << endl;
        MainMenu();
    };
};

class Hexagon : public Shape
{
private:
    Point point1;
    Point point2;
    Point point3;
    Point point4;
    Point point5;
    Point point6;
public:
    Hexagon()
    {
        cout << "������ ����� ����� Hexagon:" << endl;
    };

    void AddPoints() override
    {
        cout << "��������� ���������� 4-� �����:" << endl;
        cout << "1-� �����:" << endl;
        cin >> point1.x >> point1.y;
        cout << "2-� �����:" << endl;
        cin >> point2.x >> point2.y;
        cout << "3-� �����:" << endl;
        cin >> point3.x >> point3.y;
        cout << "4-� �����:" << endl;
        cin >> point4.x >> point4.y;
        cout << "5-� �����:" << endl;
        cin >> point5.x >> point5.y;
        cout << "6-� �����:" << endl;
        cin >> point6.x >> point6.y;
    };
    double S() override
    {
        double res = 0;
        res = (3 * sqrt(3) * ((point2.x - point1.x) * (point2.x - point1.x))) / 2;
        return res;
    };
    Point Center() override
    {
        Point res;
        res.x = (point1.x + point2.x + point3.x + point4.x + point5.x + point6.x) / 6;
        res.y = (point1.y + point2.y + point3.y + point4.y + point5.y + point6.y) / 6;
        return res;
    };
    void info() override 
    {
        double s = S();
        cout << "�������:" << s << endl;

        Point c = Center();
        cout << "�����:" << c.x << "x" << c.y << endl;
        MainMenu();
    };
};

void MainMenu()
{
    char command;
    cout << "�������� ��� ������:" << endl;
    cout << "1) �������" << endl;
    cout << "2) ���������� �������������" << endl;
    cin >> command;
    proceed_action(command);
}

void proceed_action(char command)
{
    switch (command)
    {
    case '1':
        Square * T1;
        T1 = new Square();
        T1->AddPoints();
        T1->info();
        break;
    case '2':
        Hexagon * T2;
        T2 = new Hexagon();
        T2->AddPoints();
        T2->info();
        break;
    }
}


int main()
{
    setlocale(LC_ALL, "Rus");
    MainMenu();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
