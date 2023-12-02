#!/bin/bash

# Check if the number of integers to generate (X) is passed as an argument
if [ $# -eq 0 ]; then
    echo "Usage: $0 <number-of-integers>"
    exit 1
fi

X=$1  # Number of integers to generate

# Initialize an empty string to hold the integers
output=""

# Generate X random integers and append them to the output string
for (( i = 0; i < X; i++ )); do
    output+="$(( RANDOM )) "
done

# Print the generated integers
echo $output
