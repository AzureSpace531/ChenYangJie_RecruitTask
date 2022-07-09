#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int year, month, day;

public:
	//////////////////////////////////////////////////////
    //  �벹������ Date ��
    //
    
    //	�޲ι��캯��
	Date(){}

	//	���ι��캯��
	Date(int y,int m,int d):year(y),month(m),day(d){}

	// 	�������к���
	void DateModify(int y,int m,int d){
		year=y;
		month=m;
		day=d;
	}
	int getYear(){
		return year;
	}
	int getMonth(){
		return month;
	}
	int getDay(){
		return day;
	}

    //////////////////////////////////////////////////////
    
	// ���� Person ��Ĵ�ӡ��Ϣ������ʹ�� Date �� show() ����
    void show()
    {
      cout << year <<"��" << month << "��" << day << "��" << endl;
    };    
};

class Person
{   
private:
   int id;						// ID��
   Date birthDate; 				// ����������
   static int numberOfObjects;  // ��̬��������ʾPerson��Ķ�������

public:
	//////////////////////////////////////////////////////
    //  �벹������ Person ��
    //
    
    //	�޲ι��캯��
	Person(){
		numberOfObjects++;
	}

	//	���ι��캯��
	Person(int i,int y,int m,int d){
		numberOfObjects++;
		id=i;
		birthDate.DateModify(y,m,d);
	}

	//	�������캯��
	Person(Person &p){
		numberOfObjects++;
		id=p.getId();
		birthDate.DateModify(p.birthDate.getYear(),p.birthDate.getMonth(),p.birthDate.getDay());
	}

	// 	��������
	~Person(){
		numberOfObjects--;
	}

	// 	�������к���
	int getId(){
		return id;
	}
	
	void show(){
		cout<<"ID:"<<id<<", "<<"����: ";
		birthDate.show();
	}

	// 	��̬���� getNumberOfObjects() ���ؾ�̬������Person���������
	static int getNumberOfObjects(){
		return numberOfObjects;
	}

    //////////////////////////////////////////////////////
};


