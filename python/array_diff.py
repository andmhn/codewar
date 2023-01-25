def array_diff(a_bd, b_gt):
    ret = [i for i in a_bd if i not in set(b_gt)]
    return ret


print(array_diff([1, 2], [1]))
