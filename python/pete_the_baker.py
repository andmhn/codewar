# So easy to solve man
def cakes(recipe: dict, available: dict) -> int:
    """Find How many cake can be made"""
    total = []
    for key, value in recipe.items():
        try:
            a = available[key]
        except KeyError:
            return 0
        total.append(int(a/value))
    return min(total)


recipe2 = {'apples': 99, 'milk': 94, 'sugar': 93}
available2 = {'pears': 6564, 'cream': 7515, 'milk': 9435, 'chocolate': 4354,
              'cocoa': 7824, 'flour': 4305, 'oil': 2189, 'crumbles': 9121,
              'apples': 3178, 'nuts': 57}
print(cakes(recipe2, available2) == 0)

recipe3 = {"flour": 500, "sugar": 200, "eggs": 1}
available3 = {"flour": 1200, "sugar": 1200, "eggs": 5, "milk": 200}
print(cakes(recipe3, available3) == 2)
