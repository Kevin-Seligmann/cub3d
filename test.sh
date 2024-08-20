invalid_maps="./assets/maps/tests/invalid"
valid_maps="./assets/maps/tests/valid"
test_sucessfull=0

rm -f test_logs_valid test_logs_invalid

# Exit code 0: Success
# Exit code 20: Memory error
# Exit code 1: Regular failure

echo "Testing invalid maps..."; echo
for file in $invalid_maps/*
do

	echo "Testing: " $(basename $file)

	valgrind --log-file=/dev/null --error-exitcode=20 --suppressions=cub3d.supp --track-fds=yes --leak-check=full --show-leak-kinds=all ./cub3D $file 2>temp_log_err
	exit_code=$?

	echo Test name: $(basename $file) >> test_logs_invalid
	cat temp_log_err >> test_logs_invalid
	echo Exit code: $exit_code $'\n' >> test_logs_invalid

	if [ $exit_code -eq 20 ]
	then
		echo "Memory error."
		test_successful=1
	fi
	if [ $exit_code -eq 0 ]
	then
		echo 'Unpexpected good run (exit code = 0).'
		test_successful=1
	fi

done

echo; echo "Testing valid maps... pay attention to the map name"; echo
for file in $valid_maps/*
do

	echo "Testing: " $(basename $file)
	
	./cub3D $file 2>temp_log_err
	exit_code=$?

	echo Test name: $(basename $file) >> test_logs_valid
	cat temp_log_err >> test_logs_valid
	echo Exit code: $exit_code $'\n' >> test_logs_valid

	if [ $exit_code -eq 1 ]
	then
		echo "Unexpected exit."
		test_successful=1
	fi

done

echo; echo "Testing valid maps with valgrind"; 
echo "This test is slow, you might want to skip it"; echo
for file in $valid_maps/*
do

	echo "Testing: " $(basename $file)

	valgrind --log-file=/dev/null --error-exitcode=20 --suppressions=cub3d.supp --track-fds=yes --leak-check=full --show-leak-kinds=all ./cub3D $file 2>temp_log_err
	exit_code=$?

	echo Test name: $(basename $file) >> test_logs_valid
	cat temp_log_err >> test_logs_valid
	echo Exit code: $exit_code $'\n' >> test_logs_valid

	if [ $exit_code -eq 20 ]
	then
		echo "Memory error."
		test_successful=1
	fi
	if [ $exit_code -eq 1 ]
	then
		echo "Unexpected exit."
		test_successful=1
	fi

done

if [ $test_successful -eq 1 ]
then
	echo "Test failed"
else
	echo "Test successful"
fi


rm -f temp_log_err
