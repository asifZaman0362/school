echo "Enter height of the pyramid: "
read height

for (( i = $height - 1; i >= 0; i-- )); do
	for (( j = $i - 1; j >= 0; j-- )); do
		printf ' '
	done
	for (( j = 0; j < ($height - $i - 1) * 2 + 1; j++ )); do
		printf '*'
	done
	printf '\n'
done