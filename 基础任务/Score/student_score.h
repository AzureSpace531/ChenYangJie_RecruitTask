#include <iostream>
#include <string>
using namespace std;
class Score{
private:
	double Chinese;       // 语文课成绩
	double English;       // 英语课成绩
	double Mathematics;   // 数学课成绩
	
public:
	//////////////////////////////////////////////////////
    //  请补充完整 Score 类
    //
	
    //  无参构造函数
	Score(){
		Chinese=0;
		English=0;
		Mathematics=0;
	}
	
	//  带参构造函数
	Score(double ch,double en,double ma):Chinese(ch),English(en),Mathematics(ma){
	}
	
	//  计算三门课总成绩
	double sum(){
		return Chinese+English+Mathematics;
	}
	
	//  输出三门课成绩和总成绩
	void print()
	{
		cout<<"语文成绩："<<Chinese<<endl;
		cout<<"英语成绩："<<English<<endl;
		cout<<"数学成绩："<<Mathematics<<endl;
		cout<<"总成绩："<<sum()<<endl;
	}
	
	//  修改三门课成绩
	void modify(double chinese,double english,double mathematics)
	{
		Chinese=chinese;
		English=english;
		Mathematics=mathematics;
	}
		
    
    //////////////////////////////////////////////////////
};

class Student{
private:
	string Num;        // 学号
	string Name;       // 姓名
	Score MyScore;     //成绩对象
public:
	//////////////////////////////////////////////////////
    //  请补充完整 Student 类
    //
    
    //无参构造函数
	Student(){}
	
	//带参构造函数
	Studnet(string& nu,string& na,double ch,double en,double ma){
		Num=nu;
		Name=na;
		MyScore.modify(ch,en,ma);
	}
	

	// 输出某学生学号、姓名和成绩
	void print(){
		cout<<"学号："<<Num<<endl;
		cout<<"姓名："<<Name<<endl;
		MyScore.print();
	}
	
	// 修改某学生学号、姓名和成绩
	void modify(string num, string name, float chinese,float english,float mathematics){
		Num=num;
		Name=name;
		MyScore.modify(chinese,english,mathematics);
	}
};
