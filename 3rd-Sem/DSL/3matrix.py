def is_upper_triangular(matrix):
    """Check if the given matrix is upper triangular."""
    for i in range(1, len(matrix)):
        for j in range(0, i):
            if matrix[i][j] != 0:
                return False
    return True

def sum_diagonal(matrix):
    """Compute the summation of diagonal elements."""
    return sum(matrix[i][i] for i in range(min(len(matrix), len(matrix[0]))))

def transpose(matrix):
    """Compute the transpose of the matrix."""
    return [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]

def add_matrices(matrix1, matrix2):
    """Add two matrices."""
    return [[matrix1[i][j] + matrix2[i][j] for j in range(len(matrix1[0]))] for i in range(len(matrix1))]

def subtract_matrices(matrix1, matrix2):
    """Subtract two matrices."""
    return [[matrix1[i][j] - matrix2[i][j] for j in range(len(matrix1[0]))] for i in range(len(matrix1))]

def multiply_matrices(matrix1, matrix2):
    """Multiply two matrices."""
    result = [[0 for _ in range(len(matrix2[0]))] for _ in range(len(matrix1))]
    for i in range(len(matrix1)):
        for j in range(len(matrix2[0])):
            for k in range(len(matrix2)):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
    return result

def find_saddle_points(matrix):
    """Determine the location of a saddle point if one exists."""
    found = False
    for i in range(len(matrix)):
        min_row_value = min(matrix[i])
        col_index = matrix[i].index(min_row_value)

        # Check if the minimum element is the maximum in its column
        if all(matrix[k][col_index] <= min_row_value for k in range(len(matrix))):
            print(f"Saddle point found at ({i}, {col_index}) with value {min_row_value}")
            found = True

    if not found:
        print("No saddle point found.")

def input_matrix(rows, cols):
    """Input a matrix from the user."""
    matrix = []
    print(f"Enter the elements of the {rows}x{cols} matrix:")
    for i in range(rows):
        row = list(map(int, input(f"Row {i + 1}: ").split()))
        while len(row) != cols:
            print(f"Please enter exactly {cols} integers.")
            row = list(map(int, input(f"Row {i + 1}: ").split()))
        matrix.append(row)
    return matrix

# Main program
if __name__ == "__main__":
    # Input dimensions of the matrix
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))

    # Input the matrix
    matrix = input_matrix(rows, cols)

    print("\nMatrix:")
    for row in matrix:
        print(row)

    print("\nIs the matrix upper triangular?", is_upper_triangular(matrix))
    print("Sum of diagonal elements:", sum_diagonal(matrix))
    print("Transpose of the matrix:")
    for row in transpose(matrix):
        print(row)

    # Input another matrix for addition, subtraction, and multiplication
    print("\nInput another matrix for addition, subtraction, and multiplication:")
    matrix2 = input_matrix(rows, cols)

    print("\nAddition of the two matrices:")
    for row in add_matrices(matrix, matrix2):
        print(row)

    print("\nSubtraction of the two matrices:")
    for row in subtract_matrices(matrix, matrix2):
        print(row)

    print("\nMultiplication of the two matrices:")
    for row in multiply_matrices(matrix, matrix2):
        print(row)

    print("\nFinding saddle points in the matrix:")
    find_saddle_points(matrix)
