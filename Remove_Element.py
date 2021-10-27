# problem : Remove Element
# Hacktoberfest 2021

class Solution:
        def removeElement(self, A, elem):
        front, back = 0, 0
        while front < len(A):
            if A[front] != elem:
                # Not to be removed
                A[back] = A[front]
                back += 1
            front += 1
        return back
