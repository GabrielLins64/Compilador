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
	...
"""

from sys import argv
from os.path import isfile, isdir

data_path = "../data/"

def _readlines(f):
	x = []
	for i, l in enumerate(f.readlines()):
		x.append(str(i+1) + ": " + l)
	return x

def difference(arr1, arr2):
	diffs = []
	size = len(arr1) if len(arr1) < len(arr2) else len(arr2)
	for i in range(size):
		if(arr1[i] != arr2[i]):
			diffs.append((arr1[i], arr2[i]))
	return diffs

def compare(file_name_1, file_name_2, dp):
	with open(dp+file_name_1) as f1:
		with open(dp+file_name_2) as f2:
			f1s = _readlines(f1)
			f2s = _readlines(f2)
			diffs = difference(f1s, f2s)
	return diffs

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
	check(argv[1:])
	fn1, fn2 = argv[1], argv[2]
	diffs = compare(fn1, fn2, data_path)
	if(len(diffs)==0):
		print("The files are equal!")
	else:
		print("The files aren't equal! Differences:")
		print("Legend: ("+fn1+", "+fn2+")")
		for i in diffs:
			print(i)

if __name__ == "__main__":
	main()
