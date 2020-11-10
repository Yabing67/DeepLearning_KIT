#include<iostream>
#include<cstdlib>
//#include<cmath>
#include<iomanip>
using namespace std;

double apple_price = 3.5, banana_price = 4.2;
double sum = 0;
double apple_weight = 0, banana_weight = 0;

void showMenu() {
	cout << "************************************" << endl;
	cout << "*欢迎使用自动售卖机，请输入您的选择*" << endl;
	cout << "*1. 下订单                         *" << endl;
	cout << "*2. 退出自动售卖                   *" << endl;
	cout << "************************************" << endl;
}

void showSubMenu() {
	cout << "++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+请输入您要进行的操作：            +" << endl;
	cout << "+1. 购买苹果（3.5元/公斤）         +" << endl;
	cout << "+2. 购买香蕉（4.2元/公斤）         +" << endl;
	cout << "+3. 结账                           +" << endl;
	cout << "+4. 放弃购买                       +" << endl;
	cout << "++++++++++++++++++++++++++++++++++++" << endl;
}

int GetInteger() {

	char buf[100] = { 0 };
	while (strlen(buf) == 0)
		cin.getline(buf, 100);
	return atoi(buf);
}

double GetDouble() {

	char buf[100] = { 0 };
	while (strlen(buf) == 0)
		cin.getline(buf, 100);
	return atof(buf);
}

void dealOrder() {
	while (1) 
	{
		showSubMenu();
		cout << "您目前购买了" << apple_weight << "公斤苹果";
		cout << "和" << banana_weight << "公斤香蕉， " ;
		cout << "总价为：" << fixed << setprecision(2)
			<< setw(8) << sum << "元" << endl;//控制输出格式
		cout << "您的选择是：" << endl;
		//int input = GetInteger();
		int input;
		cin >> input;
		int weight;
		//int weight = GetDouble();
		switch (input)
		{
		case 1:
			cout << "请输入称重（公斤）：" << endl;
			cin >> weight;
			cout << endl;
			apple_weight += weight;
			sum += apple_price * weight;
			break;
		case 2:
			cout << "请输入称重（公斤）" << endl;
			cin >> weight;
			banana_weight += weight;
			sum += banana_price * weight;
			break;
		case 3:
			if (sum > 1E-6)//确定买了水果
			{
				cout << "您一共购买了";
				if (fabs(apple_weight) > 1E-6)
					cout << apple_weight << "公斤苹果";
				if (fabs(banana_weight) > 1E-6)
					cout << "和" << banana_weight << "公斤香蕉， ";
				cout << "您应付的总价为：" << sum << "元" << endl;
				system("pause");
				system("cls");
			}
			return;
		case 4:
			return;
		}
	}
}


int main()
{
	while(1)
	{
		sum = 0;
		apple_weight = 0;
		banana_weight = 0;
		showMenu();
		cout << "您的选择是：" << endl;
		int input;
		//int input = GetInteger();
		cin >> input;
		cout << endl;
		switch (input)
		{
		case 1:
			dealOrder();
			break;
		case 2:
			return 0;
		}
	}
}