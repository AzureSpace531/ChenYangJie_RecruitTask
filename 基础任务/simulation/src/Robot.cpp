#include "../include/Robot.h"
#include<random>
using namespace std;
bool Robot::Survive(){
    if(Health_>0)
        return 1;
    else
        return 0;
}

void Robot::Hit(Building &target){
    default_random_engine e;
    uniform_int_distribution<int> u(1,10);
    if(u(e)<hitRate*10){
    	if(target.Health_>atk)
        	target.Health_-=atk;
        else
        	target.Health_=0;
    }
}

void Robot::Hit(Robot &target){
    default_random_engine e;
    uniform_int_distribution<int> u(1,10);
    if(u(e)<hitRate*10){
        if(target.Health_>atk)
        	target.Health_-=atk;
        else{
			target.Health_=0;
			target.SetAtk(0);
		}	
    }
}

bool Building::Survive(){
    if(Health_>0)
        return 1;
    else
        return 0;
}
