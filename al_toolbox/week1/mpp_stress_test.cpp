#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int64_t max_pairwise_product(vector<int>& numbers){
	int64_t max_product = 0;
	int n = numbers.size();

	for (int first = 0; first < n; ++first){
		for (int second = first + 1; second < n; ++second){
			max_product = std::max(
					max_product, 
					int64_t(numbers[first]) * numbers[second]
                    );
		}
	}
	return max_product;
}



int64_t max_pairwise_product_fast(vector<int>& numbers){
	int n = numbers.size();

    int max_index1 = -1;
	for (int i = 0; i < n; ++i)
        if (i == -1 || numbers[i] > numbers[max_index1])
            max_index1 = i;
   
    int max_index2 = -1;
	for (int i = 0; i < n; ++i)
        if (i != max_index1 
                && (i == -1 || numbers[i] > numbers[max_index2]))
            max_index2 = i;

	return int64_t(numbers[max_index1]) * numbers[max_index2];
}



int main(){
    const int MAX_VAL = 100000;
    const int MIN_LEN = 2; 
    const int MAX_LEN = 10000;
    
    while (true) {
        int n = rand() % MAX_LEN + MIN_LEN;
        cout << n << endl;
        vector<int> a;
        for (int i = 0; i < n; ++i){
            a.push_back(rand() % MAX_VAL);
        }

        // for (int i = 0; i < n; ++i){
        //   cout << a[i] << " "; 
        // }
        cout << endl;

        int64_t res1 = max_pairwise_product(a);
        int64_t res2 = max_pairwise_product_fast(a);
            
        if (res1 != res2){
            cout << "Wrong answer: " << res1 << " " << res2 << endl;
            break;
        } else {
            cout << "OK\n";
        }
    }
    int n;
    cin >> n;
    vector<int> input_number(n);
    for (int i = 0; i < n; ++i){
        cin >> input_number[i];
    }


    cout << max_pairwise_product(input_number) << endl;
    cout << max_pairwise_product_fast(input_number) << endl;
    return 0;
}
