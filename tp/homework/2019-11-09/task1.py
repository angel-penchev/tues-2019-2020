from collections import defaultdict

def main():
    print(group_by_f(lambda a : a % 2 == 0, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
    print(group_by_f(len, [[1], [7, 8], [1, 2, 3, 4], [4], ["random", "words"]]))


def group_by_f(f, lst):
    d = {}

    for i in lst:
        try:
            d[f(i)].append(i)
        except KeyError:
            d[f(i)] = [i]

    return d


if __name__ == "__main__":
    main()