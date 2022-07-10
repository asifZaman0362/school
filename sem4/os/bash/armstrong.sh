echo "Armstron numbers from 1 to 500"
for (( i = 1; i <= 500; i++ )); do
	length=${#i}
	product=0
	for (( j = $length - 1; j >= 0; j-- )); do
		digit="${i:$j:1}"
		product=$(( $product + $digit ** $length ))
	done
	if [[ $product -eq $i ]]; then
		echo "$i is an Armstrong number"
	fi
done