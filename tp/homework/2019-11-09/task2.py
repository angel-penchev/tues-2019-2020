def main():
    A = ("A", [("p", 5), ("q", 3)])
    B = ("B", [("p", 4), ("q", 3)])
    C = ("C", [("p", 3)])
    D = ("D", [("p", 4.5), ("q", 3), ("r", 1)])
    # print(is_stronger(A, B))
    # print(is_stronger(B, A))
    # print(least_stronger(B, [A, C, D]))
    # print(least_stronger(A, [B, C, D]))
    print(strong_relation([A, B, C]))


def is_stronger(a, b):
    is_stronger = False

    for i in b[1]:
        is_found = False
        for j in a[1]:
            if (i[0] == j[0]):
                is_found = True
                if (i[1] > j[1]):
                    return False
                elif (i[1] < j[1]):
                    is_stronger = True

    if(is_found and is_stronger):
        return True


def least_stronger(a, l):
    current_min = None
    current_obj = []
    a_sum = sum([i[1] for i in a[1]])
    for j in [i for i in l if (is_stronger(i, a))]:
        j_sum = sum([k[1] for k in j[1]])
        if (current_min is None or current_min > a_sum - j_sum):
            current_min = a_sum - j_sum
            current_obj = j

    return current_obj


def strong_relation(l):
    return [(i, [j[0] for j in l if is_stronger(j, i)]) for i in l]


if __name__ == "__main__":
    main()