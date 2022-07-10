echo "Enter the number of elements: "
read len
for (( i = 0; i < len; i++ )); do
	echo "Enter element #$i: "
	read val
	arr[$i]=$val
done
smallest=${arr[0]}
for (( i = 0; i < len; i++ )); do
	if [[ ${arr[$i]} -lt $smallest ]]; then
		smallest=${arr[$i]}
	fi
done
echo "The smallest element of the array is: $smallest"