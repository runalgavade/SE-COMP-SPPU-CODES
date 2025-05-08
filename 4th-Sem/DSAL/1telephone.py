def tele_database():
    phone_data = []
    n = int(input("Enter Number of Clients: "))
    print("Enter Phone Numbers (as strings):\n")
    for _ in range(n):
        x = input("--> ")
        phone_data.append(x)
    return phone_data


def hash_function_1(key_ele, m_size):
    return int(key_ele) % m_size


def hash_function_2(key_ele):
    return 1 + (int(key_ele) % 11)


def hashtable(ht):
    print(f"\nHash Value \tKey")
    for ele in range(len(ht)):
        if ht[ele] != -1:
            print(f"\t{ele} \t---> \t{ht[ele]}")
        else:
            print(f"\t{ele}")


phone_database = tele_database()
m = int(input("Enter Hash Table Size: "))
hash_table = [-1] * m

opt = int(input("If collision occurs, which collision resolution technique do you want to use?\n\t1. Linear Probing\n\t2. Double Hashing: "))

for k in phone_database:
    h_1 = hash_function_1(k, m)
    h_2 = hash_function_2(k)

    if hash_table[h_1] == -1:
        hash_table[h_1] = k
    else:
        if opt == 1:  # Linear Probing
            while hash_table[h_1] != -1:
                h_1 = (h_1 + 1) % m
            hash_table[h_1] = k
        elif opt == 2:  # Double Hashing
            i = 0
            while hash_table[h_1] != -1:
                i += 1
                h_1 = (h_1 + (i * h_2)) % m
            hash_table[h_1] = k

hashtable(hash_table)

# Pause before exiting
input("\nPress Enter to exit...")
