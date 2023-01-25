def descending_order(num):
    arr = [int(x) for x in str(num)]
    arr.sort(reverse=True)
    ret = ""
    for i in arr:
        ret += str(i)
    return int(ret)


print(descending_order(127563))
