#include <iostream>
#include <vector>
#include <algorithm>


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

    int max_index1 = 0;
	for (int i = 0; i < n; ++i)
        if (numbers[i] > numbers[max_index1])
            max_index1 = i;
   
    int max_index2 = -1;
	for (int i = 0; i < n; ++i)
        if (i != max_index1 
                && (max_index2 == -1 || numbers[i] > numbers[max_index2]))
            max_index2 = i;

	return int64_t(numbers[max_index1]) * numbers[max_index2];
}



int main(){
    int n;
	cin >> n;
	vector<int> input_numbers(n);
	for (int i = 0; i < n; i++)
		cin >> input_numbers[i];

	cout << max_pairwise_product_fast(input_numbers) << endl; 
    return 0;
}
