def solution(s: str):
    if s == '':
        return []
    splits = []
    temp = ""
    for c in s:
        if len(temp) > 1:
            splits.append(temp)
            temp = ""
            temp += c
        else:
            temp += c
    if len(temp) > 1:
        splits.append(temp)
    else:
        temp += '_'
        splits.append(temp)
    return splits


name = "asdfads"
print(solution(name))
