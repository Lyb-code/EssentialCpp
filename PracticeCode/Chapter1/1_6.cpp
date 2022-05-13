#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int upper_limit = 128;
    int num, cnt = 0;
    vector<int> v;
    int arr[upper_limit];
    while (cin >> num && cnt < upper_limit) {
        arr[cnt++] = num;
        v.push_back(num);
    }
    int sum1 = 0, sum2 = 0;;
    for (int i = 0; i < cnt; i++) {
        sum1 += arr[i];
    }
    for (int i = 0; i < v.size(); i++) {
        sum2 += v[i];
    }
    cout << "Sum of " << cnt << " elements: " << sum1 << ". Average: " << sum1 / cnt << endl;
    cout << "Sum of " << v.size() << " elements: "<< sum2 << ". Average: " << sum2 / cnt << endl;
    return 0;
}