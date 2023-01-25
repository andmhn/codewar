# https://www.codewars.com/kata/54da5a58ea159efa38000836/train/python
# finding the odd item

def find_it(seq: list) -> int:
    for i in set(seq):
        if seq.count(i) % 2 != 0:
            return i


print(find_it([20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5]) == 5)
