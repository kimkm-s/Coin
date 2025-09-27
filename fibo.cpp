#include <iostream>
#include <vector>
using namespace std;

// 재귀함수로 구현한 피보나치 수열
int fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// 재귀를 사용하지 않고 반복문으로 구현한 피보나치 수열
int fibonacciIterative(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// 메모이제이션을 활용한 피보나치 수열 (재귀 방식)
vector<int> memo;

int fibonacciMemo(int n) {
    if (n <= 1) {
        return n;
    }
    // 이미 계산된 값이 있으면 바로 반환
    if (memo[n] != -1) {
        return memo[n];
    }
    // 계산된 값을 memo에 저장
    memo[n] = fibonacciMemo(n - 1) + fibonacciMemo(n - 2);
    return memo[n];
}

int main() {
    int n;
    cout << "피보나치 수열의 n번째 항을 구할 값을 입력하세요: ";
    cin >> n;

    // 선택지 출력
    cout << "\n[1] 재귀 함수로 피보나치 구하기\n";
    cout << "[2] 반복문으로 피보나치 구하기\n";
    cout << "[3] 메모이제이션을 사용하여 재귀 함수로 피보나치 구하기\n";
    int choice;
    cout << "원하는 방법을 선택하세요 (1/2/3): ";
    cin >> choice;

    switch (choice) {
    case 1:
        // 재귀 함수로 피보나치 계산
        cout << "재귀 함수로 구한 피보나치 수열의 " << n << "번째 항: " << fibonacciRecursive(n) << endl;
        break;
    case 2:
        // 반복문으로 피보나치 계산
        cout << "반복문으로 구한 피보나치 수열의 " << n << "번째 항: " << fibonacciIterative(n) << endl;
        break;
    case 3:
        // 메모이제이션을 사용한 재귀로 피보나치 계산
        memo.resize(n + 1, -1);  // memo 벡터 초기화
        cout << "메모이제이션을 사용한 재귀 함수로 구한 피보나치 수열의 " << n << "번째 항: " << fibonacciMemo(n) << endl;
        break;
    default:
        cout << "잘못된 선택입니다." << endl;
        break;
    }

    return 0;
}
