#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
using namespace std;

int main() {
    // 1. 사용자로부터 입력을 받는 부분
    int n;
    cout << "몇 개의 숫자를 입력하시겠습니까? "; // std::cout
    while (!(cin >> n) || n <= 0) {  // std::cin, 오류 처리 (cin.fail() 등)
        cin.clear();  // std::cin.clear(), 입력 오류 플래그 초기화
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // std::cin.ignore(), 버퍼 비우기
        cout << "잘못된 입력입니다. 1 이상의 숫자를 입력하세요: "; // std::cout
    }

    vector<double> numbers(n);  // std::vector

    // 2. n개의 숫자 입력 받기
    cout << "\n숫자 " << n << "개를 입력하세요: "; // std::cout
    for (int i = 0; i < n; i++) {
        while (!(cin >> numbers[i])) {  // std::cin
            cin.clear();  // std::cin.clear(), 입력 오류 플래그 초기화
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // std::cin.ignore(), 버퍼 비우기
            cout << "잘못된 입력입니다. 숫자를 다시 입력하세요: "; // std::cout
        }
    }

    // 3. 숫자들의 합과 평균을 계산
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];  // 더하기 연산
    }
    double average = sum / n;

    // 4. 결과 출력 (소수점 2자리로 출력)
    cout << "\n결과 테이블 (소수점 2자리로 출력):\n"; // std::cout
    cout << setw(10) << "Index" << setw(15) << "Number" << setw(15) << "Square" << setw(15) << "Cubic" << endl; // std::setw, std::endl

    for (int i = 0; i < n; i++) {
        cout << setw(10) << i + 1  // std::setw
            << setw(15) << fixed << setprecision(2) << numbers[i]  // std::fixed, std::setprecision
            << setw(15) << fixed << setprecision(2) << numbers[i] * numbers[i]  // std::fixed, std::setprecision
            << setw(15) << fixed << setprecision(2) << numbers[i] * numbers[i] * numbers[i]  // std::fixed, std::setprecision
            << endl;  // std::endl
    }

    // 5. 최종 결과 출력
    cout << "\n총합: " << fixed << setprecision(2) << sum << endl;  // std::cout, std::fixed, std::setprecision, std::endl
    cout << "평균: " << fixed << setprecision(2) << average << endl;  // std::cout, std::fixed, std::setprecision, std::endl

    // 6. 출력 버퍼 강제로 비우기
    cout << flush;  // std::flush

    return 0;
}
