#HactoberFest 2021

class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        # Handle the special case that, A is empty
        if len(A) == 0:     return 0
        front, back = 1, 1
        while front < len(A):
            if A[front] != A[front-1]:
                # Not a duplicate item
                A[back] = A[front]
                back += 1
            front += 1
        return back
