""" Test script

This script tests if 2 output files are the same, expecting
that one of those is the correct output, while the other
is the actual output.

CLI Arguments
-------------
file_name_1 : str
	The name of file 1
file_name_2 : str
	The name of file 2
data_path : str (optional)
	An alternative data path.

Output
------
This script outputs "The files are equal!" if both files
are the same. Otherwise, it outputs:

"The files aren't equal! Differences:
~~~~~~~~~~~~~~~~~~~
File 1:

{Things that file 1 contains that file 2 doesn't}.
~~~~~~~~~~~~~~~~~~~
File 2:

{Things that file 2 contains that file 1 doesn't}."
"""

from sys import argv
from os.path import isfile, isdir

data_path = "../data/"

def compare(file_name_1, file_name_2, dp=data_path):
	with open(dp+file_name_1) as f1:
		with open(dp+file_name_2) as f2:
			f1s, f2s = f1.readlines(), f2.readlines()
			dif1 = set(f1s).difference(f2s)
			dif2 = set(f2s).difference(f1s)
	return dif1, dif2

def check(arr):
	if(len(arr) != 2 and len(arr) != 3):
		print("Error: Bad arguments")
		print("The correct CLI call is:")
		print("$ verificar_saida.py filename1 filename2 alternative_data_path (third argument is optional)")
		exit(1)
	elif(len(arr)==3):
		if(not isdir(arr[2])):
			print("Error: Invalid data path")
			print("Not found directory \'"+arr[2]+"\'")
			exit(1)
		global data_path
		data_path = arr[2]
	if(not isfile(data_path + arr[0])):
		print("Unrecognized file \'"+arr[0]+"\'")
		exit(1)	
	if(not isfile(data_path + arr[1])):
		print("Unrecognized file \'"+arr[1]+"\'")
		exit(1)

def main():
	# dif1, dif2 = compare()
	check(argv[1:])
	fn1, fn2 = argv[1], argv[2]
	dif1, dif2 = compare(fn1, fn2)
	if(len(dif1)==0 and len(dif2)==0):
		print("The files are equal!")
	else:
		print("The files aren't equal! Differences:")
		print("~~~~~~~~~~~~~~~~~~~")
		print(fn1 + ':\n')
		for dif in dif1:
			print(dif)
		print("~~~~~~~~~~~~~~~~~~~")
		print(fn2 + ':\n')
		for dif in dif2:
			print(dif)
		print("~~~~~~~~~~~~~~~~~~~")

if __name__ == "__main__":
	main()
