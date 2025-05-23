def input_marks():
    marks = int(input("Enter Total No Of Students: "))
    a = []
    for i in range(marks):
        val = float(input("Enter Percentage: "))
        a.append(val)
    return a

def selection_sort(a):
    for i in range(len(a)):
        min_index = i
        for j in range(i + 1, len(a)):
            if a[j] < a[min_index]:
                min_index = j
        a[i], a[min_index] = a[min_index], a[i]
    return a

def bubble_sort(a):
    n = len(a)
    for i in range(n):
        for j in range(0, n - i - 1):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
    return a

def display_top_five(a):
    print("Top Five Percentages are:")
    top_five = sorted(a, reverse=True)[:5]  # Get top five in descending order
    for percentage in top_five:
        print(percentage)

# Main execution
marks_list = input_marks()

# Sort using Selection Sort
sorted_marks_selection = selection_sort(marks_list.copy())
print("Sorted list using Selection Sort (Ascending Order) is:")
print(sorted_marks_selection)

# Sort using Bubble Sort
sorted_marks_bubble = bubble_sort(marks_list.copy())
print("Sorted list using Bubble Sort (Ascending Order) is:")
print(sorted_marks_bubble)

# Display the top five percentages
display_top_five(sorted_marks_selection)  # You can use either sorted_marks_selection or sorted_marks_bubble
