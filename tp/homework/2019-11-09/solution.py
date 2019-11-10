# Task 1
def group_by_f(f, lst):
    d = {}

    for i in lst:
        try:
            d[f(i)].append(i)
        except KeyError:
            d[f(i)] = [i]

    return d


# Task 2
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


# Task 3
def max_notes(P):
    max = 0

    for i in P:
        if (max < sum(i)):
            max = sum(i)

    return max


def leading(P):
    results = [0, 0, 0]

    for i in range(0, 3):
        current_max_id = None
        for j in range(0, 3):
            if (current_max_id is None):
                current_max_id = i

            if (P[current_max_id][i] < P[j][i]):
                current_max_id = j

        results[current_max_id] += 1

    return results.index(max(results))
