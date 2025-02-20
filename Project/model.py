import pandas as pd
from sklearn.linear_model import LinearRegression
import pickle

def train_model():
    data = pd.read_csv('energy_data.csv')  # Replace with your data source
    X = data[['energyConsumed']]
    y = data['bill']
    
    model = LinearRegression()
    model.fit(X, y)
    
    with open('model.pkl', 'wb') as file:
        pickle.dump(model, file)

def predict_bill(energy_consumed):
    with open('model.pkl', 'rb') as file:
        model = pickle.load(file)
    return model.predict([[energy_consumed]])[0]

if __name__ == '__main__':
    train_model()
