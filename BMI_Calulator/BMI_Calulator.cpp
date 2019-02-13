// BMI_Calulator.cpp : Demostrate the use of passing my refences in functions.
//BMI = kg/m^2

#include "pch.h"
#include <iostream>
#include <stdio.h>
using namespace std;
#define TARGET_BMI_VALUE 24

//Function prototypes
void Convert_cm2m(float& height);
float BMI_Cal(float height, float weight);

float BMI_Cal(float height, float weight)
{
	//BMI_Cal is passed by value
	float BMI_value;
	//cout << height<<endl; //uncomment to show original height value is modified
	Convert_cm2m(height);//the height value referenced here is the copied version belonging to BMI_Cal
	//cout << height; //uncomment to show original height value is modified

	BMI_value = weight / (height*height);

	return BMI_value;

}

float Get_Wt_BMI_Cal(float height, float BMI_value)
{
	float weight;

	weight = (height/100*height/100) * BMI_value;
	return weight;

}


void Convert_cm2m(float& height)
{
	height = height / 100;
	//no need to return height value as its pass by referenced
}

int main()
{
	char ch;
	float height, weight, BMI_value, TARGET_weight;
    cout << "BMI Calculator!\n"; 
	cout << "Please enter your height in cm:";
	cin >> height;
	cout << "\nPlease enter your weight in KG:";
	cin >> weight;
	
	BMI_value = BMI_Cal(height,weight);
	cout << "\nYour BMI is   " << BMI_value <<endl;
	cout << "\nYour TARGET BMI is   " << TARGET_BMI_VALUE << endl;
	TARGET_weight = Get_Wt_BMI_Cal(height, TARGET_BMI_VALUE);
	cout << "\nYour TARGET WEIGHT is   " << TARGET_weight << endl;

	getchar();//due to keyboard buffer
	getchar();
	return 0;
}

