# problem : 4Sum
# hacktoberfest 2021

class Solution:
    # @return a list of lists of length 4, [[val1,val2,val3,val4]]
    def fourSum(self, num, target):
        result = []
        num.sort()
        firstIndex = 0
        while firstIndex < len(num)-3:
            secondIndex = firstIndex + 1
            while secondIndex < len(num)-2:
                thirdIndex = secondIndex + 1
                fourthIndex = len(num) - 1
                while thirdIndex < fourthIndex:
                    if num[firstIndex] + num[secondIndex] + num[thirdIndex]
                       + num[thirdIndex] > target:
                        # Already too larger, not possible to find any qualified
                        # list afterwards
                        break
                    if num[firstIndex] + num[secondIndex] + num[fourthIndex]
                       + num[fourthIndex] < target:
                        # Already too small, not possible to find any qualified
                        # list forwards
                        break
                    temp = num[firstIndex] + num[secondIndex] + num[thirdIndex]
                         + num[fourthIndex]
                    if temp == target:
                        result.append([num[firstIndex], num[secondIndex],
                                       num[thirdIndex], num[fourthIndex]])
                        # Skip the duplicate numbers as num[thirdIndex]
                        thirdIndex += 1
                        while thirdIndex < fourthIndex + 1 and
                              num[thirdIndex] == num[thirdIndex-1]:
                            thirdIndex += 1
                        # Skip the duplicate numbers as num[fourthIndex]
                        fourthIndex -= 1
                        while fourthIndex > thirdIndex -1 and
                              num[fourthIndex] == num[fourthIndex+1]:
                            fourthIndex -= 1
                    elif temp > target:
                        # Skip the duplicate numbers as num[fourthIndex]
                        fourthIndex -= 1
                        while fourthIndex > thirdIndex -1 and
                              num[fourthIndex] == num[fourthIndex+1]:
                            fourthIndex -= 1
                    else:
                        # Skip the duplicate numbers as num[thirdIndex]
                        thirdIndex += 1
                        while thirdIndex < fourthIndex + 1 and
                              num[thirdIndex] == num[thirdIndex-1]:
                            thirdIndex += 1
                # Skip the duplicate numbers as num[secondIndex]
                secondIndex += 1
                while secondIndex < len(num)-1 and
                      num[secondIndex] == num[secondIndex-1]:
                    secondIndex += 1
            # Skip the duplicate numbers as num[firstIndex]
            firstIndex += 1
            while firstIndex < len(num) - 2 and
                  num[firstIndex] == num[firstIndex-1]:
                firstIndex += 1
        return result
