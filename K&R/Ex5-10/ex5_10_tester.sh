gcc -o tester $1
echo "tester" > out
# Proper format
./tester 5 4 + >> out
./tester 5 4 - >> out
./tester 5 4 x >> out 
./tester 5 4 / >> out
./tester 5 1 2 + x >> out
./tester 3 124 54 6 / x + >> out
./tester 1000 234 100 345 1 3 5 / x + x + - >> out
./tester 5 7 1222 77 4 35 8 x / - - + + >> out
./tester 346 99 100 0 0 + - x + >> out
# Improper format
./tester banana >> out
./tester 5 4 + + >> out
./tester 1 2 >> out
./tester 1 2 a + - >> out
./tester >> out
./tester 3 3 3 3 3 + >> out
./tester 3 3 * >> out
d=$(diff correct_out out)
if [ "$d" != "" ]
then
  echo "Failed"
  echo $d
else
  echo "Success"
fi
rm out
rm tester
