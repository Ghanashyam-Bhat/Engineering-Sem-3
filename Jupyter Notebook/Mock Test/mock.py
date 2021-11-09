import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
#loc = input("Enter location: ").upper()
year = list(input("Enter year range: ").split())
df = pd.read_csv("Foreign_Exchange_Rates.csv")
df.drop([df.columns[0]],inplace= True ,axis=1)
for k in list(df.columns)[1:] :
    df = pd.read_csv("Foreign_Exchange_Rates.csv")
    df = df.replace("ND",np.nan)
    df = df.dropna()
    df.drop([df.columns[0]],inplace= True ,axis=1)
    loc = k
    #df = df[int(str(df["Time Serie"])[:4])>=int(year[0]) and int(str(df["Time Serie"])[:4])<=int(year[1])]
    cols = df.columns
    cols = list(filter(lambda x:x[:len(loc)]==loc,cols))
    df["year"] = df["Time Serie"]
    df["month"] = df["Time Serie"]

    x = 0
    for i in df["Time Serie"]:
        df["year"][x] = i[:4]
        df["month"][x] = i[:7]
        x+=1

    #file = df[cols[0]].groupby(df['month'])
    #print(file.mean())
    #plt.xticks([])
    plt.title(k)
    plt.xlabel("Month-Year")
    plt.ylabel("Currency of the country/ US $")
    plt.yticks([])
    plt.xticks(rotation=90)
    df = df[df["year"]>=year[0]] 
    df = df[df["year"]<=year[1]] 
    x = 0


    """
    df["decrease"] =df[cols[0]]
    for i in df[cols[0]]:
        df["decrease"][x] = (1/float(i))*100
        print(str((1/float(i))*100))
        x+=1"""
        
    plt.bar(df["month"],df[cols[0]])
    plt.savefig(f"{k[:4]}.jpg")
    #plt.show()
    #df.to_csv("checking.csv",index=False)
    
