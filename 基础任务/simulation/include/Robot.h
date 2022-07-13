#pragma once
#include<string>
#include<iostream>
using namespace std;

class Building{
private:
    string name;
public:
    double Health_;
    Building(string n,double h):name(n),Health_(h){}
    bool Survive();
};

class  Robot{
private:
    string name;
    double atk,hitRate;
public:
    double Health_;
    Robot(string n,double h,double a,double hR):name(n),Health_(h),atk(a),hitRate(hR){}
    void SetAtk(double a){atk=a;}
    bool Survive();
    void Hit(Building &target);
    void Hit(Robot &target);
};