#Program By Roger Blake to read a csv file then calculate mean, max, and min of the colorado river measurements.

import csv

with open("primary-time-series.csv", newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')

    count = 0
    times = 0
    lowestwater = 10.00
    highestwater = 0
    for row in spamreader:
        
        if count >0:
            
            information = row[1].split(',') #04:00:00+00:00,3.02,ft,Approved,,2025-12-17 splits data into this for us
            wateramount = float(information[1]) #grabs the row 1 of the varible above which is in this case 3.02
            times+=wateramount

            if wateramount < lowestwater:
               lowestwater = wateramount
            if wateramount > highestwater:
               highestwater = wateramount
            
        count += 1 

    average = times/(count - 1)
    print("%.4f"%average,"ft", "%.4f"%lowestwater,"ft", "%.4f"%highestwater,"ft")
            
            