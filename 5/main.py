import math

n = 1176
m = 209
rules = dict()
forbidden = dict()

# flag if this is 5a or 5b
b_flag = False

for i in range(n):
  line = input()
  nums = line.split("|")
  nums = [int(nums[0]),int(nums[1])]
  rules[(nums[0], nums[1])] = True
  if nums[0] not in forbidden:
    forbidden[nums[0]] = [nums[1]]
  else:
    forbidden[nums[0]].append(nums[1])

input()
res = 0
for i in range(m):
  line = input()
  input_nums = line.split(",")
  nums = []
  for j in range(len(input_nums)):
    nums.append(int(input_nums[j]))
  seen = dict()
  bad = False
  refresh = False
  j = 0
  while j < len(input_nums):
    num = nums[j]
    seen[num] = j
    if num not in forbidden:
      j += 1
      continue
    for f in forbidden[num]:
      if f in seen:
        bad = True
        refresh = True
        nums[seen[f]] = nums[j]
        nums[j] = f
        break
    
    if refresh:
      seen.clear()
      j = -1
      refresh = False
    
    j += 1
  
  if b_flag and bad:
    res += int(nums[math.floor(len(nums)/2)])
  elif b_flag and not bad:
    res += int(nums[math.floor(len(nums)/2)])

print(res)