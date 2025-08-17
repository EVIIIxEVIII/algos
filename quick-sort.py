def quicksort(array):
    if len(array) <= 1:
        return array

    p1, p2 = 0, 0
    pivot = array[-1]

    while p1 < len(array) - 1:
        if array[p1] <= pivot:
            if array[p1] != array[p2] and array[p2] > pivot:
                array[p1], array[p2] = array[p2], array[p1]
            p2 += 1
        p1 += 1

    array[p2], array[-1] = array[-1], array[p2]
    left = quicksort(array[:p2])
    right = quicksort(array[p2+1:])

    return left + [pivot] + right


print(quicksort([3, 2, 5, 0, 1, 8, 7, 6, 9, 4]))
print(quicksort([3, 2, 0, 5, 5, 8, 10]))
