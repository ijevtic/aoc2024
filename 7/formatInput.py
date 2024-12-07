# first I removed ':' symbols from the input file

for i in range(850):
  line = input()
  size = line.split()
  
  print(str(len(size)) + " " + line)