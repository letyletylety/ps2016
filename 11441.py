n = input()
arr = raw_input().split()
srr = [0] * (len(arr)+1)

for i in xrange(len(arr)):
  srr[i+1] = srr[i] + int(arr[i])
#  print srr[i+1]
m =  input()
while m>0:
  m-=1
  (i,j) = raw_input().split()
  (i,j) = int(i),int(j)
  print srr[j] - srr[i-1]
