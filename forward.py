from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
import pandas as pd
import numpy as np
import copy

def fit_reg(X,y):
    reg = LinearRegression().fit(X, y)
    return {'r2_score':reg.score(X,y),'coef': reg.coef_,'intercept': reg.intercept_,'mse': mean_squared_error(y,reg.predict(X))}

#d = {'Town1': [34,86,56,23,12,22], 'Town2': [32,91,78,92,99,102], 'Town3': [53,24,90,45,23,11],'Town4': [5,10,23,44,34,23], 'Town5':[10,12,23,55,64,45],'Town6':[29,50,45,67,56,65],'NYC':[40,45,23,34,35,43]}

d = {'Town3':[67,31,63,88,63],'NYC':[69,48,81,77,66],'Town1':[60,61,61,71,61],'Town4':[63,62,73,67,77],'Town5':[65,46,49,64,43],'Town6':[69,46,100,90,82],'Town2':[95,102,94,95,81]}

data = pd.DataFrame(data = d)

#regression
y = np.array(d['NYC'])
data.drop(['NYC'],axis = 1,inplace = True)
town = list(data.columns)

f = []
#forward_stepwise
for i in range(0,5):
    temp_res = pd.Series()
    for name in town:
        f.append(name)
        X = np.array(pd.DataFrame(data[f].values))
        fit_res = fit_reg(X,y)
        f.remove(name)
        temp_res[name] = fit_res['r2_score']
    new_feature = temp_res.idxmax()
    f.append(new_feature)
    town.remove(new_feature)
print(f)

