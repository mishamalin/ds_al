#!/usr/bin/env python3


def max_pairwise_product(numbers, n):
    max_product = 0
    for i in range(n):
        for j in range(i+1, n):
            max_product = max(
                    max_product,
                    numbers[i] * numbers[j])
    return max_product


if __name__ == "__main__":
    n = int(input())
    input_numbers = [int(x) for x in input().split()]
    print(max_pairwise_product(input_numbers, n))
