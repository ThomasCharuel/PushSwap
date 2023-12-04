# make

# valgrind --leak-check=full ./push_swap 10 50
# ./push_swap $(./generator.sh 20)
# ARG="$(./generator.sh 500)"
ARG="-10 5 4 3 -10"
echo $ARG > /tmp/test
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | ./checker $ARG
