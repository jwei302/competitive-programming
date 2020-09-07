"""
ID: jeffrey88
PROG: friday
LANG: PYTHON3
"""

f = open('friday.in', 'r')
w = open('friday.out', 'w')

#Checks what day of the week is the 13th of each month
def year(occured, date, x):

  #The days of the year. :P
  months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

  #Checks to see if its a leap year
  if date % 400 == 0:
    months[1] = 29
  elif date % 100 != 0 and (date % 100) % 4 == 0:
    months[1] = 29

  #What actually calculates the 13th of each month
  week = x
  for time in range(12):
    week = (week + 13) % 7
    occured[week] += 1
    week = (week + (months[time]-13)) % 7
  return occured, week

#Determines how many years need to be measured
years = int(f.read())

#The dates of the week that it occurs
occur = [0,0,0,0,0,0,0]

#Starts on Monday, and since code counts with 0.. 1.. 2.. Monday is equivilent to 1
start = 1

#Counts the dates 1 year at a time
for time in range(1900, years+ 1900, 1):
  occur, start = year(occur, time, start)

#Once it is finished, the code gets outputed here
for steps in range(6):
  w.write(str(occur[steps]) + " ")
w.write(str(occur[6]) + "\n")
