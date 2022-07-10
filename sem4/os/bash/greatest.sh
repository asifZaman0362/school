echo "Enter the number of elements: "
read len
for (( i = 0; i < len; i++ )); do
	echo "Enter element #$i: "
	read val
	arr[$i]=$val
done
greatest=${arr[0]}
for (( i = 0; i < len; i++ )); do
	if [[ ${arr[$i]} -gt $greatest ]]; then
		greatest=${arr[$i]}
	fi
done
echo "The greatest element of the array is: $greatest"