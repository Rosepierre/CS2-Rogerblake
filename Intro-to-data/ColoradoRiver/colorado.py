#Program By Roger Blake to read a csv file then calculate mean, max, and min of the colorado river measurements.

import csv

with open("primary-time-series.csv", as newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
    print(spamreader)