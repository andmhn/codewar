def disemvowel(string_: str):
    vowel = ['a', 'e', 'i', 'o', 'u']
    out = ""
    for i in string_:
        if i.lower() not in vowel:
            out += i
    return out


print(disemvowel("This website is for losers LOL!"))
