li = [["Top Gun","Risky Business","Minority Report"],["Titanic","The Revenant","Inception"],["Training Day","Man on Fire","Flight"]]
import csv
with open("file.csv","w") as f:
    write = csv.writer(f,delimiter=",")
    for i in li:
        write.writerow(i)
print("DOne")