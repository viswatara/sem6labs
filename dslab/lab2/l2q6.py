import pandas as pd
df=pd.DataFrame({'Name':['Tara','Laxya'],'Quiz_1 /10':[10,8],'In-Sem_1/15':[12,15],'Quiz_2 /10':[7,7],'In-Sem_2 /15':[13,14]})
df['Total'] = df.sum(numeric_only=True,axis=1)
df.loc['Mean'] = df.mean(numeric_only=True,axis=0)
print(df)