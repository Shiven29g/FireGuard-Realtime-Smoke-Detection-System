import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report, confusion_matrix, roc_auc_score
import joblib

# Step 1: Data Collection
data = pd.read_csv('smoke_detection_iot')  # Replace with your data file
print("Data Loaded:")
print(data.head())

# Step 2: Data Preprocessing
# Handling missing values
data.fillna(data.mean(), inplace=True)

# Features and target variable
features = data[['Temperature[C]', 'Humidity[%]', 'TVOC[ppb]', 'eCO2[ppm]', 
                 'Raw H2', 'Raw Ethanol', 'Pressure[hPa]', 
                 'PM1.0', 'PM2.5', 'NC0.5', 'NC1.0', 'NC2.5', 'CNT']]
labels = data['Fire Alarm']  # Your target variable

# Split the dataset
X_train, X_test, y_train, y_test = train_test_split(features, labels, test_size=0.3, random_state=42)

# Standardization
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# Step 3: Model Training
rf_model = RandomForestClassifier(random_state=42)
param_grid = {
    'n_estimators': [50, 100, 200],
    'max_depth': [None, 10, 20, 30],
    'min_samples_split': [2, 5, 10]
}

grid_search = GridSearchCV(estimator=rf_model, param_grid=param_grid, cv=5, scoring='accuracy')
grid_search.fit(X_train, y_train)

# Best model
best_rf_model = grid_search.best_estimator_
print("Best Hyperparameters: ", grid_search.best_params_)

# Step 4: Evaluation
y_pred = best_rf_model.predict(X_test)
print("Confusion Matrix:\n", confusion_matrix(y_test, y_pred))
print("Classification Report:\n", classification_report(y_test, y_pred))
print("ROC AUC Score:", roc_auc_score(y_test, best_rf_model.predict_proba(X_test)[:, 1]))  # For binary classification

# Step 5: Save the Model
joblib.dump(best_rf_model, 'fire_detection_model.pkl')
joblib.dump(scaler, 'scaler.pkl')

# Step 6: Real-Time Detection Function
def classify_fire(new_data):
    scaled_data = scaler.transform(np.array(new_data).reshape(1, -1))
    prediction = best_rf_model.predict(scaled_data)
    return prediction[0]

# Example of real-time data input
# Note: In a real application, replace the following with actual sensor data retrieval
while True:
    # Simulated real-time sensor data (replace with actual sensor readings)
    new_sensor_data = [25.0, 60.0, 200.0, 400.0, 50, 30, 1013, 10, 15, 5, 3, 2, 100]  # Example data
    fire_alarm_status = classify_fire(new_sensor_data)
    print("Fire Alarm Status:", fire_alarm_status)
    # Include a sleep or delay here if running in a continuous loop
    break  # Remove this break for continuous running
