import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
no = [100,90,100,115,88,109,157]
days = ["SUN","MON","TUE","WED","THU","FRI","SAT"]
data = list(zip(days,no))
df = pd.DataFrame(data,columns=["Days","Number of Patients"])
plt.clf()
plt.xlabel("Days")
plt.ylabel("Number of Patients")
plt.title("Line Graph")
plt.plot(df["Days"],df["Number of Patients"])
plt.savefig("Line_Graph.jpg")
plt.show()
