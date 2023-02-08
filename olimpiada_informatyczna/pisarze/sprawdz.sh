echo Testowanie...
./pistestgen.py 4 test pis_dlazaw
./pis.py < test.in > test.out1
./porownaj.py test.out test.out1