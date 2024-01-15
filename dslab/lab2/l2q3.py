d={'Name':('Tara','Laxya'),'Height':(5.8,5.9),'Qualification':('Btech','Btech')}
import pandas as pd
df1=pd.DataFrame(d)


addr=['h1','h2']
df1['Address']=addr
print(df1)