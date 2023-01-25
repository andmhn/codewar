def high_and_low(numbers):
    nums = [int(x) for x in numbers.split(' ')]
    nums.sort()
    ret = f"{nums[0]} {nums[-1]}"
    return ret


print(high_and_low("8 3 -5 42 -1 0 0 -9 4 7 4 -4"))
