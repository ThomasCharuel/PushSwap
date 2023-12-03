make

# valgrind --leak-check=full ./push_swap 10 50
./push_swap $(./generator.sh 10)
