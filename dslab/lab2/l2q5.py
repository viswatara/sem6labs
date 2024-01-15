import pandas as pd
df1=pd.DataFrame({'Name':("Tara","Laxya")})
df2=pd.DataFrame({'Math':(100,100),'Physics':(88,81.5),'Chemistry':(98,97),
	'Biology':(100,99)})
frames=[df1,df2]
df_new=pd.concat(frames,axis=1)
df_new['Total'] = df_new.sum(numeric_only=True,axis=1)
print(df_new)