execute_file=SA.out;
for i in $(ls inputs/);
do
  echo $i
 ./$execute_file <inputs/$i > outputs/$i
done