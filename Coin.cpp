#include <iostream>
using namespace std;

int count500;
int count100;
int count50;
int count10;


void coin(int n)
{
	count500 = n / 500;
	cout << "500원 거스름돈 수 " << count500 << endl;
	count100 = (n - (count500 * 500)) / 100;
	cout << "100원 거스름돈 수 " << count100 << endl;
	count50 = (n - (count500 * 500 + count100 * 100)) / 50;
	cout << "50원 거스름돈 수 " << count50 << endl;
	count10 = (n - (count500 * 500 + count100 * 100 + count50 *50)) / 10;
	cout << "10원 거스름돈 수 " << count10 << endl;
}
int main()
{
	int a;
	cout << "거스름돈을 입력하세요" << endl;
	cin >> a;

	coin(a);
	return 0;

}