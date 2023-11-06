lst = ['1', '3', '4', '1', '5', '3', '2', '3','1','1']
most_occuring = {}

# Count the occurrences of elements in lst
for i in lst:
    if i in most_occuring:
        most_occuring[i] += 1
    else:
        most_occuring[i] = 1

print(most_occuring)
most_occured=max(most_occuring,key=most_occuring.get)

print(most_occured,">>" ,most_occuring[most_occured])
