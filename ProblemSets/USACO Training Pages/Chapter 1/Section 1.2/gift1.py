"""
ID: jeffrey88
LANG: PYTHON3
PROG: gift1
"""

f = open('gift1.in', 'r')
w = open('gift1.out', 'w')
input = f.read()

output = ""
#Counting amount of people
input = input.split("\n")
people = []
for gifts in range(int(input[0])):
  people.append([input[gifts + 1], 0])

#Removes the now unneccessary Text
del input[0:int(input[0])+1]
del input[-1]

#Actually calculates the cost
for peeps in range(int(len(people))):
  #How much money the person will throw away
  giver = input[0]
  paid = input[1].split(" ")
  money = int(paid[0])
  shared = int(paid[1])
  #People getting that guy's money
  receipients = input[2:2 + shared]
  #Removing the now unneccessary Text
  del input[0:2 + shared]
  #Calculating the gift cost
  if money > 0:
    kept = money % shared
    given = money // shared
  else:
    kept = 0
    given = 0
  #Distributing the monies
  for gifts in range(int(len(people))):
    if people[gifts][0] == giver:
      people[gifts][1] -= (money - kept)
    if people[gifts][0] in receipients:
      people[gifts][1] += given

#Outputting the data
for data in range(int(len(people))):
  output += people[data][0] + " " + str(people[data][1]) + "\n"

w.write(output)
