from itertools import permutations

def bugged_sort(a, b):
    n = len(a)
    if(n == 0): return False

    sorted_pairs = sorted(zip(a, b), key=lambda pair: min(pair))
    a_sort, b_sort = zip(*sorted_pairs)

    a = list(a_sort)
    b = list(b_sort)
    print(a)
    print(b)

    pairs = [[]] * n

    for i in range(n):
        pairs[i] = [a[i], b[i]]

    dp = [[0] * n for _ in range(4)]

    # it is possible to achieve the first row to be sorted by
    # not flipping its elements
    dp[0][0] = 1

    # it is possible to achieve the first row to be sorted by
    # flipping its elements
    dp[3][0] = 1

    for i in range(1, n):
        # if previous was flipped it means that this condition is not true
        # from the perspective of that sequence of flips
        if(pairs[i - 1][0] < pairs[i][0] and pairs[i - 1][1] < pairs[i][1]):
            # ------------------------------------------------------------------------------------
            # i - 1 WAS NOT fliped, thus the condition is still true that's why we don't need to flip now:
            # ------------------------------------------------------------------------------------

            # can we achieve an even number of flips excluding i
            dp[0][i] |= dp[0][i - 1]
            # can we achieve and odd number of flips excluding i
            dp[1][i] |= dp[1][i - 1]


            # ------------------------------------------------------------------------------------
            # i - 1 WAS fliped, thus the condition is now false and we need to do the following:
            # ------------------------------------------------------------------------------------

            # is it possible to achieve sorted state by odd flips including i - 1 =>
            # we can flip i to achieve an even number of flips
            dp[2][i] |= dp[3][i - 1]

            # is it possible to achieve a sorted state by even flips, including i - 1 =>
            # we can flip i to achieve sorted by odd number of flips
            dp[3][i] |= dp[2][i - 1]

        if(pairs[i - 1][0] < pairs[i][1] and pairs[i - 1][1] < pairs[i][0]):
            # ------------------------------------------------------------------------------------
            # i - 1 WAS flipped, thus the current row is sorted, so we DONT need to flip i:
            # ------------------------------------------------------------------------------------

            # even number of flips before, including i - 1 => we don't need to flip now
            dp[0][i] |= dp[2][i - 1];

            # odd number of flips before, including i - 1 => we don't need to flips now
            dp[1][i] |= dp[3][i - 1];

            # ------------------------------------------------------------------------------------
            # i - 1 WAS NOT flipped, thus the current row is NOT sorted, so we DO need to flip i:
            # ------------------------------------------------------------------------------------

            # odd number of flips excluding i - 1 => flip i to obtain an even number of flips
            dp[2][i] |= dp[1][i - 1];

            # even number of flips excluding i - 1 => flip i to obtain odd flips including i
            dp[3][i] |= dp[0][i - 1];

    # dp[0][n-1] can we achieve a sorted state by doing an even number of flips excluding n - 1
    # dp[2][n-1] can we achieve a sorted state by doing an even number of flips including n - 1
    return (dp[0][n-1] | dp[2][n - 1])

a = [5, 1, 9, 12, 3, 13, 7]
b = [2, 4, 11, 14, 6, 10, 8]

bugged_sort(a, b)

#t = int(input())
#
#for _ in range(t):
#    n = int(input())  # Length of each array
#    a = list(map(int, input().split()))
#    b = list(map(int, input().split()))
#
#    print("YES" if bugged_sort(a, b) else "NO")



#numbers = [1, 2, 3, 4, 5, 6]
#perms = list(permutations(numbers))
#
#sortable = 0
#for perm in perms:
#    a = perm[:3]
#    b = perm[3:]
#    sortable += 1 if (bugged_sort(a, b)) else 0
#
#print(sortable)
#print(len(perms))


