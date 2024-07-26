#include<stdio.h>

#include<string>
#include<iostream>
#include<chrono>

int main() {

	std::string a(100000, 'a');

	std::chrono::system_clock::time_point start1, end1;
	std::chrono::system_clock::time_point start2, end2;

	start1 = std::chrono::system_clock::now();
	std::string b = a;
	end1= std::chrono::system_clock::now();


	start2 = std::chrono::system_clock::now();
	std::string c = a;
	end2 = std::chrono::system_clock::now();

	auto time1 = end1 - start1;
	auto time2 = end2 - start2;
	auto m1 = std::chrono::duration_cast<std::chrono::microseconds>(time1).count();
	auto m2 = std::chrono::duration_cast<std::chrono::microseconds>(time2).count();

	std::cout << "10000文字をコピーと移動で比較" << std::endl;
	std::cout<<"コピー"<<m1<<"μs" << std::endl;
	std::cout<<"コピー"<<m2<<"μs" << std::endl;

	return 0;
}