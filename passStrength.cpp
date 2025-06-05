#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <thread>
#include <chrono>
using namespace std;

int point = 0;
int fpoint = 0;

void len_check(string str)
{
	int size = str.length();
	if (size < 8)
	{
		point = point - 2;
	}
	else if (size < 12)
	{
		point = point + 1;
	}
	else
	{
		point = point + 2;
	}
}

void char_check(string str)
{
	regex num("[0-9]");
	regex alpha_U("[A-Z]");
	regex alpha_L("[a-z]");
	regex special_Char("[~`!@#$%^&*()_+=-{};:'\"<>[],.\\/?|]");

	smatch _num, _alpha_U, _alpha_L, _special_char;
	regex_search(str, _num, num);
	regex_search(str, _alpha_U, alpha_U);
	regex_search(str, _alpha_L, alpha_L);
	regex_search(str, _special_char, special_Char);
	if (!_num.empty())
	{
		point++;
	}
	else
		point--;

	if (!_alpha_L.empty())
	{
		point++;
	}
	else
		point--;

	if (!_alpha_U.empty())
	{
		point++;
	}
	else
		point--;

	if (!_special_char.empty())
	{
		point++;
	}
	else
		point--;

	string rev_str = str;
	reverse(rev_str.begin(), rev_str.end());
	smatch rev_num, rev_alpha_U, rev_alpha_L, rev_special_char;

	regex_search(rev_str, rev_num, num);
	regex_search(rev_str, rev_alpha_U, alpha_U);
	regex_search(rev_str, rev_alpha_L, alpha_L);
	regex_search(rev_str, rev_special_char, special_Char);

	if (!_num.empty())
	{
		if (_num.position(0) > 0 || rev_num.position(0) > 0)
		{
			point++;
		}
		else
			point--;
	}

	if (!_alpha_L.empty())
	{
		if (_alpha_L.position(0) > 0 || rev_alpha_L.position(0) > 0)
		{
			point++;
		}
		else
			point--;
	}
	if (!_alpha_U.empty())
	{
		if (_alpha_U.position(0) > 0 || rev_alpha_U.position(0) > 0)
		{
			point++;
		}
		else
			point--;
	}
	if (!_special_char.empty())
	{
		if (_special_char.position(0) > 0 || rev_special_char.position(0) > 0)
		{
			point++;
		}
		else
			point--;
	}
}

void check_pass_str(string str)
{
	len_check(str);
	char_check(str);
}

int main()
{
	int very_weak_threshold = -5;
	int weak_threshold = 0;
	int average_threshold = 3;
	int good_threshold = 6;
	int strong_threshold = 8;
	int totalPoint = 0;
	char ch;
	while(1){
		cout << "Check Password Strength" << endl;
		string pass_str;
		cin >> pass_str;
		check_pass_str(pass_str);
		totalPoint = point + fpoint;
		
		if (totalPoint <= very_weak_threshold){
        	cout << "--> Oh no! Your password is as secure as a house no door." << endl;
		}
		else if(totalPoint <=weak_threshold){
			cout << "--> Your password is a bit like leaving your front door unlocked."<<endl;
		}
		else if(totalPoint <=average_threshold){
			cout << "--> Try more!! Your password is like having a rope on your door."<<endl;
		}
		else if(totalPoint <= good_threshold){
			cout << "--> you can improve the password."<<endl;
		}
		else if(totalPoint < strong_threshold){
			cout << "--> Nice ! Your password is like a fortress protecting your secrets."<<endl;
		}
		else 
		cout << "--> Wow! Your password is like Fort Knox. You're a security superhero!" << endl;
		cout << "--> Total points:  " << totalPoint << endl;

		cout << "Do you want to continue (y/n): " << endl;
		cin >> ch;

		if(ch == 'Y'||ch=='y'){
			cout << "continuing..." << endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
		}
		else{
			cout << "exiting...";
			std::this_thread::sleep_for(std::chrono::seconds(3));
			break;
		}
	}
	return 0;
}
