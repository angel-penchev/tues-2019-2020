def main():
    print(max_notes([[1, 2, 3], [2, 2, 2], [9, 7, 3]]))
    print(max_notes([]))
    print(leading([[1, 10, 2], [2, 2, 2], [9, 7, 3]]))

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


if __name__ == "__main__":
    main()