#Question 3

def evenSumOfSquares(lst=[]):
    evenLst = lst[::2]
    squareLst = [x*x for x in evenLst]
    # squareLst = [x*x for x in lst[::2]]
    total = sum(squareLst)
    return total

def main():
    evenSum = evenSumOfSquares([1,2,3,4])
    print(evenSum)

if __name__ == "__main__":
    main()