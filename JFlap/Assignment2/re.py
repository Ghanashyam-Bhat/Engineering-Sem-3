import re
txt = "The conference is from 09-10-2021 to 16-10-2021, and aliens will arrive on 32-5-2021"
print("Text\n"+txt)
date = "(((([1-2][0-9]|0[1-9]|3[0-1])-(0[13578]|1[02]))|(([1-2][0-9]|0[1-9]|30)-(0[469]|11))|(([1-2][0-9]|0[1-8])-(02)))-2021)"
cmp = re.compile(date)
x = re.findall(cmp,txt)
print("The valid dates mentioned in the text are:")
for i in range(len(x)):
    print(x[i][0])
    sp = re.search(x[i][0],txt)
    span = sp.span()
    print("The span of the above date is:",span)
    txt = re.sub(x[i][0],"{date}",txt,1)
print("All the valid dates are replaced with {date} in the text")
print("Text\n"+txt)
