idx =0
sci = []
soc = []
while idx <4:
  sci.append(input())
  idx+=1

while idx < 6:
  soc.append(input())
  idx+=1
  
print sum(sci) - min(sci) + sum(soc) - min(soc)
