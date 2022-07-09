#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int year, month, day;

public:
	//////////////////////////////////////////////////////
    //  请补充完整 Date 类
    //
    
    //	无参构造函数
	Date(){}

	//	带参构造函数
	Date(int y,int m,int d):year(y),month(m),day(d){}

	// 	其他公有函数
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
    
	// 请在 Person 类的打印信息函数中使用 Date 的 show() 方法
    void show()
    {
      cout << year <<"年" << month << "月" << day << "日" << endl;
    };    
};

class Person
{   
private:
   int id;						// ID号
   Date birthDate; 				// 出生年月日
   static int numberOfObjects;  // 静态变量，表示Person类的对象数量

public:
	//////////////////////////////////////////////////////
    //  请补充完整 Person 类
    //
    
    //	无参构造函数
	Person(){
		numberOfObjects++;
	}

	//	带参构造函数
	Person(int i,int y,int m,int d){
		numberOfObjects++;
		id=i;
		birthDate.DateModify(y,m,d);
	}

	//	拷贝构造函数
	Person(Person &p){
		numberOfObjects++;
		id=p.getId();
		birthDate.DateModify(p.birthDate.getYear(),p.birthDate.getMonth(),p.birthDate.getDay());
	}

	// 	析构函数
	~Person(){
		numberOfObjects--;
	}

	// 	其他公有函数
	int getId(){
		return id;
	}
	
	void show(){
		cout<<"ID:"<<id<<", "<<"生日: ";
		birthDate.show();
	}

	// 	静态函数 getNumberOfObjects() 返回静态变量：Person对象的数量
	static int getNumberOfObjects(){
		return numberOfObjects;
	}

    //////////////////////////////////////////////////////
};


