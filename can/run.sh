
# convert candump foremt file to cansend input
sed -E "s/ +\[[0-9]+\] +/##0/" file

# show a number of differences
diff -y --suppress-common-lines file1 file2 | wc -l
