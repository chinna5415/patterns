n = int(input("enter the number : "))
length = n*2-1

#  3 3 3 3 3
#  3 2 2 2 3
#  3 2 1 2 3
#  3 2 2 2 3
#  3 3 3 3 3

for i in range(length):
    for j in range(length):
        
        if i < j : minimum = i
        else : minimum = j

        if minimum < length - i : minimum = minimum
        else : minimum = length-i-1

        if minimum < length-j-1 : minimum = minimum
        else : minimum = length-j-1

        print(n-minimum,end=" ")
    print()   
