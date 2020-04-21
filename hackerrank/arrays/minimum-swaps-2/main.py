'''
Coding Dojo 2020 - Python
Exercise: Minimum Swaps 2
Link: https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

Description:

You are given an unordered array consisting of consecutive integers

[1, 2, 3, ..., n] without any duplicates. You are allowed to swap any two elements. You need to find the minimum number of swaps required to sort the array in ascending order.

For example, given the array [7, 1, 3, 2, 4, 5, 6] we perform the following steps:

i   arr                     swap (indices)
0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
5   [1, 2, 3, 4, 5, 6, 7]

It took 5 swaps to sort the array.


'''
import math
import os
import random
import re
import sys


# Complete the minimumSwaps function below.
def minimumSwaps(arr):

# Passo a passo para mudança:
# 1 - Verificar se o valor da posição i é igual a i+1
# 2 - Caso o passo 1 seja falso:
# 3 - Colocar o valor i+1 na posição i (Uma troca)
# 4 - Descobrir onde estava o valor i+1 no array original
# 5 - Colocar o valor original da posição i no lugar da posição original do valor i+1 (Segunda troca)
# 6 - Atualizar o dicionário de valor, posição com as trocas

    value_index_dictionary = dict()
    for index, value in enumerate(arr):
        value_index_dictionary.update(
            {value: index})
    swapCounter = 0
    for i in range(len(arr)):
        # Passo 1
        if arr[i] != i+1:
            # Armazena valor da posição i
            current_value = arr[i]
            # Passo 3
            arr[i] = i+1
            # Passo 4
            i_plus_1_position = value_index_dictionary.get(i+1)
            # Passo 5
            arr[i_plus_1_position] = current_value
            # Passo 6
            value_index_dictionary.update(
                {i+1: i,
                current_value: i_plus_1_position})

            swapCounter +=1
    return swapCounter


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = minimumSwaps(arr)

    fptr.write(str(res) + '\n')

    fptr.close()
