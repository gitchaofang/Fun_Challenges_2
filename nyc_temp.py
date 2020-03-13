from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
import pandas as pd
import numpy as np
#'r2_score','coef','intercept', 'mse'
def fit_reg(X,y):
    reg = LinearRegression().fit(X, y)
 #   r2 = mean_squared_error(y,reg.predict(X))
    return {'r2_score':reg.score(X,y),'coef': reg.coef_,'intercept': reg.intercept_,'mse': mean_squared_error(y,reg.predict(X))}

d = {'Town1': [34,86,56,23,12,22], 'Town2': [32,91,78,92,99,102], 'Town3': [53,24,90,45,23,11],'Town4': [5,10,23,44,34,23], 'Town5':[10,12,23,55,64,45],'Town6':[29,50,45,67,56,65],'NYC':[40,45,23,34,35,43]}
data = pd.DataFrame(data = d)
res = ""
std = data.std(axis = 0)
res += std.idxmax()
md = data[(data['Town2']>=90) & (data['Town2']<=100)].median()['NYC']
res += ',' + str(int(md+0.5))

#regression
y = np.array(d['NYC'])
data.drop(['NYC'],axis = 1,inplace = True)
town = data.columns

#single vaviable
temp_res = pd.Series()
coeff_tot = 0.0
for name in town:
    X = np.array(pd.DataFrame(data[name].values))
    fit_res = fit_reg(X,y)
    temp_res[name] = fit_res['mse']
    for d in fit_res['coef']:
        coeff_tot += abs(d)
res += ',' + str(int(coeff_tot+0.5)) + ',' + temp_res.idxmin()

#two variables
n = len(town)
temp_res = pd.Series()
for i in range(0,n):
    for j in range(i+1,n):
        X = np.array(pd.DataFrame(data[[town[i],town[j]]].values))
        fit_res = fit_reg(X,y)
        temp_res[town[i]+','+town[j]] = fit_res['mse']
res += ',' + temp_res.idxmin()

print(res)
