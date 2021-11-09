import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_csv("district_wise.csv")
df = df.replace("Total District(s)",np.nan)
df = df.replace("TOTAL",np.nan)
df = df.replace("ZZ TOTAL",np.nan)
df = df.replace("DELHI UT TOTAL",np.nan)
df = df.replace("A&N ISLANDS","A & N ISLANDS")
df = df.replace("D & N HAVELI","D&N HAVELI")
df["STATE/UT"] = df["STATE/UT"].str.upper()
df = df.dropna()
df["sum"] = df.iloc[:,3:].sum(axis = 1)
df["Danger index"] = (df['sum']/max(df['sum']))*100
df["Safety index"] = ((df['Danger index']-max(df['Danger index']))*(-1))
#df.sort_values('sum',ascending=False).to_csv("No_total.csv",index=False)
#df.sort_values('STATE/UT',ascending=False).to_csv("No_total.csv",index=False)
#df.pivot(index='STATE/UT',columns='DISTRICT',values='index')
plt.xticks(rotation=90)
plt.bar(df.sort_values('sum',ascending=False)["STATE/UT"],df.sort_values('sum',ascending=False)["Danger index"],width=0.5,align="center")
plt.savefig("Bar.jpg")