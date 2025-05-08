# Function to accept the names of students who play a specific sport
def accept_args(student_list, sport_name):
    num_students = int(input(f"Enter the total number of students who play {sport_name}: "))
    for i in range(num_students):
        name = input(f"Enter the name of student {i + 1} who plays {sport_name}: ")
        student_list.append(name)

# Function to display the list of students who play a specific sport
def show(student_list, sport_name):
    print(f"\nStudents who play {sport_name}:")
    for name in student_list:
        print(name, end=" ")
    print()

# Function to search for a student name in a list (returns 1 if found, else 0)
def search_set(student_list, student_name):
    return 1 if student_name in student_list else 0

# Function to find the intersection of two sets (common students in both lists)
def find_intersection_set(set1, set2, result_set):
    for student in set1:
        if search_set(set2, student):
            result_set.append(student)

# Function to find elements in set1 that are not in set2 (difference)
def find_different_set(set1, set2, result_set):
    for student in set1:
        if not search_set(set2, student):
            result_set.append(student)

# Function to find the union of two sets (all unique students from both lists)
def find_union_set(set1, set2, result_set):
    result_set.extend(set1)
    for student in set2:
        if not search_set(set1, student):
            result_set.append(student)

# Main program function to display a menu and perform set operations
def main():
    cricket_players = []
    badminton_players = []
    football_players = []

    while True:
        print("\nMenu:")
        print("\t1. Accept the information")
        print("\t2. List of students who play both cricket and badminton")
        print("\t3. List of students who play either cricket or badminton but not both")
        print("\t4. Number of students who play neither cricket nor badminton")
        print("\t5. Number of students who play cricket and football but not badminton")
        print("\t6. Exit")

        choice = int(input("Enter your choice: "))
        result = []

        if choice == 6:
            print("Thank you!")
            break

        elif choice == 1:
            accept_args(cricket_players, "cricket")
            accept_args(badminton_players, "badminton")
            accept_args(football_players, "football")
            show(cricket_players, "cricket")
            show(badminton_players, "badminton")
            show(football_players, "football")

        elif choice == 2:
            find_intersection_set(cricket_players, badminton_players, result)
            show(result, "both cricket and badminton")

        elif choice == 3:
            union_result = []
            intersection_result = []
            find_union_set(cricket_players, badminton_players, union_result)
            find_intersection_set(cricket_players, badminton_players, intersection_result)
            find_different_set(union_result, intersection_result, result)
            show(result, "either cricket or badminton but not both")

        elif choice == 4:
            union_result = []
            find_union_set(cricket_players, badminton_players, union_result)
            find_different_set(football_players, union_result, result)
            show(result, "neither cricket nor badminton")
            print("Number of students who play neither cricket nor badminton: ", len(result))

        elif choice == 5:
            intersection_result = []
            find_intersection_set(cricket_players, football_players, intersection_result)
            find_different_set(intersection_result, badminton_players, result)
            show(result, "cricket and football but not badminton")
            print("Number of students who play cricket and football but not badminton: ", len(result))

        else:
            print("Invalid choice, please try again.")

# Run the main function
if __name__ == "__main__":
    main()
