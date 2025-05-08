def input_matrix(rows, cols):
    matrix = []
    for i in range(rows):
        row = []
        for j in range(cols):
            ele = int(input("Enter element at position ({}, {}): ".format(i, j)))
            row.append(ele)
        matrix.append(row)
    return matrix

def display_matrix(matrix):
    for row in matrix:
        for ele in row:
            print(ele, end="\t")
        print()

def add_matrices(mat1, mat2):
    rows = len(mat1)
    cols = len(mat1[0])
    result = []
    for i in range(rows):
        row = []
        for j in range(cols):
            summ = mat1[i][j] + mat2[i][j]
            row.append(summ)
        result.append(row)
    return result

def subtract_matrices(mat1, mat2):
    rows = len(mat1)
    cols = len(mat1[0])
    result = []
    for i in range(rows):
        row = []
        for j in range(cols):
            diff = mat1[i][j] - mat2[i][j]
            row.append(diff)
        result.append(row)
    return result

def multiply_matrices(mat1, mat2):
    rows1 = len(mat1)
    cols1 = len(mat1[0])
    rows2 = len(mat2)
    cols2 = len(mat2[0])
    if cols1 != rows2:
        print("Error: Incompatible matrix dimensions for multiplication!")
        return None
    result = []
    for i in range(rows1):
        row = []
        for j in range(cols2):
            prod = 0
            for k in range(cols1):
                prod += mat1[i][k] * mat2[k][j]
            row.append(prod)
        result.append(row)
    return result

def transpose_matrix(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    result = []
    for j in range(cols):
        row = []
        for i in range(rows):
            row.append(matrix[i][j])
        result.append(row)
    return result

row = int(input("Enter the number of rows: "))
col = int(input("Enter the number of columns: "))

print("\nEnter elements for matrix 1 ")
mat1 = input_matrix(row, col)
print("\nEnter elements for matrix 2 ")
mat2 = input_matrix(row, col)

print("\nMatrix 1:")
display_matrix(mat1)

print("\nMatrix 2:")
display_matrix(mat2)

choice = 'y'	
while choice == 'y':
    print("--------------------------------------------------------------------------------------------------------------")
    print("\n\t* * * MENU * * *\n")
    print("Enter 1 for Addition of Matrices")
    print("Enter 2 for Subtraction of Matrices")
    print("Enter 3 for Multiplication of Matrices")
    print("Enter 4 for Transpose of Matrix")
    
    ch = int(input("Enter your choice: "))

    if ch == 1:
        # Addition of Matrices
        result = add_matrices(mat1, mat2)
        print("\nResultant Matrix:")
        display_matrix(result)
    elif ch == 2:
        # Subtraction of Matrices
        result = subtract_matrices(mat1, mat2)
        print("\nResultant Matrix:")
        display_matrix(result)
    elif ch == 3:
        # Multiplication of Matrices
        result = multiply_matrices(mat1, mat2)
        if result is not None:
            print("\nResultant Matrix:")
            display_matrix(result)
    elif ch == 4:
        # Transpose of Matrix
        print("\nMatrix 1:")
        display_matrix(mat1)
        print("\nTransposed Matrix:")
        result = transpose_matrix(mat1)
        display_matrix(result)
    else:
        print("Wrong Input!!")
        
    print("--------------------------------------------------------------------------------------------------------------------")
    choice = input("Do you want to continue (y/n): ")
