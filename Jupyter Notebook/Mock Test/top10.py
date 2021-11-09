import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_csv("Foreign_Exchange_Rates.csv")
dft = df.T
to_drp = list(dft.columns)
to_drp.pop()
dft.drop(to_drp , inplace= True ,axis=1)
dft.drop(["Unnamed: 0","Time Serie"], inplace= True ,axis=0)
dft.rename(columns = {5216: 'Updated'}, inplace = True)
dft['Updated'] = float(str(dft['Updated']))
dft = dft.sort_values("Updated")
print(dft)
dft.to_csv("checking.csv",index=True)
#print(list(dft.columns))