#!/usr/bin/env python3


def max_pairwise_product(numbers, n):
    max_product = 0
    for i in range(n):
        for j in range(i + 1, n):
            max_product = max(
                max_product,
                numbers[i] * numbers[j])
    return max_product


def max_pairwise_product_fast(numbers, n):
    max_index1 = 0
    for i in range(n):
        if numbers[i] > numbers[max_index1]:
            max_index1 = i

    max_index2 = -1
    for i in range(n):
        if i != max_index1 \
                and (max_index2 == -1 or numbers[i] > numbers[max_index2]):
            print(i)
            max_index2 = i

    return numbers[max_index1] * numbers[max_index2]


if __name__ == "__main__":
    n = int(input())
    input_numbers = [int(x) for x in input().split()]
    print(max_pairwise_product_fast(input_numbers, n))
