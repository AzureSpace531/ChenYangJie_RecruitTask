#include <iostream>
#include <string>
using namespace std;
class Score{
private:
	double Chinese;       // ���Ŀγɼ�
	double English;       // Ӣ��γɼ�
	double Mathematics;   // ��ѧ�γɼ�
	
public:
	//////////////////////////////////////////////////////
    //  �벹������ Score ��
    //
	
    //  �޲ι��캯��
	Score(){
		Chinese=0;
		English=0;
		Mathematics=0;
	}
	
	//  ���ι��캯��
	Score(double ch,double en,double ma):Chinese(ch),English(en),Mathematics(ma){
	}
	
	//  �������ſ��ܳɼ�
	double sum(){
		return Chinese+English+Mathematics;
	}
	
	//  ������ſγɼ����ܳɼ�
	void print()
	{
		cout<<"���ĳɼ���"<<Chinese<<endl;
		cout<<"Ӣ��ɼ���"<<English<<endl;
		cout<<"��ѧ�ɼ���"<<Mathematics<<endl;
		cout<<"�ܳɼ���"<<sum()<<endl;
	}
	
	//  �޸����ſγɼ�
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
	string Num;        // ѧ��
	string Name;       // ����
	Score MyScore;     //�ɼ�����
public:
	//////////////////////////////////////////////////////
    //  �벹������ Student ��
    //
    
    //�޲ι��캯��
	Student(){}
	
	//���ι��캯��
	Studnet(string& nu,string& na,double ch,double en,double ma){
		Num=nu;
		Name=na;
		MyScore.modify(ch,en,ma);
	}
	

	// ���ĳѧ��ѧ�š������ͳɼ�
	void print(){
		cout<<"ѧ�ţ�"<<Num<<endl;
		cout<<"������"<<Name<<endl;
		MyScore.print();
	}
	
	// �޸�ĳѧ��ѧ�š������ͳɼ�
	void modify(string num, string name, float chinese,float english,float mathematics){
		Num=num;
		Name=name;
		MyScore.modify(chinese,english,mathematics);
	}
};
