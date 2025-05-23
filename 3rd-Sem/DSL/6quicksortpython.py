def quickSort(arr):
    if len(arr) <= 1:  # If the array is empty or has one element
        return arr

    pivot = arr[len(arr) // 2]  # Set pivot element
    left = []  # Empty list to store left part
    middle = []  # Empty list to store middle elements
    right = []  # Empty list to store right part

    for i in arr:
        if i < pivot:
            left.append(i)
        elif i == pivot:
            middle.append(i)
        else:
            right.append(i)

    return quickSort(left) + middle + quickSort(right)

# Function for displaying top scores:
def top5(arr):
    sorted_scores = quickSort(arr)
    return sorted_scores[-5:]  # Get the last five elements (top scores)

# Defining main function:
def main():
    percent = []  # List to store percentages
    
    total = int(input("Total number of students are:\t"))  # Input for total students
    for i in range(total):
        percent_in = float(input(f"Enter percentage for student {i + 1}:\t"))
        percent.append(percent_in)
    
    print(f"-----\nPercentages of students are:\t {percent}\n-----")
    sorted_percent = quickSort(percent)
    print(f"-----\nSorted marks (using quick sort algorithm):\t{sorted_percent}\n-----")
    
    # Display the top five scores
    top_scores = top5(percent)
    print(f"-----\nTop five scores are:\t{sorted(top_scores, reverse=True)}\n-----")

# Calling main function:
if __name__ == "__main__":
    main()
