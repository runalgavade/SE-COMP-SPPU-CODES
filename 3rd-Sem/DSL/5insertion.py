size = int(input("Enter size of list: "))
a = []
for i in range(size):
    val = float(input("Enter No: "))
    a.append(val)

# INSERTION SORT
for i in range(1, size):
    t = a[i]  # Element to be inserted
    j = i - 1  # Element in the sorted part
    # Shift elements of sorted part that are greater than t to one position ahead
    while j >= 0 and t < a[j]:
        a[j + 1] = a[j]
        j -= 1
    a[j + 1] = t

print("Sorted list using Insertion Sort is:")
print(a)

# SHELL SORT
d = size // 2
while d > 0:
    for i in range(d, size):
        t = a[i]
        j = i
        while j >= d and a[j - d] > t:
            a[j] = a[j - d]
            j -= d
        a[j] = t
    d //= 2

print("Sorted list using Shell Sort is:")
print(a)

# Function to display the top five percentages
def display_top_five(a):
    print("Top Five Percentages are:")
    if len(a) < 5:
        start, stop = len(a) - 1, -1
    else:
        start, stop = len(a) - 1, len(a) - 6

    for i in range(start, stop, -1):
        print(a[i])

display_top_five(a)
