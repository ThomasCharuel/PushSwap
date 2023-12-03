#!/bin/bash

# Check if the number of integers to generate (X) is passed as an argument
if [ $# -eq 0 ]; then
    echo "Usage: $0 <number-of-integers>"
    exit 1
fi

X=$1  # Number of integers to generate
MIN_INT=-2147483648  # Minimum integer value
MAX_INT=2147483647   # Maximum integer value

declare -A num_array  # Associative array to store unique numbers

# Function to generate a random number within a range
function rand() {
    # Generate a number in the range of 0 to (MAX_INT - MIN_INT)
    local range=$((MAX_INT - MIN_INT))
    local random_num=$(( $RANDOM + ($RANDOM << 15) + ($RANDOM << 30) ))

    # Adjust the number to fit in the range of MIN_INT to MAX_INT
    echo $(( random_num % range + MIN_INT ))
}

# Generate X unique random integers
while [ ${#num_array[@]} -lt $X ]; do
    rand_num=$(rand)
    num_array["$rand_num"]=1
done

# Output the unique numbers
for num in "${!num_array[@]}"; do
    echo -n "$num "
done
echo
